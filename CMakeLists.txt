cmake_minimum_required(VERSION 3.21)
project(ITproject)

set(CMAKE_CXX_STANDARD 23)

add_executable(ITproject main.cpp Rockets.h Radar.h MissileSystem.h Target.h Vector.h Integrator.h)
