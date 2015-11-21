/**
 * @file    mgrs_to_utm.cpp
 * @author  Marvin Smith
 * @date    11/19/2015
*/

// C++ Libraries
#include <iostream>
#include <string>


// GeographicLib
#include <GeographicLib/MGRS.hpp>


using namespace std;
using namespace GeographicLib;


int main( int argc, char* argv[] )
{
    // Grab stdin
    const std::string mgrs_string = argv[1];
    std::string resulting_mgrs_string;

    // Print the input
    std::cout << "MGRS Coordinate: " << mgrs_string << std::endl;

    // UTM Elements
    int grid_zone;
    bool is_northern;
    double easting_meters, northing_meters;
    int precision_100km;
    bool from_center = true;
   

    // Convert to UTM
    MGRS::Reverse( mgrs_string,
                   grid_zone,
                   is_northern,
                   easting_meters,
                   northing_meters,
                   precision_100km,
                   from_center );

    // Print the results
    std::cout << "UTM Coordinate" << std::endl;
    std::cout << " - grid zone  : " << grid_zone << std::endl;
    std::cout << " - is northern: " << std::boolalpha << is_northern << std::endl;
    std::cout << " - easting    : " << easting_meters << std::endl;
    std::cout << " - northing   : " << northing_meters << std::endl;
    std::cout << " - precision  : " << precision_100km << std::endl;


    // Forward back to MGRS
    MGRS::Forward( grid_zone,
                   is_northern,
                   easting_meters,
                   northing_meters,
                   precision_100km,
                   resulting_mgrs_string );

    // Print the result
    std::cout << std::endl;
    std::cout << "Result MGRS String: " << resulting_mgrs_string << std::endl;
    
    // Return success
    return 0;
}


