set(sources
  svm-toy.cpp
)

add_executable(svm-toy WIN32 ${sources})
target_link_libraries (svm-toy libsvm)