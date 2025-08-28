# Specify the minimum version of CMake required to build this project.
cmake_minimum_required(VERSION 3.20)

# Set the project name.
project(ImageViewer1to1)

# Set the C++ standard to C++11, which is sufficient for this code.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the VTK package. CMake will search for a VTK installation.
# The REQUIRED keyword will cause CMake to fail if VTK is not found.
find_package(VTK REQUIRED)

# This line includes the VTK settings, which configures include directories,
# compiler definitions, and other necessary build settings.
include(${VTK_USE_FILE})

# Add the executable target.
# It's named "ImageViewer1to1" and is built from "main.cpp".
# Replace "main.cpp" if your source file has a different name.
add_executable(ImageViewer1to1 main.cpp)

# Link the executable against the necessary VTK libraries.
# The ${VTK_LIBRARIES} variable is populated by the find_package command.
target_link_libraries(ImageViewer1to1 PRIVATE ${VTK_LIBRARIES})