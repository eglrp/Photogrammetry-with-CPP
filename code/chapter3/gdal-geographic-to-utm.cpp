
// GDAL Libraries
#include <ogr_spatialref.h>


// C++ Libraries
#include <iomanip>
#include <iostream>


// Common Libraries
#include "../common/Coordinate_Utilities.hpp"


/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Geographic Coordinates
    const double latitude_degrees  = 39.5;
    const double longitude_degrees = -119.5;
    const double elevation_meters  = 1234;
    const std::string input_datum  = "WGS84";
    const std::string output_datum = "WGS84";
    const bool is_northern = (latitude_degrees >= 0);

    // Compute the Recommended UTM Grid Zone
    int grid_zone = Compute_UTM_Grid_Zone( latitude_degrees,
                                           longitude_degrees);


    // Latitude Band
    char lat_band = Compute_UTM_Latitude_Band( latitude_degrees );


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
    
    double easting_meters          = longitude_degrees;
    double northing_meters         = latitude_degrees;
    double output_elevation_meters = elevation_meters;

    if( !transform->Transform( 1, &easting_meters,
                                  &northing_meters,
                                  &output_elevation_meters ) )
    {
        throw std::runtime_error("Transformation Failed.");
    }

    
    // Destroy the Transform
    OCTDestroyCoordinateTransformation( transform );

    // Print Results
    std::cout << std::fixed;
    std::cout << "UTM Grid Zone   : " << grid_zone << std::endl;
    std::cout << "Latitude Band   : " << lat_band << std::endl;
    std::cout << "Easting Meters  : " << easting_meters << std::endl;
    std::cout << "Northing Meters : " << northing_meters << std::endl;
    std::cout << "Elevation Meters: " << output_elevation_meters << std::endl;

    return 0;
}

