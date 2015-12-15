/**
 * @file    OSG_Utilities.hpp
 * @author  Marvin Smith
 * @date    12/13/2015
 */
#ifndef __PHOTOGRAMMETRY_CPP_CODE_COMMON_OSG_UTILITIES_HPP__
#define __PHOTOGRAMMETRY_CPP_CODE_COMMON_OSG_UTILITIES_HPP__

// OpenCV Libraries
#include <opencv2/core/core.hpp>


// C++ Libraries
#include <string>


// OpenSceneGraph Libraries
#include <osg/Geode>
#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osgUtil/Optimizer>
#include <osgUtil/SmoothingVisitor>
#include <osgUtil/Simplifier>
#include <osg/Node>
#include <osg/Texture1D>
#include <osg/Texture2D>
#include <osg/TexGen>
#include <osg/Material>
#include <osgViewer/Viewer>
#include <osgDB/Registry>
#include <osgDB/WriteFile>
#include <osgDB/ReadFile>
#include <osgSim/Version>
#include <osgFX/Version>
#include <osgTerrain/Version>
#include <osgVolume/Version>



/**
 * @brief Write Digital Elevation Model as OSG Mesh.
 *
 * @param[in] output_pathname
 * @param[in] dem
 */
osg::Node* Build_DEM_Mesh( const cv::Mat& dem,
                           const double*  geo_transform );


#endif
