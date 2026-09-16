#ifndef STATE_HPP
#define STATE_HPP

#include <Eigen/Dense>

// A "struct" is just a way to bundle several related variables into one named thing.
// Instead of tracking position, velocity, orientation, and angular velocity as
// four separate loose variables, we carry them around together as one "State".
struct State {
    Eigen::Vector3d pos;      // position in the world frame (x, y, z), meters
    Eigen::Vector3d vel;      // velocity in the world frame (x, y, z), meters/second
    Eigen::Quaterniond q;     // orientation, body-to-world rotation
    Eigen::Vector3d omega;    // angular velocity, in the body frame, radians/second
};

#endif