#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/24/2015
#
#    Purpose: Construct Chapter 4 Samples.
#


#  Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#--------------------------------------------#
#-     Build the GDAL Load Image Example    -#
#--------------------------------------------#
add_executable( gdal-load-image-simple
                gdal-load-image.cpp )

target_link_libraries( gdal-load-image-simple
                       common-utilities
                       ${GDAL_LIBRARIES} )


