#include <AMReX_REAL.H>

#include <Derive.H>
#include <Castro.H>
#include <prob_parameters.H>
#include <prob_util.H>

using namespace amrex;


void deranalytic(const Box& bx, FArrayBox& derfab, int /*dcomp*/, int /*ncomp*/,
                 const FArrayBox& /*datfab*/, const Geometry& geomdata,
                 Real time, const int* /*bcrec*/, int /*level*/)
{

    const auto dx = geomdata.CellSizeArray();
    const auto problo = geomdata.ProbLoArray();

    const int coord_type = geomdata.Coord();

    auto const der = derfab.array();

    amrex::ParallelFor(bx,
    [=] AMREX_GPU_HOST_DEVICE (int i, int j, int k)
    {
        Real r[3] = {0.0_rt};
        r[0] = problo[0] + dx[0] * (static_cast<Real>(i) + 0.5_rt);
#if AMREX_SPACEDIM >= 2
        r[1] = problo[1] + dx[1] * (static_cast<Real>(j) + 0.5_rt);
#endif
#if AMREX_SPACEDIM == 3
        r[2] = problo[2] + dx[2] * (static_cast<Real>(k) + 0.5_rt);
#endif
        if (coord_type <= 1) {
            for (int n = 0; n < AMREX_SPACEDIM; ++n) {
                r[n] -= problem::center[n];
            }
        }

        der(i,j,k,0) = analytic(r, time, coord_type);

    });

}
