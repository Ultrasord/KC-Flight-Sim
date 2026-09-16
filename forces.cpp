#include "forces.hpp"

Eigen::Vector3d gravity(double mass) {
    
    // Returns gravitational force acting on the mass in NED frame.
    // TODO: currently assumes g is constant no matter altitude.

    constexpr double g0 = 9.81;
    return Eigen::Vector3d(0.0, 0.0, mass * g0);
}

Eigen::Vector3d thrustBody(double thrust_magnitude) {
    // Returns thrust force in body frame.
    return Eigen::Vector3d(0.0, 0.0, -thrust_magnitude);
}