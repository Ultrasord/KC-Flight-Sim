#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include "state.hpp"

State stepEuler(const State& s, const State& derivative, double dt);

#endif