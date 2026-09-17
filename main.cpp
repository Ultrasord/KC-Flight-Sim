#include "state.hpp"
#include "forces.hpp"
#include "frames.hpp"
#include "dynamics.hpp"
#include "integrator.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    // --- Initial conditions ---
    State s;
    s.pos = Eigen::Vector3d(0.0, 0.0, 0.0);
    s.vel = Eigen::Vector3d(0.0, 0.0, 0.0);
    // s.q = Eigen::Quaterniond(std::cos(-15.0*M_PI/180.0), 0.0, std::sin(-15.0*M_PI/180.0), 0.0);
    s.q = Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0); // identity, no rotation
    s.omega = Eigen::Vector3d(0.0, 0.00, 0.0);

    VehicleParams test_drone;
    test_drone.inertia = Eigen::Matrix3d{{0.02, 0.0, 0.0}, 
                                        {0.0, 0.02, 0.0}, 
                                        {0.0, 0.0, 0.04}}; // TODO: units?
    test_drone.mass = 1.0; // kg

    
    double mass = 1.0; // kg, arbitrary for this test

    // --- Time setup ---
    double dt = 0.001;
    double t_final = 5.0;
    int N = static_cast<int>(t_final / dt);
    int steps_per_second = static_cast<int>(1.0 / dt);

    // Constant gravity
    constexpr double g0 = 9.81;

    // plot
    std::ofstream log("../sim_output.csv");
    log << "t,pos_x,pos_y,pos_z,vel_x,vel_y,vel_z,roll,pitch,yaw,omega_x,omega_y,omega_z\n";

    for (int i = 0; i < N; ++i) {
        double t = i * dt; // computed from integer index, not accumulated —
                            // same floating-point drift fix as Day 1

        double thrust_mag = mass * g0; // hover thrust: exactly cancels gravity when level

        Eigen::Vector3d F_gravity = gravity(mass);
        Eigen::Vector3d F_thrust_world = bodyToWorld(s.q, thrustBody(thrust_mag));
        Eigen::Vector3d F_total = F_gravity + F_thrust_world;
        Eigen::Vector3d T_total(0, 0.05, 0); // Nm

        State deriv = computeDerivative(s, F_total, T_total, test_drone);
        s = stepEuler(s, deriv, dt);

        // Print position, velocity, and orientation every second
        if ((i + 1) % steps_per_second == 0) {
            double t_now = (i + 1) * dt;

            Eigen::Vector3d euler_now = s.q.toRotationMatrix().canonicalEulerAngles(0, 1, 2).transpose();

            std::cout << "t = " << t_now << " s\n";
            std::cout << "  pos  = " << s.pos.x() << " " << s.pos.y() << " " << s.pos.z() << "\n";
            std::cout << "  vel  = " << s.vel.x() << " " << s.vel.y() << " " << s.vel.z() << "\n";
            std::cout << "  orientation  = " << euler_now.x() << " " << euler_now.y() << " " << euler_now.z()
                        << " (roll, pitch, yaw)\n\n";
        }

        // Add data to csv for plotting
        Eigen::Vector3d euler_log = s.q.toRotationMatrix().canonicalEulerAngles(0, 1, 2);
        log << t << "," << s.pos.x() << "," << s.pos.y() << "," << s.pos.z() << ","
            << s.vel.x() << "," << s.vel.y() << "," << s.vel.z() << ","
            << euler_log.x() << "," << euler_log.y() << "," << euler_log.z() << ","
            << s.omega.x() << "," << s.omega.y() << "," << s.omega.z() << "\n";
    }

    return 0;
}