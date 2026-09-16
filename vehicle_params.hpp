#ifndef VEHICLE_PARAMS_HPP
#define VEHICLE_PARAMS_HPP

#include <Eigen/Dense>

struct VehicleParams {
    double mass;               // kg
    Eigen::Matrix3d inertia;   // full 3x3 inertia tensor, kg*m^2
                                // (set off-diagonal entries to 0 manually for now —
                                // see Day 3 notes on symmetric-vehicle simplification)
};

#endif