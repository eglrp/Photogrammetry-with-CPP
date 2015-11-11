#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/9/2015
#
#    Purpose: Construct the Photogrammetry Book and all associated artifacts.
#

#--------------------------------------------------#
#-    Define the Minimum Required CMake Version   -#
#--------------------------------------------------#
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )


#---------------------------------------#
#-    Add Additional CMake Modules     -#
#---------------------------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(cmake/Modules/UseLATEX.cmake)


#------------------------------#
#-    Set the Project Name    -#
#------------------------------#
project( Photogrammetry-with-C++ )


#-----------------------------#
#-    Build Subdirectories   -#
#-----------------------------#
add_subdirectory(book)
add_subdirectory(code)

