cmake_minimum_required(VERSION 3.5)
project(AdventOfCode2024 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all problem source files
file(GLOB PROBLEM_FILES
    problems/*.cpp
)

# Create excutable with main and all problem files
add_executable(${PROJECT_NAME} 
    main.cpp 
    ${PROBLEM_FILES}
)

# Add problems directory to include path
target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/problems
)

# Copy inputs directory to build directory
file(COPY ${CMAKE_SOURCE_DIR}/inputs 
    DESTINATION ${CMAKE_BINARY_DIR}
)

# Define path to inputs directory
target_compile_definitions(${PROJECT_NAME} 
    PRIVATE 
        INPUTS_DIR="${CMAKE_BINARY_DIR}/inputs"
)