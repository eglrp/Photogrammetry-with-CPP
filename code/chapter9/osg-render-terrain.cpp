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
    std::cout << "Building DEM Node" << std::endl;
    root_node->addChild( Build_DEM_Mesh( dem, 
                                         geo_transform ));

    
    // Write the Node File
    std::cout << "Writing Node File To: " << output_pathname << std::endl;
    osgDB::writeNodeFile( *root_node.get(),
                           output_pathname,
                           write_options );
    std::cout << "Write the OSG Mesh" << std::endl;
}

/**
 * @brief Main Application
*/
int main( int argc, char* argv[] )
{
    // Parse Command-Line Options
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <dem-path> <output-path>" << std::endl;
        return 1;
    }
    std::string dem_pathname = argv[1];
    std::string output_pathname = argv[2];


    // Load the DEM
    cv::Mat dem;
    double* geo_transform = new double[6];
    Load_Raster_GDAL2CV( dem_pathname,
                         dem,
                         geo_transform );



    // Write OSG File
    Write_OSG_Mesh( output_pathname,
                    dem,
                    geo_transform );

    // Clean Up
    delete [] geo_transform;

    // Return
    return 0;
}

