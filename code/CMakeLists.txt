#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/10/2015
#
#    Purpose: Build the Code Samples
#


#-    TODO  Add this to a config setting   -#
# Add MacPorts
INCLUDE_DIRECTORIES(/opt/local/include)
LINK_DIRECTORIES(/opt/local/lib)

#------------------------------------#
#-     Look for GDAL Libraries      -#
#------------------------------------#
find_package( GDAL REQUIRED )
include_directories(${GDAL_INCLUDE_DIRS})


#--------------------------------------------#
#-     Look for GeographicLib Libraries     -#
#--------------------------------------------#
find_package( GeographicLib REQUIRED )
if( GeographicLib_FOUND )
    message("GeographicLib found.")
else()
    message("GeographicLib not found.")
endif()

#---------------------------------------------#
#-     Look for OpenSceneGraph Libraries     -#
#---------------------------------------------#
find_package( OpenSceneGraph REQUIRED 
                osg osgDB osgSim osgViewer osgWidget 
                osgVolume osgText osgGA osgFX osgTerrain  
                osgUtil osgShadow osgAnimation osgParticle
                osgPresentation osgManipulator )
#osg osgDB osgSim osgUtil osgViewer osgGA osgFX osgTerrain osgText osgWidget osgVolume )
include_directories(${OPENSCENEGRAPH_INCLUDE_DIRS})

if( OPENSCENEGRAPH_FOUND )
    message("OpenSceneGraph Found: ${OPENSCENEGRAPH_VERSION}")
    message("     LIBS: ${OPENSCENEGRAPH_LIBRARIES}")
endif()

#------------------------------------#
#-     Look for OpenCV Libraries    -#
#------------------------------------#
find_package( OpenCV REQUIRED core highgui imgproc )
include_directories( ${OpenCV_INCLUDE_DIRS} )
if( OpenCV_FOUND )
    message("Found OpenCV: ${OpenCV_VERSION}")
    message("      Libs  : ${OpenCV_LIBS}")
    message("      Incl  : ${OpenCV_INCLUDE_DIRS}")
endif()

#  For some reason, OpenCV does not also link TBB
#  despite depending on it.  Add it for completion
find_package(TBB REQUIRED)
if( TBB_FOUND )
    message("Found TBB")
    message("      Libs: ${TBB_LIBRARIES}")
else()
    message(FATAL_ERROR "Did not find TBB")
endif()

#-------------------------------#
#-     Define Common Code      -#
#-------------------------------#
add_subdirectory(common)


#------------------------------------#
#-     Build Chapter 3 Examples     -#
#------------------------------------#
add_subdirectory(chapter3)


#------------------------------------#
#-     Build Chapter 4 Examples     -#
#------------------------------------#
add_subdirectory(chapter4)


#------------------------------------#
#-     Build Chapter 6 Examples     -#
#------------------------------------#
add_subdirectory(chapter6)


#------------------------------------#
#-     Build Chapter 9 Examples     -#
#------------------------------------#
add_subdirectory(chapter9)

