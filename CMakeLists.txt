## LibSVM cmake build system
## Author: Stephan Aiche <stephan.aiche@fu-berlin.de>

project(LIBSVM)
cmake_minimum_required(VERSION 2.8)

# libsvm version settings
set(LIBSVM_MAJOR_VERSION "3")
set(LIBSVM_MINOR_VERSION "17")

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
