/**
 * @file    OSG_Render_Utilities.cpp
 * @author  Marvin Smith
 * @date    12/24/2015
*/
#include "OSG_Render_Utilities.hpp"

// C++ Libraries
#include <cstdlib>
#include <deque>
#include <iostream>


/***********************************/
/*          Constructor            */
/***********************************/
Options::Options( int argc, char* argv[] )
 : m_dem_pathname(""),
   m_output_pathname("")
{
    // Set the Application Name
    m_application_name = argv[0];

    // Set default status flags
    m_status_flags["viewer"] = false;
    m_status_flags["verbose"] = false;


    //  Construct arg list
    std::string arg;
    std::deque<std::string> args;
    for( int i=1; i<argc; i++ )
        args.push_back(argv[i]);

    // Check if we have enough arguments
    if( args.size() < 2 ){
        std::cerr << "Not enough arguments" << std::endl;
        Usage();
        exit(1);
    }

    // Pop all arguments
    while( args.size() > 0 )
    {
        // Pop next argument
        arg = args.front();
        args.pop_front();

        // Check if requesting help
        if( arg == "-h" || arg == "--help" )
        {
            Usage();
            exit(1);
        }
        
        // Check Verbose
        else if( arg == "--verbose" || arg == "-v" )
        {
            m_status_flags["verbose"] = true;
        }

        // Check Viewer Flag
        else if( arg == "--viewer" ){
            m_status_flags["viewer"] = true;
        }

        // Otherwise, check if dem pathname set
        else if( m_dem_pathname.size() <= 0 )
        {
            m_dem_pathname = arg;
        }

        // Otherwise, check if output path set
        else if( m_output_pathname.size() <= 0 )
        {
            m_output_pathname = arg;
        }

        // Otherwise, error
        else{
            std::cerr << "Unknown argument (" << arg << ")" << std::endl;
            exit(1);
        }

    }

}


/************************************/
/*        Usage Instructions        */
/************************************/
void Options::Usage()const
{
    // Print Usage
    std::cerr << "usage: " << m_application_name << " [flags] <dem-pathname> <output-pathname>" << std::endl;
    std::cerr << std::endl;

    // Print flags
    std::cerr << "flags: " << std::endl;
    std::cerr << "--viewer       : Run OSG Viewer" << std::endl;
    std::cerr << "-v | --verbose : Print verbose logging." << std::endl;
    std::cerr << std::endl;

    // Print DEM and output options
    std::cerr << "<dem-pathname> : DEM Pathname" << std::endl;
    std::cerr << std::endl;

    std::cerr << "<output-pathname> : Path to OSG Binary file. Do not include the .osgb extension." << std::endl;
    std::cerr << std::endl;
}


/*********************************************************/
/*               Write the OSG Mesh File                 */
/*********************************************************/
osg::ref_ptr<osg::Group>  Write_OSG_Mesh( const std::string& output_pathname,
                                          const cv::Mat&     dem,
                                          const double*      geo_transform )
{

    // Define Write Options
    osgDB::Options* write_options = new osgDB::Options();//"WriteImageHint=IncludeData Compressor=zlib");

    // Create the Root Nodes
    osg::ref_ptr<osg::Group> root_node(new osg::Group());
    

    // Add the DEM Node
    std::cout << "Building DEM Node" << std::endl;
    osg::ref_ptr<osg::Geode> dem_node = Build_DEM_Mesh( dem, 
                                                        geo_transform );
    root_node->addChild(dem_node);
    
    // Add the Color Node
    std::cout << "Constructing Color Mesh" << std::endl;
    osg::ref_ptr<osg::StateSet> stateSet = Build_Color_Mesh( dem_node,
                                                             osg::Vec3f( 0, 0, 1)); 
    stateSet->setMode( GL_BLEND,    osg::StateAttribute::ON );
    stateSet->setMode( GL_LIGHTING, osg::StateAttribute::ON );
    root_node->setStateSet( stateSet );

   
    // Smooth the Camera data
    if( true )
    {
      osgUtil::SmoothingVisitor sv;
      root_node->accept(sv);
    }


    // Optimize the Camera Data
    std::cout << "Optimizing" << std::endl;
    osgUtil::Optimizer optimizer;
    optimizer.optimize( root_node.get() );
    
    // Write the Node File
    std::cout << "Writing Node File To: " << output_pathname << std::endl;
    osgDB::writeNodeFile( *root_node.get(),
                           output_pathname,
                           write_options );

    return root_node;
}


