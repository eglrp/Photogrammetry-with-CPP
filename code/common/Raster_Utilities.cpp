/**
 * @file    Raster_Utilities.cpp
 * @author  Marvin Smith
 * @date    11/21/2015
*/
#include "Raster_Utilities.hpp"

// C++ Libraries
#include <iostream>

// GDAL Libraries
#include <gdal.h>
#include <gdal_priv.h>


/*********************************************************/
/*         Load Dataset Into OpenCV Mat Object           */
/*********************************************************/
bool Load_Raster_GDAL2CV( const std::string& pathname,
                          cv::Mat&           image,
                          double*&           geo_transform )
{
    // Init GDAL
    GDALAllRegister();

    // Open the GDAL Dataset
    GDALDataset* dataset = (GDALDataset*)GDALOpen( pathname.c_str(),
                                                   GA_ReadOnly );


    // Make sure the dataset is not null
    if( dataset == NULL ){
        std::cerr << "Unable to load dataset (" << pathname << ")." << std::endl;
        return false;
    }


    // otherwise, grab the transform
    if( dataset->GetGeoTransform(geo_transform) != CE_None ){
        std::cerr << "Unable to get the Geo-Transform." << std::endl;
        return false;
    }

    // Get the band count
    int channels = dataset->GetRasterCount();
    int rows     = dataset->GetRasterYSize();
    int cols     = dataset->GetRasterXSize();

    // Construct OpenCV Channels
    std::vector<cv::Mat> image_list(channels, cv::Mat( rows, cols, CV_8UC1));

    // Iterate over each band
    for( int channel=1; channel <= channels; channel++ )
    {
        // Fetch the band
        GDALRasterBand* band = dataset->GetRasterBand(channel);

        // Grab pixel data
        band->RasterIO( GF_Read, 0, 0, cols, rows,
                        image_list[channel-1].data,
                        cols, rows, GDT_Byte, 0, 0);
    }

    // Merge channels
    cv::merge( image_list, image );

    // Return success
    return true;
}


