// Comment Only File

/*
    // Test bodyToWorld
    double angle = 90.0 * M_PI/180.0;
    Eigen::Quaterniond q_90i(std::cos(angle/2.0), 0.0, 0.0, std::sin(angle/2.0));
    Eigen::Vector3d v_body(100, 0, 0);

    std::cout << "q representing a 90 deg yaw: " << q_90i << std::endl;
    std::cout << "          body frame vector: " << v_body.transpose() << std::endl;
    std::cout << "           bodyToWorld call: " << bodyToWorld(q_90i, v_body).transpose() << std::endl;
*/