// g++ testsetup.cpp -I "C:\libs\eigen-5.0\" -o testsetup.exe
#include <Eigen/Dense>
#include <iostream>

int main() {

    // Create an identity quaternion and a constant angular velocity
    Eigen::Quaterniond q(1, 0, 0, 0);
    Eigen::Quaterniond omega(0, 0, 0, 0.5);

    // Initialize qdot
    Eigen::Quaterniond q_dot;
    
    // Time parameters
    double t = 0;
    double dt = 0.001;
    double t_final = 15.0;
    int steps_per_second = 1 / dt;

    // Find number of steps
    int N = (t_final - t)/dt;
    std::cout << "TOTAL STEPS:" << N << std::endl;

    for (int i = 0; i < N; ++i) {
        t += dt;

        // Calculate qdot (I borrowed this code from gemini let me know if this is bad practice.)
        q_dot.coeffs() = 0.5 * (q * omega).coeffs();

        q = q.coeffs() + (q_dot.coeffs() * dt);
        q = q.normalized();

        // Print updates every second
        if ( (i + 1) % steps_per_second == 0) {     // i + 1 because i starts at 0 and we want to print exactly at each second.
            Eigen::Vector3d euler = q.matrix().canonicalEulerAngles(2, 1, 0); // ZYX order

            // std::cout << "Euler angles (degrees):\n" << euler * 180 / M_PI << std::endl;
            std::cout << "Time: " << t << " seconds\n";
            std::cout << "Step: " << i + 1 << "\n"; // i + 1 because i starts at 0
            std::cout << "Real Angle in radians: " << fmod(0.5*t, 2*M_PI) << "\n";
            std::cout << "Euler angle in radians:\n" << euler << "\n\n";

            // std::cout << "Quaternion Normalized: " << q << std::endl;
            // std::cout << "Quaternion Magnituyde: " << q.norm() << "\n" << std::endl;
        }
    }

}