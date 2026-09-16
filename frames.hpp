#ifndef FRAMES_HPP
#define FRAMES_HPP

#include <Eigen/Dense>

Eigen::Vector3d bodyToWorld(const Eigen::Quaterniond& q, const Eigen::Vector3d& v_body);

#endif