/**
 * @file    Coordinate_Utilities.hpp
 * @author  Marvin Smith
 * @date    11/10/2015
*/
#ifndef __COORDINATE_UTILITIES_HPP__
#define __COORDINATE_UTILITIES_HPP__

// C++ Libraries
#include <string>


/**
 * @brief Compute the UTM Latitude Band.
 *
 * @param[in] latitude_degrees Latitude angle in degrees.  Range from [-90,90].
 *
 * @return UTM Latitude Band as Char.
*/
char Compute_UTM_Latitude_Band( const double& latitude_degrees );


/**
 * @brief Compute the UTM Grid Zone given Latitude and Longitude.
 *
 * @param[in] latitude_degrees Latitude in degrees [-90,90]
 * @param[in] longitude_degrees Longitude in degrees [-180,180]
 *
 * @return Grid zone value.
*/
int Compute_UTM_Grid_Zone( const double& latitude_degrees,
                           const double& longitude_degrees );


/** 
 * @brief Convert Geographic to UTM
 */
void Convert_Geographic_To_UTM( const double&       latitude_degrees,
                                const double&       longitude_degrees,
                                const std::string&  input_datum,
                                const int&          grid_zone,
                                const bool&         is_northern,
                                double&             easting_meters,
                                double&             northing_meters,
                                const std::string&  output_datum );


/** 
 * @brief Convert Geographic to UTM
 */
void Convert_Geographic_To_UTM( const int&          number_coordinates,
                                const double*       latitude_degrees,
                                const double*       longitude_degrees,
                                const std::string&  input_datum,
                                const int&          grid_zone,
                                const bool&         is_northern,
                                double*             eastings_meters,
                                double*             northings_meters,
                                const std::string&  output_datum );


#endif
