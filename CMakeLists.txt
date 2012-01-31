project("libSVM")
cmake_minimum_required(VERSION 2.8)

# libsvm version settings
set(LIBSVM_MAJOR_VERSION "3")
set(LIBSVM_MINOR_VERSION "11")

## all these classes will be linked into a library
set(svm_sources
	source/svm.cpp
)

## add def file for windows library construction
if(MSVC)
  set(svm_sources 
    ${svm_sources} 
  	source/svm.def)
		
	# copied from old Makefilen.win
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nologo -I. -D __WIN32__ -D _CRT_SECURE_NO_DEPRECATE")
endif(MSVC)

# set pathes
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

# in case of windows we put everything in the same directory so it works
# out of the box, for linux/mac we do it the classical unix way bin/lib/..
if(MSVC)
	set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
else()
	set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

#################### svm library #####################

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

################## svm executables ###################

## list all your executables here (a corresponding .c file should exist)
set(svm_executables
	svm-predict
	svm-train
	svm-scale
)

foreach(i ${svm_executables})
  add_executable(${i} apps/${i}.c)
  ## link executables against OpenMS
  target_link_libraries(${i} libsvm)
endforeach(i)

################## svm toy examples ##################

if(SVM_TOY_QT)
  add_subdirectory(svm-toy/qt/)
endif(SVM_TOY_QT) 

if(SVM_TOY_GTK)
  add_subdirectory(svm-toy/gtk/)
endif(SVM_TOY_GTK)

if(MSVC)
	add_subdirectory(svm-toy/windows)
endif(MSVC)

################### install target ###################

# install header
install(DIRECTORY include/ DESTINATION include )

# install lib and executables
install(TARGETS libsvm ${svm_executables}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)


