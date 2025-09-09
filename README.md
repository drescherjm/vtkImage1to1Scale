# vtkImage1to1Scale

This is a small vtk example that uses vcpkg and CMake to download and build vtk and its dependencies using vcpkg in manifest mode.

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
3. Now go up 1 level in the folder tree so that the vcpkg folder is a subfolder of the current folder.
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
## Have CMake configure and generate
On Windows (with Visual Studio 2022): 
```shell
cmake -S .. -B . -DCMAKE_TOOLCHAIN_FILE="..\vcpkg\scripts\buildsystems\vcpkg.cmake" -G "Visual Studio 17 2022"
```
On Linux:
```bash
cmake -S .. -B . -DVCPKG_TARGET_TRIPLET="x64-linux-dynamic"  -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
```

After executing either of these commands vcpkg will fetch all the dependencies of vtk and build vtk as shared libraries (.so or .dll files)

## Now build the project!
```shell
cmake --build .
```
