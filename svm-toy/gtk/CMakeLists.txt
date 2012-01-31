find_package(GTK2)

if (GTK2_FOUND)

  set(sources
    main.c
    interface.c
    callbacks.cpp
  )

  set_source_files_properties(main.c PROPERTIES LANGUAGE C )
  set_source_files_properties(interface.c PROPERTIES LANGUAGE C )

  include_directories(${GTK2_INCLUDE_DIRS})
  # link_directories (${GTK2_LIBRARIES})
  
  add_executable(svm-toy ${sources})
  
  add_definitions (${GTK2_CFLAGS_OTHER})
  target_link_libraries (svm-toy libsvm ${GTK2_LIBRARIES})

else()
  message(STATUS "Cannot find GTK")
endif (GTK2_FOUND)