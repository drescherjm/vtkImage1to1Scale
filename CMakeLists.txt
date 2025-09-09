# Specify the minimum version of CMake required to build this project. 
cmake_minimum_required(VERSION 3.20)

# Set the project name.
project(ImageViewer1to1)

# Set the C++ standard to C++11, which is sufficient for this code.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(VTK REQUIRED COMPONENTS
  CommonCore
  CommonDataModel
  FiltersSources
  RenderingCore
  RenderingOpenGL2   
  InteractionStyle
)

add_executable(ImageViewer1to1 main.cpp)
target_link_libraries(ImageViewer1to1 PRIVATE ${VTK_LIBRARIES})

vtk_module_autoinit(TARGETS ImageViewer1to1 MODULES ${VTK_LIBRARIES})