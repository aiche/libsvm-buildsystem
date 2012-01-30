include(UsePkgConfig)
find_package(GTK)

if (GTK_FOUND)
  message(STATUS "Found GTK")
else()
  message(STATUS "Cannot find GTK")
endif (GTK_FOUND)