#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Construct Chapter 3 Samples.
#


#  Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#---------------------------------------------------#
#-     Build the GDAL Geographic to UTM Example    -#
#---------------------------------------------------#
add_executable( gdal-geographic-to-utm
                gdal-geographic-to-utm.cpp )

target_link_libraries( gdal-geographic-to-utm
                       common-utilities
                       ${GDAL_LIBRARIES} )



#-------------------------------------------#
#-      Build the MGRS to UTM Example      -#
#-------------------------------------------#
add_executable( mgrs-to-utm
                mgrs_to_utm.cpp )

target_link_libraries( mgrs-to-utm
                       common-utilities
                       ${GeographicLib_LIBRARIES})


