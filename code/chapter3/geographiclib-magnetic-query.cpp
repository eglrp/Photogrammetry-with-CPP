/**
 * @file    geographiclib-magnetic-query.cpp
 * @author  Marvin Smith
 * @date    11/12/2015
*/

// C++ Libraries
#include <exception>
#include <iostream>

#include <GeographicLib/MagneticModel.hpp>


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] ) 
{
    // Fetch the components
    const double lat  = std::stod(argv[1]);
    const double lon  = std::stod(argv[2]);
    const double elev = std::stod(argv[3]);
    const double year = std::stoi(argv[4]);
    
    
    try 
    {
    
        // Define the GeographicLib Magnetic Model Object
        GeographicLib::MagneticModel mag("wmm2010");
        
        double Bx, By, Bz;
        
        mag( year, lat, lon, elev,
             Bx, By, Bz);
        
        double H, F, D, I;
        
        
        GeographicLib::MagneticModel::FieldComponents(Bx, By, Bz, H, F, D, I);
        std::cout << H << " " << F << " " << D << " " << I << "\n";
            
    }
    
    catch (const std::exception& e) 
    { 
        std::cerr << "Caught exception: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
