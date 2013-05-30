## LibSVM cmake build system
## svm-toy/gtk sub-folder

project (LIBSVM_svm_toy_gtk)
cmake_minimum_required (VERSION 2.8)

find_package(GTK2 REQUIRED)

set(sources
  main.c
  interface.c
  callbacks.cpp
)

set_source_files_properties(main.c PROPERTIES LANGUAGE C )
set_source_files_properties(interface.c PROPERTIES LANGUAGE C )

include_directories(${GTK2_INCLUDE_DIRS})
add_executable(svm-toy ${sources})

add_definitions (${GTK2_CFLAGS_OTHER})
target_link_libraries (svm-toy libsvm ${GTK2_LIBRARIES})
