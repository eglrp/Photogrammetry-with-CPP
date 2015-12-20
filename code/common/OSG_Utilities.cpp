/**
 * @file    OSG_Utilities.cpp
 * @author  Marvin Smith
 * @date    12/13/2015
 */
#include "OSG_Utilities.hpp"


/****************************************/
/*          Write the DEM Mesh          */
/****************************************/
osg::Node* Build_DEM_Mesh( const cv::Mat& dem,
                           const double*  geo_transform )
{

    // Create the list of points
    osg::Geode* mesh = new osg::Geode();
    osg::Geometry* geometry = new osg::Geometry();
    osg::Vec3Array* vertices = new osg::Vec3Array();
    osg::Vec2Array* texcoords = new osg::Vec2Array();
    osg::Vec3Array* normals = new osg::Vec3Array();



    return mesh;
}

