cmake_minimum_required(VERSION 3.22) # Specify CMake version.
project(Final-Project) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
add_compile_definitions(_USE_MATH_DEFINES)

# set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wpedantic -Wextra")
message(STATUS "CMakeLists.txt is at ${PROJECT_SOURCE_DIR}") # To print something.

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
)

# Create a binary file.

# The first argument is the name of the binary file.
#sdf
# It can be anything. In this case, it is set to be the project name.
# The other arguments are source files.
# Header files are not needed in add_executable(), assuming they are properly included.
add_executable(${CMAKE_PROJECT_NAME} ${all_SRCS})