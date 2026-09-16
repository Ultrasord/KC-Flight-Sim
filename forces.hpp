#ifndef FORCES_HPP
#define FORCES_HPP

#include <Eigen/Dense>

Eigen::Vector3d gravity(double mass);
Eigen::Vector3d thrustBody(double thrust_magnitude);

#endif