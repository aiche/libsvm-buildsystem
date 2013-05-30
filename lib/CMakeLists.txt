## LibSVM cmake build system
## libs sub-folder

project(LIBSVM_lib)
cmake_minimum_required(VERSION 2.8)

# in case of windows we put everything in the same directory so it works
# out of the box, for linux/mac we do it the classical unix way bin/lib/..
if(MSVC)
	set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin )
else()
	set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib )
endif()

## all these classes will be linked into a library
set(svm_sources
	../source/svm.cpp
)

## add def file for windows library construction
if(MSVC)
  set(svm_sources ${svm_sources}  ../source/svm.def)
endif(MSVC)

# create debug libs with d suffix
set(CMAKE_DEBUG_POSTFIX d)

## svm library
add_library(libsvm SHARED ${svm_sources})
add_library(libsvm_static STATIC ${svm_sources})
set_target_properties(libsvm_static PROPERTIES OUTPUT_NAME libsvm)

# remove default prefix of cmake, since our target is already named libsvm
set_target_properties(libsvm PROPERTIES PREFIX "")
set_target_properties(libsvm_static PROPERTIES PREFIX "")

# set version for embedding in the SO/DYLIB
set_target_properties(libsvm PROPERTIES 
  VERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}"
  SOVERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}")
  
# install lib
install(TARGETS libsvm libsvm_static
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
