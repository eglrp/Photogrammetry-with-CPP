/**
 * @file    OSG_Utilities.cpp
 * @author  Marvin Smith
 * @date    12/13/2015
 */
#include "OSG_Utilities.hpp"

// Coordinate 
#include "Coordinate_Utilities.hpp"

    

/****************************************/
/*          Write the DEM Mesh          */
/****************************************/
osg::ref_ptr<osg::Geode> Build_DEM_Mesh( const cv::Mat& dem,
                                         const double*  geo_transform )
{

    // Create the list of points
    osg::Geode* mesh = new osg::Geode();
    osg::Geometry* geometry = new osg::Geometry();
    osg::Vec3Array* vertices = new osg::Vec3Array();
    osg::Vec2Array* texcoords = new osg::Vec2Array();
    osg::Vec3Array* normals = new osg::Vec3Array();

    int maxR = dem.rows/4;
    int maxC = dem.cols/4;
    double lon, lat;

    
    // Pre-Compute Geographic Coordinates
    double* lats = new double[maxR * maxC];
    double* lons = new double[maxR * maxC];
    double mean_lat = 0, mean_lon = 0;
    int counter = 0;
    for( int r=0; r<maxR; r++ )
    for( int c=0; c<maxC; c++ ){
        
        // Set the Geographic Coordinates
        lons[counter] = geo_transform[0] + geo_transform[1] * c + geo_transform[2] * r;
        lats[counter] = geo_transform[3] + geo_transform[4] * c + geo_transform[5] * r;
        
        // Update Mean Value
        mean_lat += lats[counter];
        mean_lon += lons[counter];

        // Increment counter
        counter++;
    }
    mean_lat /= counter;
    mean_lon /= counter;
    
    
    // Construct UTM Coordinates
    int grid_zone = Compute_UTM_Grid_Zone(  mean_lat, mean_lon );
    bool is_northern = (mean_lat >= 0) ? true : false;
    std::cout << "Grid Zone: " << grid_zone << std::endl;

    // Batch Convert Geographic to UTM
    std::cout << "Converting Batch" << std::endl;
    double* eastings  = new double[maxR * maxC];
    double* northings = new double[maxR * maxC];
    Convert_Geographic_To_UTM( maxR * maxC, lats, lons, "WGS84", grid_zone, is_northern, eastings, northings, "WGS84" );


    // Compute Center Coordinate
    std::cout << "Computing Center" << std::endl;
    double mean_x, mean_y;
    Convert_Geographic_To_UTM( mean_lat, mean_lon, "WGS84", grid_zone, is_northern, mean_x, mean_y, "WGS84" ); 
    osg::Vec3f center( mean_x, mean_y, 0 );

    // Construct the Vertices
    counter = 0;
    for( int r=0; r<maxR; r++ )
    {
        std::cout << "Row: " << r << std::endl;
        for( int c=0; c<maxC; c++, counter++ )
        {
            // Compute longitude and latitude
            osg::Vec3f  coord( eastings[counter],
                               northings[counter],
                               dem.at<short>(r,c));

            // Add the point
            vertices->push_back( coord );
        
            // Compute the Normal
            int b1 = counter + 1;
            int b2 = ((r+1) * dem.cols) + c;
            int b1r = r;
            int b2r = r+1;
            int b1c = c+1;
            int b2c = c;
            osg::Vec3f a = osg::Vec3f( eastings[b1], northings[b1], dem.at<short>(b1r,b1c)) - center;
            osg::Vec3f b = osg::Vec3f( eastings[b2], northings[b2], dem.at<short>(b2r, b2c)) - center;

            // Cross product
            osg::Vec3f normalCoord = (a ^ b);
            normalCoord = normalCoord / normalCoord.normalize(); 

            // Set the Normal
            normals->push_back( normalCoord );

            // Add the Texture Coordinates
            //texcoords.push_back( 
        }
    }
    geometry->setVertexArray( vertices );


    // Construct the Primitive Sets
    for( int r=0; r<(maxR-1); r++ )
    for( int c=0; c<(maxC-1); c++ )
    {
        osg::DrawElementsUInt* pset = new osg::DrawElementsUInt( GL_TRIANGLE_STRIP );
        
        // Get the index value
        int tl = (r * maxC) + c;
        int tr = (r * maxC) + c+1;
        int bl = ((r+1) * maxC) + c;
        int br = ((r+1) * maxC) + c + 1;
        pset->push_back(tl);
        pset->push_back(tr);
        pset->push_back(bl);
        pset->push_back(br);
        pset->push_back(tl);
        pset->push_back(bl);
    
        // Add the primitive set
        geometry->addPrimitiveSet( pset );
    } 



    //  Set the Name of the Mesh
    mesh->setName("Grid");
    

    // Set the Geometry
    mesh->addDrawable( geometry );

    // Clean up
    delete [] lats;
    delete [] lons;
    delete [] eastings;
    delete [] northings;

    return mesh;
}


/*****************************************/
/*        Build the Color Mesh           */
/*****************************************/
osg::ref_ptr<osg::StateSet>  Build_Color_Mesh( osg::ref_ptr<osg::Node> loadedModel,
                                               const osg::Vec3f&        Direction )
{
    // Create a Bounding Sphere
    const osg::BoundingSphere& bs = loadedModel->getBound();
    
    
    // Build output image
    osg::Image* image = new osg::Image;
    int noPixels = 1000;
    int divider = 200;

    // Now I am going to build the image data
    image->allocateImage( noPixels , 1 , 1 , GL_RGBA , GL_FLOAT );
    image->setInternalTextureFormat( GL_RGBA );

    // Set the color info
    std::vector< osg::Vec4 > colour;
    colour.push_back( osg::Vec4( 0.6f , 0.6f , 0.6f , 1.0f ) );
    colour.push_back( osg::Vec4( 0.6f , 0.6f , 0.6f , 1.0f ) );

    // file in the image data
    osg::Vec4* dataPtr = (osg::Vec4*)image->data();
    for ( int i = 0 ; i < divider ; ++i )
    {
        osg::Vec4 color = colour[0];
        *dataPtr++ = color;
    }
    for ( int i=divider ; i < noPixels ; ++i ) 
    {
        osg::Vec4 color = colour[1];
        *dataPtr++ = color;
    }

    // Texture 1D
    osg::Texture1D* texture = new osg::Texture1D;
    texture->setWrap( osg::Texture1D::WRAP_S , osg::Texture1D::MIRROR );
    texture->setFilter( osg::Texture1D::MIN_FILTER , osg::Texture1D::LINEAR );
    texture->setFilter( osg::Texture1D::MAG_FILTER , osg::Texture1D::LINEAR );
    texture->setImage( image );

    float zBase = bs.center().z() - bs.radius();
    float zScale = 0.4;

    // Texture Coordinate Generator
    osg::TexGen* texgen = new osg::TexGen;
    texgen->setMode( osg::TexGen::OBJECT_LINEAR );
    texgen->setPlane( osg::TexGen::S , osg::Plane( zScale*Direction.x(), 
                                                   zScale*Direction.y(), 
                                                   zScale*Direction.z(), -zBase ) );

    osg::Material* material = new osg::Material;

    osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
    stateset->setTextureAttribute( 0 , texture , osg::StateAttribute::OVERRIDE );
    stateset->setTextureMode( 0 , GL_TEXTURE_1D , osg::StateAttribute::ON  | osg::StateAttribute::OVERRIDE );
    stateset->setTextureMode( 0 , GL_TEXTURE_2D , osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE );
    stateset->setTextureMode( 0 , GL_TEXTURE_3D , osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE );

    stateset->setTextureAttribute( 0 , texgen , osg::StateAttribute::OVERRIDE );
    stateset->setTextureMode( 0 , GL_TEXTURE_GEN_S , osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE );

    stateset->setAttribute( material, 
                            osg::StateAttribute::OVERRIDE );

    return stateset;
}


