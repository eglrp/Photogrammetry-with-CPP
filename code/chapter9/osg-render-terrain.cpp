/**
 * @file    osg-render-terrain.cpp
 * @author  Marvin Smith
 * @date    11/27/2015
*/

// OpenCV Libraries
#include <opencv2/core/core.hpp>


// C++ Libraries
#include <iostream>
#include <string>


// Common Libraries
#include "../common/OSG_Utilities.hpp"
#include "../common/Raster_Utilities.hpp"
#include "OSG_Render_Utilities.hpp"


// OSG Libraries
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/StateSetManipulator>

/**
 * @brief Main Application
*/
int main( int argc, char* argv[] )
{
    
    // Parse Command-Line Options
    Options options( argc, argv );


    // Load the DEM
    cv::Mat dem;
    double* geo_transform = new double[6];
    Load_Raster_GDAL2CV( options.Get_DEM_Pathname(),
                         dem,
                         geo_transform );



    // Write OSG File
    osg::ref_ptr<osg::Group> osg_mesh =  Write_OSG_Mesh( options.Get_Output_Pathname(),
                                                         dem,
                                                         geo_transform );

    
    // Create viewer if desired
    if( options.Check_Flag("viewer") == true )
    {
        std::cout << "Creating Viewer" << std::endl;
        osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
        viewer->setSceneData(osg_mesh.get());
        viewer->setCameraManipulator(new osgGA::TrackballManipulator);
        viewer->addEventHandler(new osgViewer::StatsHandler);
        viewer->run();

    }

    // Clean Up
    delete [] geo_transform;

    // Return
    return 0;
}

