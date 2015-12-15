/**
 * @file    Model_Utilities.cpp
 * @author  Marvin Smith
 * @date    11/26/2015
*/
#include "Model_Utilities.hpp"


// Autodesk FBX Libraries
#include <fbxsdk.h>

// Common Libraries
#include "FBX_Utilities.hpp"


/********************************************/
/*          Build the FBX Model             */
/********************************************/
bool Build_FBX_Model( 
                      const double*       geo_transform,
                      const std::string&  output_pathname )
{

    // Create the model
    FbxManager* sdk_manager = NULL;
    FbxScene*   scene       = NULL;

    InitializeSdkObjects( sdk_manager,
                          scene );

    // Register our new mesh
     
    
    // Save the scene
    const char* opath = output_pathname.c_str();
    bool result = SaveScene( sdk_manager,
                             scene,
                             opath );


    // Clean up 
    DestroySdkObjects( sdk_manager,
                       result );

}


