/**
 * @file    FBX_Utilities.hpp
 * @author  Marvin Smith
 * @date    11/26/2015
*/
#ifndef __COMMON_FBX_UTILITIES_HPP__
#define __COMMON_FBX_UTILITIES_HPP__

//  Autodesk FBX Library
#include <fbxsdk.h>


/**
 * @brief Load the Scene
*/
bool LoadScene(FbxManager* pManager, FbxDocument* pScene, const char* pFilename);


void CreateAndFillIOSettings(FbxManager* pManager);


/**
 * @brief Initialize the SDK Objects.
 *
 * @param[in/out] manager
 * @param[in/out] scene
*/
void InitializeSdkObjects( FbxManager*& manager, 
                           FbxScene*&   scene);


/**
 * @brief Destroy SDK Objects
 * 
 * @param[in] manager
 * @param[in] exit_status
*/
void DestroySdkObjects( FbxManager*  manager, 
                        const bool&  exit_status);

/**
 * @brief Save the FBX Scene File
 *
 * @param[in] manager
 * @param[in] scene
 * @param[in] filename
 * @param[in] file_format
 * @param[in] embed_media
 *
 * @return True if successful, false otherwise.
*/
bool SaveScene( FbxManager*  manager, 
                FbxDocument* scene, 
                const char*  filename, 
                const int&   file_format = -1, 
                const bool&  embed_media = false);



#endif
