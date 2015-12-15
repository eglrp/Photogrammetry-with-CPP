/**
 * @file    gdal-load-image.cpp
 * @author  Marvin Smith
 * @date    11/24/2015
*/

// GDAL Libraries
#include <gdal.h>
#include <gdal_priv.h>


// C++ Libraries
#include <iostream>
#include <string>


int main( int argc, char* argv[] )
{
    // Register GDAL
    GDALAllRegister();

    // Pathname
    std::string pathname = argv[1];
    
    // Load the driver
    GDALDataset* dataset = (GDALDataset*)GDALOpen( pathname.c_str(),
                                                   GA_ReadOnly );

    // Make sure the dataset is not null
    if( dataset == NULL ){
        std::cerr << "Unable to load image." << std::endl;
        return 1;
    }

    // Grab the driver
    GDALDriver* driver = dataset->GetDriver();

    
    // Fetch the number of channels


    // Close Up
    GDALClose(driver);

    // exit
    return 0;
}

