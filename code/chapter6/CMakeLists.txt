
#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Construct Chapter 6 Samples.
#


#  Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#---------------------------------------------------#
#-     Build the GeographicLib Gravimetric Demo    -#
#---------------------------------------------------#
add_executable( geographiclib-magnetic-query 
                geographiclib-magnetic-query.cpp )

target_link_libraries( geographiclib-magnetic-query
                       common-utilities
                       ${GeographicLib_LIBRARIES} )
                       

