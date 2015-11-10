
// GDAL Libraries
#include <ogr_spatialref.h>


// C++ Libraries
#include <iostream>
#include <math>


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
    else if((64 > latitude_degrees) && (latitude_degrees >= 56)) 
    {
        return 'V';
    }
    elseif((56 > Lat) && (Lat >= 48)) 
                                                                LetterDesignator = "U";
                                                                    elseif((48 > Lat) && (Lat >= 40))
                                                                         LetterDesignator = "T";
                                                                            elseif((40 > Lat) && (Lat >= 32))
                                                                                 LetterDesignator = "S";
                                                                                    elseif((32 > Lat) && (Lat >= 24))
                                                                                         LetterDesignator = "R";
                                                                                            elseif((24 > Lat) && (Lat >= 16))
                                                                                                 LetterDesignator = "Q";
                                                                                                    elseif((16 > Lat) && (Lat >= 8)) 
                                                                                                        LetterDesignator = "P";
                                                                                                            elseif(( 8 > Lat) && (Lat >= 0)) 
                                                                                                                LetterDesignator = "N";
                                                                                                                    elseif(( 0 > Lat) && (Lat >= -8)) 
                                                                                                                        LetterDesignator = "M";
                                                                                                                            elseif((-8> Lat) && (Lat >= -16)) 
                                                                                                                                LetterDesignator = "L";
                                                                                                                                    elseif((-16 > Lat) && (Lat >= -24))
                                                                                                                                         LetterDesignator = "K";
                                                                                                                                            elseif((-24 > Lat) && (Lat >= -32))
                                                                                                                                                 LetterDesignator = "J";
                                                                                                                                                    elseif((-32 > Lat) && (Lat >= -40)) 
                                                                                                                                                        LetterDesignator = "H";
                                                                                                                                                            elseif((-40 > Lat) && (Lat >= -48)) 
                                                                                                                                                                LetterDesignator = "G";
                                                                                                                                                                    elseif((-48 > Lat) && (Lat >= -56))
                                                                                                                                                                         LetterDesignator = "F";
                                                                                                                                                                            elseif((-56 > Lat) && (Lat >= -64)) 
                                                                                                                                                                                LetterDesignator = "E";
                                                                                                                                                                                    elseif((-64 > Lat) && (Lat >= -72))
                                                                                                                                                                                         LetterDesignator = "D";
                                                                                                                                                                                            elseif((-72 > Lat) && (Lat >= -80)) 
                                                                                                                                                                                                LetterDesignator = "C";
                                                                                                                                                                                                    else
                                                                                                                                                                                                                 LetterDesignator = "Z"; //This is here as an error flag to show that the Latitude is outside the UTM limits
                                                                                                                                                                                                                    endif
                                                                                                                                                                                                                        return LetterDesignator;
}
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


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Geographic Coordinates
    const double latitude_degrees  = 39.5;
    const double longitude_degrees = -119.5;


    // Compute the Recommended UTM Grid Zone
    int grid_zone = Compute_UTM_Grid_Zone(longitude_degrees);

    return 0;
}

