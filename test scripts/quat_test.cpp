#include<Eigen/Dense>
#include<iostream>

int main() {
    Eigen::Quaterniond q(1, 0, 0, 0);
    Eigen::Vector3d v(1, 2, 3);
    Eigen::Vector3d v_rotated = q * v;

    std::cout << v.transpose() << std::endl;
    std::cout << v_rotated.transpose() << std::endl;
}