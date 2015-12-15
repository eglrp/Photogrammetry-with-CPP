/**
 * @file    Model_Utilities.hpp
 * @author  Marvin Smith
 * @date    11/26/2015
*/
#ifndef __COMMON_MODEL_UTILITIES_HPP__
#define __COMMON_MODEL_UTILITIES_HPP__

// OpenCV Libraries
#include <opencv2/core.hpp>

// C++ Libraries
#include <string>


/**
 * @brief Build an FBX Model.
*/
bool Build_FBX_Model( 
                      const double*      geo_transform,
                      const std::string& output_pathname );


#endif
