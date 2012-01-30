project("libSVM")
cmake_minimum_required(VERSION 2.6)

set(LIBSVM_MAJOR_VERSION "3")
set(LIBSVM_MINOR_VERSION "11")
# set(LIBSVM_MAINTENANCE_VERSION "3")

## list all your executables here (a corresponding .C file should exist, e.g. Main.C)
set(svm_executables
	svm-predict
	svm-train
	svm-scale
)

## list all classes here, which are required by your executables
## (all these classes will be linked into a library)
set(svm_sources
	svm.cpp
)

if(MSVC)
  set(svm_sources 
    ${svm_sources} 
    svm.def)
endif(MSVC)


if(BUILD_STATIC)
  add_library(libsvm STATIC ${svm_sources})
else()
  add_library(libsvm SHARED ${svm_sources})
endif()

set_target_properties(libsvm PROPERTIES 
  VERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}"
  SOVERSION "${LIBSVM_MAJOR_VERSION}.${LIBSVM_MINOR_VERSION}")

foreach(i ${svm_executables})
  add_executable(${i} ${i}.c)
  ## link executables against OpenMS
  target_link_libraries(${i} libsvm)
endforeach(i)