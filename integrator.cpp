#include "integrator.hpp"

State stepEuler(const State& s, const State& derivative, double dt) {
    State next;

    // Update states with derivative values
    next.pos = s.pos + derivative.pos * dt;
    next.vel = s.vel + derivative.vel * dt;
    next.q = (s.q.coeffs() + derivative.q.coeffs() * dt).normalized();
    next.omega = s.omega + derivative.omega * dt;

    return next;
}