/**
 * @file    Coordinate_Utilities.hpp
 * @author  Marvin Smith
 * @date    11/10/2015
*/
#ifndef __COORDINATE_UTILITIES_HPP__
#define __COORDINATE_UTILITIES_HPP__

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


#endif
