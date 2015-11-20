#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Build common utilities
#


#  Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#--------------------------------#
#-       Common Utilities       -#
#--------------------------------#
add_library( common-utilities
             Coordinate_Utilities.cpp
             Coordinate_Utilities.hpp )


