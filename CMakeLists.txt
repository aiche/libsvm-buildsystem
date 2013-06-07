## LibSVM cmake build system
## Author: Stephan Aiche <stephan.aiche@fu-berlin.de>

project(LIBSVM)
cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED BUILD_SHARED_LIBS)
    option(BUILD_SHARED_LIBS "Build LIBSVM as a shared library" ON)
endif()

# libsvm version settings
set(LIBSVM_MAJOR_VERSION "3")
set(LIBSVM_MINOR_VERSION "17")

# global definition of output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
  # copied from old Makefilen.win
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nologo -I. -D __WIN32__ -D _CRT_SECURE_NO_DEPRECATE")
endif(MSVC)

# globally define the include
include_directories(${PROJECT_SOURCE_DIR}/include)

# install header
install(DIRECTORY include/ DESTINATION include )

## add the libsvm-apps
add_subdirectory(lib)

## add the libsvm-apps
add_subdirectory(apps)

## svm toy examples
add_subdirectory(svm-toy)
