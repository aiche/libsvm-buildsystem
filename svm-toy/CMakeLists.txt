## LibSVM cmake build system
## svm-toy sub-folder

project (LIBSVM_svm_toy)
cmake_minimum_required (VERSION 2.8)

if(SVM_TOY_QT)
  add_subdirectory(qt)
endif(SVM_TOY_QT) 

if(SVM_TOY_GTK)
  add_subdirectory(gtk)
endif(SVM_TOY_GTK)

if(MSVC)
	add_subdirectory(windows)
endif(MSVC)
