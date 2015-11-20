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


int main( int argc, char* argv[] )
{
    // Grab stdin
    const std::string mgrs_string = argv[1];

    // UTM Elements
    int grid_zone;
    bool is_northern;
    double easting_meters, northing_meters;
    int precision_100km;
    bool from_center = true;
   

    // Convert to UTM
    GeographicLib::MGRS::Reverse( mgrs_string,
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

    // Return success
    return 0;
}


