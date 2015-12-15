/**
 * @file    fbx-render-terrain.cpp
 * @author  Marvin Smith
 * @date    11/26/2015
*/

// C++ Libraries
#include <iostream>
#include <string>


// OpenCV Libraries
#include <opencv2/core.hpp>

// Render Utilities
#include "../common/Model_Utilities.hpp"
#include "../common/Raster_Utilities.hpp"


int main( int argc, char* argv[] )
{
    // Parse arguments
    std::string output_pathname = argv[2];
    
    // Load Input DEM
    std::string dem_pathname = argv[1];
    double* geo_transform = new double[6];

    Load_Raster_GDAL2CV( dem_pathname,
                         geo_transform );
    
    
    // Construct the FBX 3D Model
    Build_FBX_Model(  
                     geo_transform,
                     output_pathname );

    // Clean Up
    delete [] geo_transform;

    // Exit
    return 0;
}

