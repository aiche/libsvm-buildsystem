## LibSVM cmake build system
## svm-toy/windows sub-folder

project (LIBSVM_svm_toy_win)
cmake_minimum_required (VERSION 2.8)

set(sources
  svm-toy.cpp
)

add_executable(svm-toy WIN32 ${sources})
target_link_libraries (svm-toy libsvm)