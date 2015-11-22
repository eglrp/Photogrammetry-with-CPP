/**
 * @file    geographiclib-coordinate-distance.cpp
 * @author  Marvin Smith
 * @date    11/21/2015
*/

// C++ Libraries
#include <exception>
#include <iostream>


// GeographicLib Libraries
#include <GeographicLib/Constants.hpp>
#include <GeographicLib/Geodesic.hpp>


namespace GeoLib=GeographicLib;


int main( int argc, char* argv[] )
{
    
    try
    {
        // Define Coordinates: Mt. Tallac
        const double lat_1_deg =   38.905984;
        const double lon_1_deg = -120.098975;
        
        // Define Coordinates: Mt. Rose
        const double lat_2_deg =   39.343778;
        const double lon_2_deg = -119.917889;

        // GRS80 Compontents
        const double a = GeoLib::Constants::GRS80_a();
        const double f = 298.257222101;

        // Define our Datum
        GeoLib::Geodesic geodesic( a, f);


        // Compute the Distance between Coordinates
        double distance_meters;
        double azimuth1, azimuth2;
        geodesic.Inverse( lat_1_deg,
                          lon_1_deg,
                          lat_2_deg,
                          lon_2_deg, 
                          distance_meters,
                          azimuth1,
                          azimuth2 );

        
        // Compute the Direct and Compute the Endpoint
        double result_lat, result_lon;
        geodesic.Direct( lat_1_deg,
                         lon_1_deg,
                         azimuth1,
                         distance_meters,
                         result_lat,
                         result_lon );
        

        // Print info
        std::cout << "Coordinate 1 (deg): " << lat_1_deg << ", " << lon_1_deg << std::endl;
        std::cout << "Coordinate 2 (deg): " << lat_2_deg << ", " << lon_2_deg << std::endl;
        std::cout << "Distance      (m) : " << distance_meters << std::endl;
        std::cout << "Azimuth 1    (deg): " << azimuth1 << std::endl;
        std::cout << "Azimuth 2    (deg): " << azimuth2 << std::endl;
        std::cout << "Direct Coord (deg): " << result_lat << ", " << result_lon << std::endl;


    } 
    catch ( const std::exception& e )
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

