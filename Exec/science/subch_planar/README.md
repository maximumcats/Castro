# subch_planar

This setup studies the behavior of the initial detonation of a double
detonation Type Ia supernova at the white dwarf and accretion layer
interface and the effect of prohibiting burning in detected shock
zones. It takes a 1-d initial model representing a sub-Chandra WD and
a surface He layer and initializes a small perturbation in the He
layer.

Initial models for this setup can be created via
https://github.com/AMReX-Astro/initial_models in the `toy_atm/` directory.

To disable burning in shocks:

* in the inputs file, set `castro.disable_shock_burning = 1`

* to change the detection threshold from the default 2/3, use
  `castro.shock_detection_threshold = #`, where # is the new
  desired threshold.


## Publications

This problem setup was used in:

* *Numerical Treatment of Shock-induced Nuclear Burning in Double
  Detonation Type Ia Supernovae*

  Ryan Brady & Michael Zingale, 2025, Research Notes of the AAS, 9, 5,
  DOI: 10.3847/2515-5172/add686
