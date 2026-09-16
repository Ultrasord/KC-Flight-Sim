#include "frames.hpp"

Eigen::Vector3d bodyToWorld(const Eigen::Quaterniond& q, const Eigen::Vector3d& v_body) {
    // rotates v_body into the world frame using q.
    return q * v_body;
}