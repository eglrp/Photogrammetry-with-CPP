#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Build the Code Samples
#


#------------------------------------#
#-     Look for GDAL Libraries      -#
#------------------------------------#
find_package( GDAL REQUIRED )
include_directories(${GDAL_INCLUDE_DIRS})


#--------------------------------------------#
#-     Look for GeographicLib Libraries     -#
#--------------------------------------------#
find_package( GeographicLib REQUIRED )


#-------------------------------#
#-     Define Common Code      -#
#-------------------------------#
add_subdirectory(common)


#------------------------------------#
#-     Build Chapter 3 Examples     -#
#------------------------------------#
add_subdirectory(chapter3)

