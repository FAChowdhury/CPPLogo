cmake_minimum_required(VERSION 3.10)
project(CPPLogo)

# Ensure C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/src           # Include the src directory for header files
    ${PROJECT_SOURCE_DIR}/lib/lodepng   # Include the lib/lodepng directory for lodepng.h
    ${PROJECT_SOURCE_DIR}/src/utils     # Include the utils directory for header files
)

# Add source files from the src and utils directories
file(GLOB SOURCE_FILES 
    "src/*.cpp"                  # All .cpp files in src directory
    "src/utils/*.cpp"            # All .cpp files in the utils directory
)

# Include the lodepng.cc file in the list of source files
list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/lib/lodepng/lodepng.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Ensure that the correct C++ standard is being used for std::format (C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check if the compiler supports std::format (C++20)
if(NOT CMAKE_CXX_STANDARD MATCHES "20")
    message(FATAL_ERROR "C++20 is required for std::format.")
endif()

# If you're using fmt as an alternative, find and link it here (if needed):
# find_package(fmt REQUIRED)
# target_link_libraries(${PROJECT_NAME} fmt::fmt)
