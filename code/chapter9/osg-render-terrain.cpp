/**
 * @file    osg-render-terrain.cpp
 * @author  Marvin Smith
 * @date    11/27/2015
*/

// OpenCV Libraries
#include <opencv2/core.hpp>


// C++ Libraries
#include <iostream>
#include <string>


// Common Libraries
#include "../common/OSG_Utilities.hpp"
#include "../common/Raster_Utilities.hpp"



/**
 * @brief Write the OSG Mesh File
*/
void Write_OSG_Mesh( const std::string& output_pathname,
                     const cv::Mat&     dem,
                     const double*      geo_transform )
{

    // Define Write Options
    osgDB::Options* write_options = new osgDB::Options("WriteImageHint=IncludeData Compressor=zlib");

    // Create the Root Nodes
    osg::ref_ptr<osg::Group> root_node(new osg::Group());
    
    // Add the DEM Node
    root_node->addChild( Build_DEM_Mesh( dem, 
                                         geo_transform ));

    
    // Write the Node File
    osgDB::writeNodeFile( *root_node.get(),
                           output_pathname,
                           write_options );
}

/**
 * @brief Main Application
*/
int main( int argc, char* argv[] )
{
    // Load the DEM
    cv::Mat dem;
    double* geo_transform;
    std::string dem_pathname = argv[1];
    Load_Raster_GDAL2CV( dem_pathname,
                         dem,
                         geo_transform );
                         


    // Set the Output Pathname
    std::string output_pathname = argv[2];

    // Write OSG File
    Write_OSG_Mesh( output_pathname,
                    dem,
                    geo_transform );

    // Return
    return 0;
}

