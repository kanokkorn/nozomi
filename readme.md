# nozomi

Demo opencv project using vcpkg and cmake for cross-platform compile

## Prerequisites

- cmake 3.10

- git

- gcc or mvsc

- vcpkg

## Windows

1. Install vcpkg ([guide](https://github.com/microsoft/vcpkg#quick-start-windows))

2. Download and install opencv4:x64-windows

```cmd
./vcpkg.exe install opencv4:x64-windows
```

3. Create ```build``` folder in project and run a command or use cmake-gui

```cmd
cmake .. && cmake --build .
```

4. Build a project with Visual Studio

## Linux

1. Install vcpkg ([guide](https://github.com/microsoft/vcpkg#quick-start-unix))

2. Download and install opencv4:x64-linux

```bash
./vcpkg install opencv4:x64-linux
```

3. run a command form project folder

```bash
mkdir build && cd build && cmake .. && cmake --build .
```

### NOTE

change ```set( CMAKE_TOOLCHAIN_FILE )``` and ```set( OpenCV_DIR )``` to path where you install vcpkg for example

```bash
set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystem/vcpkg.cmake")
set(OpenCV_DIR "D:/vcpkg/installed/x64-windows/share/opencv")
```
