cmake_minimum_required(VERSION 3.10)

project(QALS-cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Create the executable target.
add_executable(main     src/main.cpp src/lib.cpp src/npp.cpp src/tsp.cpp)

