/**
 * @file    geographiclib-coordinate-conversion.cpp
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
int main() 
{
    
    try {
    
        GeographicLib::MagneticModel mag("wmm2010");
        
        double lat = 27.99, lon = 86.93, h = 8820, t = 2012; // Mt Everest
        double Bx, By, Bz;
        
        mag(t, lat,lon, h, Bx, By, Bz);
        
        double H, F, D, I;
        
        
        MagneticModel::FieldComponents(Bx, By, Bz, H, F, D, I);
        cout << H << " " << F << " " << D << " " << I << "\n";
            
    }
    
    catch (const exception& e) 
    { 
        cerr << "Caught exception: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
