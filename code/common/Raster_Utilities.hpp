/**
 * @file    Raster_Utilities.hpp
 * @author  Marvin Smith
 * @date    11/21/2015
*/
#ifndef  __COMMON_RASTER_UTILITIES_HPP__
#define  __COMMON_RASTER_UTILITIES_HPP__


// OpenCV Libraries
#include <opencv2/core/core.hpp>

// C++ Libraries
#include <string>


/**
 * @brief Load Dataset into CV Mat.
 *
 * @param[in]  pathname      Path to image data.
 * @param[out] image         Image data.
 * @param[out] geo_transform Geographic Transform Data.
*/
bool Load_Raster_GDAL2CV( const std::string& pathname,
                          cv::Mat&           raster,
                          double*&           geo_transform);



#endif
