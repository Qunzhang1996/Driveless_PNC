cmake_minimum_required(VERSION 3.1)
project(KalmanFilterExample)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Eigen library (change the path accordingly if Eigen is installed in a different location)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# Add executable for the Kalman filter example
add_executable(kalman_filter_example
    src/main.cpp
    src/kalman_filter.cpp
)

# Include the "include" directory for the Kalman filter header
target_include_directories(kalman_filter_example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Link the necessary libraries (matplotlib-cpp and Python3)
find_package(Python3 COMPONENTS Development NumPy)
target_link_libraries(kalman_filter_example PRIVATE Python3::Python Python3::NumPy)

# Enable C++11 features
target_compile_features(kalman_filter_example PRIVATE cxx_std_11)
