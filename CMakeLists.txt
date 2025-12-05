cmake_minimum_required(VERSION 3.10)
project(simulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simulation src/main.cpp src/station.cpp src/bus.cpp)

target_include_directories(simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)