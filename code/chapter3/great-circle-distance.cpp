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
                           const double& lon_2_degrees )
{
    // Convert Degrees to Radians
    double lat_1_rad = lat_1_degrees * M_PI / 180.0;
    double lon_1_rad = lon_1_degrees * M_PI / 180.0;
    double lat_2_rad = lat_2_degrees * M_PI / 180.0;
    double lon_2_rad = lon_2_degrees * M_PI / 180.0;

    // Compute Latitude Difference

    // Compute Longitude Difference

    dz = sin(th1) - sin(th2);
    dx = cos(ph1) * cos(th1) - cos(th2);
    dy = sin(ph1) * cos(th1);
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}

int main()
{
    double d = dist(36.12, -86.67, 33.94, -118.4);
    /* Americans don't know kilometers */
    printf("dist: %.1f km (%.1f mi.)\n", d, d / 1.609344);

    return 0;
}
