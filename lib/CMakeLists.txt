## LibSVM cmake build system
## libs sub-folder

project(LIBSVM_lib)
cmake_minimum_required(VERSION 2.8)

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
if (BUILD_SHARED_LIBS)
	add_library(libsvm SHARED ${svm_sources})
	# set version for embedding in the SO/DYLIB
	set_target_properties(libsvm PROPERTIES 
		VERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}"
		SOVERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}")
else()
	add_library(libsvm STATIC ${svm_sources})
endif (BUILD_SHARED_LIBS)

# remove default prefix of cmake, since our target is already named libsvm
set_target_properties(libsvm PROPERTIES PREFIX "")
  
# install lib
install(TARGETS libsvm
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

# if MSVC we want the dll to be also in the lib-folder
# for linking against libsvm
if (MSVC AND BUILD_SHARED_LIBS)
	install(TARGETS libsvm DESTINATION lib	)
endif (MSVC AND BUILD_SHARED_LIBS)
