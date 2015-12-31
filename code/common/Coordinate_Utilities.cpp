/**
 * @file    Coordinate_Utilities.cpp
 * @author  Marvin Smith
 * @date    11/10/2015
*/
#include "Coordinate_Utilities.hpp"

// C++ Libraries
#include <algorithm>
#include <cmath>
#include <iostream>

// OGR
#include <ogr_spatialref.h>

/**
 * @brief Compute the UTM Latitude Band.
 *
 * @param[in] latitude_degrees Latitude angle in degrees.  Range from [-90,90].
 *
 * @return UTM Latitude Band as Char.
*/
char Compute_UTM_Latitude_Band( const double& latitude_degrees )
{
    if((84 >= latitude_degrees) && (latitude_degrees >= 72)){ 
        return 'X';
    }
    if((72 > latitude_degrees) && (latitude_degrees >= 64)){
        return 'W';
    }
    else if((64 > latitude_degrees) && (latitude_degrees >= 56)){
        return 'V';
    }
    else if((56 > latitude_degrees) && (latitude_degrees >= 48)){
        return 'U';
    }
    else if((48 > latitude_degrees) && (latitude_degrees >= 40)){
        return 'T';
    }
    else if((40 > latitude_degrees) && (latitude_degrees >= 32)){
        return 'S';
    }
    else if((32 > latitude_degrees) && (latitude_degrees >= 24)){
        return 'R';
    }
    else if((24 > latitude_degrees) && (latitude_degrees >= 16)){
        return 'Q';
    }
    else if((16 > latitude_degrees) && (latitude_degrees >= 8)){ 
        return 'P';
    }
    else if(( 8 > latitude_degrees) && (latitude_degrees >= 0)){
        return 'N';
    }
    else if(( 0 > latitude_degrees) && (latitude_degrees >= -8)){ 
        return 'M';
    }
    else if((-8> latitude_degrees) && (latitude_degrees >= -16)){
        return 'L';
    }
    else if((-16 > latitude_degrees) && (latitude_degrees >= -24)){
        return 'K';
    }
    else if((-24 > latitude_degrees) && (latitude_degrees >= -32)){
        return 'J';
    }
    else if((-32 > latitude_degrees) && (latitude_degrees >= -40)){
        return 'H';
    }
    else if((-40 > latitude_degrees) && (latitude_degrees >= -48)){
        return 'G';
    }
    else if((-48 > latitude_degrees) && (latitude_degrees >= -56)){
        return 'F';
    }
    else if((-56 > latitude_degrees) && (latitude_degrees >= -64)){
        return 'E';
    }
    else if((-64 > latitude_degrees) && (latitude_degrees >= -72)){
        return 'D';
    }
    else if((-72 > latitude_degrees) && (latitude_degrees >= -80)){
        return 'C';
    }
    
    // This should be considered an error condition.
    return 'Z';
}


/**
 * @brief Compute the UTM Grid Zone given Latitude and Longitude.
 *
 * @param[in] latitude_degrees Latitude in degrees [-90,90]
 * @param[in] longitude_degrees Longitude in degrees [-180,180]
 *
 * @return Grid zone value.
*/
int Compute_UTM_Grid_Zone( const double& latitude_degrees,
                           const double& longitude_degrees )
{
    // Create zone using standard algorithm
    int grid_zone = std::floor((longitude_degrees + 180)/6) + 1;

    // Check if we are around an exception near Norway
    if( latitude_degrees  >= 56.0 && latitude_degrees  < 64.0 && 
            longitude_degrees >= 3.0  && longitude_degrees < 12.0 )
    {
        return 32;
    }

    // Check for Svalbard
    if( latitude_degrees >= 72.0 && latitude_degrees < 84.0 ) 
    {
        if( longitude_degrees >= 0.0  && longitude_degrees <  9.0 ){
            return 32;
        }                                          
        else if( longitude_degrees >= 9.0  && longitude_degrees < 21.0 ){
            return 33;
        }
        else if( longitude_degrees >= 21.0 && longitude_degrees < 33.0 ){
            return 35;
        }
        else if( longitude_degrees >= 33.0 && longitude_degrees < 42.0 ){
            return 37;
        }
    }
    return grid_zone;
}


/************************************************************/
/*          Compute the Conversion from Geog to UTM         */
/************************************************************/
void Convert_Geographic_To_UTM( const double&       latitude_degrees,
                                const double&       longitude_degrees,
                                const std::string&  input_datum,
                                const int&          grid_zone,
                                const bool&         is_northern,
                                double&             easting_meters,
                                double&             northing_meters,
                                const std::string&  output_datum )
{
    // Create the Spatial Reference Objects
    OGRSpatialReference sourceSRS, targetSRS;

    sourceSRS.SetWellKnownGeogCS(  input_datum.c_str() );
    targetSRS.SetWellKnownGeogCS( output_datum.c_str() );

    // Configure the Projected Coordinate Components
    targetSRS.SetUTM( grid_zone,
                      is_northern );

    // Build the Transform Engine
    OGRCoordinateTransformation* transform;
    transform = OGRCreateCoordinateTransformation( &sourceSRS,
                                                   &targetSRS );
    
    easting_meters          = longitude_degrees;
    northing_meters         = latitude_degrees;
    double output_elevation_meters = 0;

    if( !transform->Transform( 1, &easting_meters,
                                  &northing_meters,
                                  &output_elevation_meters ) )
    {
        throw std::runtime_error("Transformation Failed.");
    }

    
    // Destroy the Transform
    OCTDestroyCoordinateTransformation( transform );
}


/************************************************************/
/*          Compute the Conversion from Geog to UTM         */
/************************************************************/
void Convert_Geographic_To_UTM( const int&          number_coordinates,
                                const double*       latitudes_degrees,
                                const double*       longitudes_degrees,
                                const std::string&  input_datum,
                                const int&          grid_zone,
                                const bool&         is_northern,
                                double*             eastings_meters,
                                double*             northings_meters,
                                const std::string&  output_datum )
{
    // Create the Spatial Reference Objects
    OGRSpatialReference sourceSRS, targetSRS;

    sourceSRS.SetWellKnownGeogCS(  input_datum.c_str() );
    targetSRS.SetWellKnownGeogCS( output_datum.c_str() );

    // Configure the Projected Coordinate Components
    targetSRS.SetUTM( grid_zone,
                      is_northern );

    // Build the Transform Engine
    OGRCoordinateTransformation* transform;
    transform = OGRCreateCoordinateTransformation( &sourceSRS,
                                                   &targetSRS );
    double* elevations_meters = NULL;

    memcpy( eastings_meters,  longitudes_degrees, sizeof(double)*number_coordinates );
    memcpy( northings_meters, latitudes_degrees,  sizeof(double)*number_coordinates );

    if( !transform->Transform( number_coordinates, 
                               eastings_meters,
                               northings_meters,
                               NULL ))
    {
        throw std::runtime_error("Transformation Failed.");
    }

    
    // Destroy the Transform
    OCTDestroyCoordinateTransformation( transform );
}

