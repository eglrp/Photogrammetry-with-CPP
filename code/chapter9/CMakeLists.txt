#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/25/2015
#


#------------------------------------------#
#-     Construct the OSG Rendering App    -#
#------------------------------------------#
add_executable( osg-render-terrain
                osg-render-terrain.cpp )

target_link_libraries( osg-render-terrain
                       common-utilities
                       ${OPENSCENEGRAPH_LIBRARIES}
                       ${OpenCV_LIBS}
)

