## LibSVM cmake build system
## svm-toy/qt sub-folder

project (LIBSVM_svm_toy_qt)
cmake_minimum_required (VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui) # find and setup Qt4 for this project
include(${QT_USE_FILE}) 

set(sources 
  svm-toy.cpp)

# tell cmake to create .moc files for all files in the variable qtproject_SRCS that require such a file.
# note: this assumes that you use #include "header.moc" in your files
qt4_automoc(${sources})

# hint to find the moc-ed files
include_directories(${PROJECT_BINARY_DIR})

add_executable(svm-toy ${sources} ${svm-toy-mocs})
target_link_libraries(svm-toy libsvm ${QT_LIBRARIES})