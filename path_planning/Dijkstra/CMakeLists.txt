cmake_minimum_required(VERSION 3.0)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 11)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include directories for the project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the source files
set(SOURCES
    src/main.cpp
    src/map_generation.cpp
    src/path_planning.cpp
)

# Create the executable target
add_executable(Dijkstra ${SOURCES})

# Link SDL2 library
target_link_libraries(Dijkstra ${SDL2_LIBRARIES})

