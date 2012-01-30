project("libSVM")
cmake_minimum_required(VERSION 2.6)

# libsvm version settings
set(LIBSVM_MAJOR_VERSION "3")
set(LIBSVM_MINOR_VERSION "11")

## list all your executables here (a corresponding .c file should exist)
set(svm_executables
	svm-predict
	svm-train
	svm-scale
)

## all these classes will be linked into a library
set(svm_sources
	svm.cpp
)

## add def file for windows library construction
if(MSVC)
  set(svm_sources 
    ${svm_sources} 
    svm.def)
endif(MSVC)

# set pathes
set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

if(BUILD_STATIC)
  add_library(libsvm STATIC ${svm_sources})
else()
  add_library(libsvm SHARED ${svm_sources})
endif()

# remove default prefix of cmake, since our target is already named libsvm
set_target_properties(libsvm PROPERTIES PREFIX "")

# set version for embedding in the SO/DYLIB
set_target_properties(libsvm PROPERTIES 
  VERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}"
  SOVERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}")

foreach(i ${svm_executables})
  add_executable(${i} ${i}.c)
  ## link executables against OpenMS
  target_link_libraries(${i} libsvm)
endforeach(i)
