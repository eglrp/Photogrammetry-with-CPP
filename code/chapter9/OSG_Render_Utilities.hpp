/**
 * @file    OSG_Render_Utilities.hpp
 * @author  Marvin Smith
 * @date    12/24/2015
*/
#ifndef __CODE_CHAPTER9_OSG_RENDER_UTILITIES_HPP__
#define __CODE_CHAPTER9_OSG_RENDER_UTILITIES_HPP__

// C++ Libraries
#include <map>
#include <string>

// OpenCV Libraries
#include <opencv2/core/core.hpp>

// OSG Libraries
#include "../common/OSG_Utilities.hpp"

/**
 * @class Options
*/
class Options
{
    public:
  
        /**
         * @brief Constructor
        */
        Options( int argc, char* argv[] );
       
        
        /**
         * @brief Usage Options
        */
        void Usage()const;


        /**
         * @brief Get the DEM Pathname
        */
        inline std::string Get_DEM_Pathname()const{
            return m_dem_pathname;
        }


        /**
         * @brief Get the Output Pathname.
        */
        inline std::string Get_Output_Pathname()const{
            return m_output_pathname;
        }


        /**
         * @brief Check Flag
         *
         * @param[in] flag_name
         *
         * @return Status
        */
        inline bool Check_Flag( const std::string& flag_name )const{
            return m_status_flags.find(flag_name)->second;
        }

    private:
        
        /// Application Name
        std::string m_application_name;

        /// DEM Pathname
        std::string m_dem_pathname;

        /// Output Pathname
        std::string m_output_pathname;

        /// Status Flags
        std::map<std::string,bool> m_status_flags;

}; // End of Options Class


/**
 * @brief Write the OSG Mesh File
*/
osg::ref_ptr<osg::Group>  Write_OSG_Mesh( const std::string& output_pathname,
                                          const cv::Mat&     dem,
                                          const double*      geo_transform );


#endif
