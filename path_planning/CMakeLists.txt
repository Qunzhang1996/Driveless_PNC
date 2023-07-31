# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
project(path_planning)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# Add the executable target
add_executable(path_planning_executable
    src/map_generation.cpp
    src/path_planning.cpp
    src/main.cpp
)

# Link SDL2 library
target_link_libraries(path_planning_executable PRIVATE SDL2)
