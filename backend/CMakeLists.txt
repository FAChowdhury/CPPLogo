cmake_minimum_required(VERSION 3.10)
project(CPPLogo)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/src          # Include the src directory for header files
    ${PROJECT_SOURCE_DIR}/lib/lodepng  # Include the lib/lodepng directory for lodepng.h
)

# Add source files from the src directory
file(GLOB SOURCE_FILES "src/*.cpp")

# Include the lodepng.cc file in the list of source files
list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/lib/lodepng/lodepng.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Ensure proper C++ standard (if you're using C++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
