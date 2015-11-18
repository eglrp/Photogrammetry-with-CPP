#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Construct Chapter 3 Samples.
#


#---------------------------------------------------#
#-     Build the GDAL Geographic to UTM Example    -#
#---------------------------------------------------#
add_executable( gdal-geographic-to-utm
                gdal-geographic-to-utm.cpp )

target_link_libraries( gdal-geographic-to-utm
                       common-utilities
                       ${GDAL_LIBRARIES} )


