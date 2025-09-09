# vtkImage1to1Scale

This is a small vtk example that downloads and builds vtk using vcpkg in manifest mode.

## Prerequisites:

1. A working c++ compiler

2. [CMake 3.20 or newer](https://cmake.org/download/)

3. git or github desktop or cli utility

## Initial Setup:

1. Clone vcpkg to an appropriate location on your system.
   
   ```shell
   git clone https://github.com/microsoft/vcpkg.git
   ```
2. Bootstrap vcpkg
   
   On windows:
   
   ```shell
   cd vcpkg
   ./bootstrap.bat
   ```
   
   On Linux, macOS ...
   
   ```bash
   cd vcpkg
   ./bootstrap.sh
   ```
3. Now go up 1 level in the folder tree.
   ```shell
   cd ..
   ```
## Clone this repository
```shell
git clone https://github.com/drescherjm/vtkImage1to1Scale.git
```
After cloning you should have a vcpkg folder and a vtkImage1to1Scale in the current folder.

## Create the build folder
```shell
cd vtkImage1to1Scale
mkdir build
cd build
```
