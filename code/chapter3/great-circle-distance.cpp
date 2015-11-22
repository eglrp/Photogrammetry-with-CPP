/**
 * @file   great-circle-distance.cpp
 * @author Marvin Smith
 * @date   11/21/2015
*/

// C++ Libraries
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Compute Great Circle Distance between two coordinates.
 *
 * @param[in] lat_1_degrees
 * @param[in] lon_1_degrees
 * @param[in] lat_1_degrees
 * @param[in] lon_1_degrees
*/
double Haversine_Distance( const double& lat_1_degrees,
                           const double& lon_1_degrees,
                           const double& lat_2_degrees,
                           const double& lon_2_degrees,
                           const double& radius_meters )
{
    // Convert Degrees to Radians
    const double lat_1_rad = lat_1_degrees * M_PI / 180.0;
    const double lon_1_rad = lon_1_degrees * M_PI / 180.0;
    const double lat_2_rad = lat_2_degrees * M_PI / 180.0;
    const double lon_2_rad = lon_2_degrees * M_PI / 180.0;

    // Compute Differences
    const double h_lat = std::pow( std::sin((lat_2_rad - lat_1_rad)/2), 2);
    const double h_lon = std::pow( std::sin((lon_2_rad - lon_1_rad)/2), 2); 
        
    // Compute result
    const double asin_val = std::sqrt(h_lat + std::cos(lat_1_rad) * std::cos(lat_2_rad) * h_lon);

    return (2 * radius_meters * std::asin( asin_val ));
}

int main()
{
    // Coordinate Values
    const double lat_1_deg = 39.5;
    const double lon_1_deg = -120.5;
    const double lat_2_deg = 39;
    const double lon_2_deg = -120;
    const double earth_radius_meters = 6378137.0;

    // Compute Distance in Meters
    const double dist_meters = Haversine_Distance( lat_1_deg,
                                                   lon_1_deg,
                                                   lat_2_deg,
                                                   lon_2_deg,
                                                   earth_radius_meters );

    // Print Distance
    std::cout << std::fixed << "Distance (m): " << dist_meters << std::endl;

    return 0;
}
