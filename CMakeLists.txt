cmake_minimum_required(VERSION 3.1.0)
project(nozomi VERSION 0.1.0)


# Linux config
if (LINUX)
  if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # use clang
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "gcc")
  set (CMAKE_CXX_FLAGS "--std=c++14 -Ofast -Wall")
    # use gcc
  endif()
endif(LINUX)

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
  set(CPACK_PROJECT_NAME ${PROJECT_NAME})
  set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
  include(CPack)
endif()