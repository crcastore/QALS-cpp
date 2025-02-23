cmake_minimum_required(VERSION 3.10)

# Set the project name and specify C++ as the language.
project(QALS-cpp CXX)

# Use C++2a (i.e. C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ensure Release builds get -O3 (CMake usually adds optimization flags,
# but we explicitly add -O3 for consistency with your script)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Enable OpenMP support
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  message(STATUS "Found OpenMP: ${OpenMP_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


# Create the executable target.
add_executable(main     src/main.cpp src/lib.cpp src/npp.cpp src/tsp.cpp)

# Set the output directory to "bin" inside the build folder.
set_target_properties(main PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# (Optional) Add a custom target to run the executable.
add_custom_target(run
  COMMAND ${CMAKE_BINARY_DIR}/bin/main
  DEPENDS main
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
