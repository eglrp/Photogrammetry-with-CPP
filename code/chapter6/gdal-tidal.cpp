/**
 * @file    gdal-tidal.cpp
 * @author  Marvin Smith
 * @date    11/21/2016
 *
 * @brief  Sample Code Using GDAL to manipulate Tidal Data
*/

#include <gdal.h>
#include <gdal_priv.h>

#include <iomanip>
#include <iostream>
#include <string>

void Adjust_Lon( double& lon )
{
    while( lon > 180 ){
        lon = lon - 360;
    }
}


void Transform_Pixel( const double& in_x,
                      const double& in_y,
                      const double  geo_transform[6],
                      double&       pixel_x,
                      double&       pixel_y )
{
    pixel_x = geo_transform[0] + geo_transform[1] * in_x + geo_transform[2] * in_y;
    pixel_y = geo_transform[3] + geo_transform[4] * in_x + geo_transform[5] * in_y;
}




int main( int argc, char* argv[] )
{
    // Define Parameters for Alcatraz Boat Dock
    const double target_lat_deg = 37.826979;
    const double target_lon_deg = -122.420920;

    // File to parse
    std::string gtx_path = "/home/msmith/Desktop/CAsanfrb12_8301/mllw.gtx";
    if( argc > 1 ){
        gtx_path = argv[1];
    }

    // Register the driver
    GDALAllRegister();

	// load the dataset 
    GDALDataset* dataset = (GDALDataset*) GDALOpen( gtx_path.c_str(), GA_ReadOnly);
	
    // if dataset is null, then there was a problem
	if( dataset == NULL ){
        std::cout << "GDALOpen returned a null object." << std::endl;
		return 1;
	}
	
	// make sure we have pixel data inside the raster
	if( dataset->GetRasterCount() <= 0 ){
        std::cout << "File has no pixel data." << std::endl;
		return 1;
	}
	
	//extract the driver infomation
    GDALDriver* driver = dataset->GetDriver();

    
    // Grab transform info
    double geo_transform[6];
    if( dataset->GetGeoTransform( geo_transform ) != CE_None )
    {
        std::cerr << "No Transform Data Provided." << std::endl;
        return 1;
    }
    

    // Raster Band Info
    std::cout << "Raster Count: " << dataset->GetRasterCount() << std::endl;
    std::cout << "Raster Rows : " << dataset->GetRasterYSize() << std::endl;
    std::cout << "Raster Cols : " << dataset->GetRasterXSize() << std::endl;
    std::cout << std::endl;

    int rows = dataset->GetRasterYSize();
    int cols = dataset->GetRasterXSize();

    // Corner Coordinates
    double tl_x, tl_y, tr_x, tr_y, bl_x, bl_y, br_x, br_y;

    Transform_Pixel(    0,    0, geo_transform, tl_x, tl_y ); 
    Transform_Pixel( cols,    0, geo_transform, tr_x, tr_y ); 
    Transform_Pixel(    0, rows, geo_transform, bl_x, bl_y ); 
    Transform_Pixel( cols, rows, geo_transform, br_x, br_y ); 

    Adjust_Lon( tl_x );
    Adjust_Lon( tr_x );
    Adjust_Lon( bl_x );
    Adjust_Lon( br_x );

    std::cout << "Coord: " << target_lat_deg << ", " << target_lon_deg << std::endl;
    std::cout << std::endl;
    std::cout << "TL   : " << tl_y << ", " << tl_x << std::endl;
    std::cout << "TR   : " << tr_y << ", " << tr_x << std::endl;
    std::cout << "BL   : " << bl_y << ", " << bl_x << std::endl;
    std::cout << "BR   : " << br_y << ", " << br_x << std::endl;

    double inv_transform[6];
    GDALInvGeoTransform( geo_transform, inv_transform );
    
    double px, py;
    Transform_Pixel( target_lon_deg + 360, target_lat_deg, inv_transform, px, py );
    std::cout << std::endl;
    std::cout << "Pix: " << px << ", " << py << std::endl;

    float tlv; 
    float* pafScanline = new float[cols];       
    dataset->GetRasterBand(1)->RasterIO( GF_Read, 0, (int)py,
                                         cols, 1, pafScanline, 
                                         cols, 1, GDT_Float32, 0, 0);
    
    tlv = pafScanline[(int)px];
    delete [] pafScanline;

    std::cout << "Value: " << std::fixed << std::setprecision(10) << tlv << std::endl;

    // Load the Driver
    GDALClose(dataset);
    
    
    // Return Success
    return 0;
}

