## LibSVM cmake build system
## application sub-folder

project (LIBSVM_apps)
cmake_minimum_required (VERSION 2.8)

# set pathes
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin )

## list all your executables here (a corresponding .c file should exist)
set(svm_executables
	svm-predict
	svm-train
	svm-scale
)

foreach(i ${svm_executables})
  add_executable(${i} ${i}.c)
  target_link_libraries(${i} libsvm)
endforeach(i)

# define where to install the executables
install(TARGETS ${svm_executables}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
