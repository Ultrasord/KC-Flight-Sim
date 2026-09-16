#ifndef DYNAMICS_HPP
#define DYNAMICS_HPP

#include "state.hpp"
#include "vehicle_params.hpp"
#include <Eigen/Dense>

State computeDerivative(const State& s, const Eigen::Vector3d& force,
                         const Eigen::Vector3d& torque, const VehicleParams& params);

#endif