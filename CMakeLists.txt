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


#---------------------------#
#-     Provide Options     -#
#---------------------------#


#---------------------------------------#
#-    Add Additional CMake Modules     -#
#---------------------------------------#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


#---------------------------------------#
#-     Configure the Latex Module      -#
#---------------------------------------#
set( LATEX_COMPILER_FLAGS ${LATEX_COMPILER_FLAGS} -shell-escape )
set( PDFLATEX_COMPILER_FLAGS ${PDFLATEX_COMPILER_FLAGS} -shell-escape )
include(cmake/Modules/UseLATEX.cmake)
message("LATEX Compiler Flags: ${LATEX_COMPILER_FLAGS}")
message("PDFLATEX Compiler Flags: ${PDFLATEX_COMPILER_FLAGS}")

#------------------------------#
#-    Set the Project Name    -#
#------------------------------#
project( Photogrammetry-with-C++ )


#-----------------------------#
#-    Build Subdirectories   -#
#-----------------------------#
add_subdirectory(book)
add_subdirectory(code)

