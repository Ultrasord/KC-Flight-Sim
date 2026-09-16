cmake_minimum_required(VERSION 3.10)
project(SixDofSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Point at your Eigen install (no linking needed, it's header-only)
include_directories("C:/libs/eigen-3.4")

add_executable(sim
    main.cpp
    dynamics.cpp
    forces.cpp
    integrator.cpp
    frames.cpp
)