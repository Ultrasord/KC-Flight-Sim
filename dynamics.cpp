#include "dynamics.hpp"

State computeDerivative(const State& s, const Eigen::Vector3d& force,
                         const Eigen::Vector3d& torque, const VehicleParams& params) {
    State deriv;

    // Calculate kinematics
    deriv.pos = s.vel;
    deriv.vel = force / params.mass;

    // Calculate q_dot
    Eigen::Quaterniond omega_quat(0.0, s.omega);
    deriv.q = 0.5 * (s.q * omega_quat).coeffs();

    // TODO: Euler's rotation equation, solved for angular acceleration:
    //   omega_dot = I^-1 * (torque - omega x (I * omega))
    //
    // params.inertia is now a full Eigen::Matrix3d, so:
    //   I * omega        -> ordinary matrix-vector multiplication:
    //                       params.inertia * s.omega
    //   I^-1 * something -> params.inertia.inverse() * something
    // (a real matrix inverse this time, not element-wise reciprocal —
    // Eigen provides .inverse() directly on Matrix3d)
    //
    // Same three-step build as before: (1) I*omega, (2) the cross term
    // via .cross(), (3) combine and left-multiply by the inverse.

    deriv.omega = params.inertia.inverse() * (torque - s.omega.cross(params.inertia * s.omega));

    return deriv;
}