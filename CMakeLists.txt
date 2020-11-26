cmake_minimum_required(VERSION 3.10.0)
project(nozomi VERSION 0.1.0)

# Linux config
if (UNIX)
  if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # use clang
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "gcc")
    # use gcc
    set(OpenCV_DIR "~/Documents/vcpkg/installed/x64-linux/share/opencv")
    set (CMAKE_CXX_FLAGS "--std=c++14 -Ofast -Wall")
    set(CMAKE_TOOLCHAIN_FILE "~/Documents/vcpkg/scripts/buildsystem/vcpkg.cmake")
  endif()
endif(UNIX)

# Windows config
if (WIN32)
  # change if not install in D: 
  set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystem/vcpkg.cmake")
  set(OpenCV_DIR "D:/vcpkg/installed/x64-windows/share/opencv")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # use clang / clang config
    set(CMAKE_CXX_FLAGS " -Ofast ")
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "msvc")
    # use msvc / msvc config
    set (CMAKE_CXX_FLAGS "/std:c++14")
  endif()
endif (WIN32)

find_package(OpenCV CONFIG REQUIRED)

if(OpenCV_FOUND)
  include(CTest)
  include_directories(${OpenCV_INCLUDE_DIRS})
  link_directories(${OpenCV_LIB_DIR})
  enable_testing()
  add_executable(nozomi main.cpp lib/cvui.h)
  if (UNIX)
    target_link_libraries(nozomi PRIVATE opencv_ml opencv_dnn opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs)
  endif (UNIX)
  set(CPACK_PROJECT_NAME ${PROJECT_NAME})
  set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
  include(CPack)
endif()
