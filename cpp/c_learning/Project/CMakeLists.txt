cmake_minimum_required(VERSION 3.12)
project(SpeedManager)

# Add the source files to be compiled
set(SOURCES
src/speedManager.cpp
src/main.cpp
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)