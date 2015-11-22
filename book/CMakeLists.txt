#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/9/2015
#
#    Purpose: Construct the Photogrammetry-with-C++ Book
#


#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR} )
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR} )


#---------------------------------------#
#-     Modify the Latex Output Path    -#
#---------------------------------------#
#set( LATEX_OUTPUT_PATH ${PROJECT_SOURCE_DIR} )

#----------------------------------#
#-     Define the Latex Files     -#
#----------------------------------#
set( BOOK_LATEX_FILES
        core/front_matter.tex
        core/structure.tex
        chapter1/overview.tex
        chapter1/spherical-vs-projected.tex
        chapter1/gis-data-formats.tex
        chapter2/overview.tex
        chapter2/gdal-overview.tex
        chapter2/geographiclib-overview.tex
        chapter3/overview.tex
        chapter3/coordinate-conversions.tex
        chapter3/distance-measurements.tex
        chapter3/liblas-examples.tex
        chapter4/overview.tex
        chapter5/overview.tex
        chapter6/overview.tex
        chapter6/geographiclib-geoid.tex
        appendix-A/overview.tex
        appendix-A/Coordinate-Lookup-Table.tex
        ../code/chapter3/gdal-geographic-to-utm.cpp
        ../code/chapter3/geographiclib-ellipsoid-distance.cpp
        ../code/chapter3/great-circle-distance.cpp
        ../code/chapter3/mgrs_to_utm.cpp
        ../code/chapter6/geographiclib-magnetic-query.cpp
        ../code/common/Coordinate_Utilities.cpp
        ../data/Coordinate-Lookup-Table.csv
)



#----------------------------------------------#
#-        Define the Bibliography Files       -#
#----------------------------------------------#
set( BOOK_BIB_FILES
     core/bibliography.bib
)


#--------------------------------------------#
#-     Define the Book Image File List      -#
#--------------------------------------------#
set( BOOK_IMAGE_FILES
     chapter1/diagrams/figure_1_1.png
     chapter1/diagrams/figure_1_2.png
)


#--------------------------------------#
#-     Set the Desired Book Format    -#
#--------------------------------------#
set( BOOK_OUTPUT_FORMAT FORCE_PDF )

#-----------------------------------#
#-     Build the Latex Document    -#
#-----------------------------------#
add_latex_document( photogrammetry-with-cpp.tex
                        INPUTS
                            ${BOOK_LATEX_FILES}
                        ${BOOK_OUTPUT_FORMAT}
                        TARGET_NAME
                            photogrammetry-with-cpp
                        IMAGES
                            ${BOOK_IMAGE_FILES}
                        BIBFILES
                            ${BOOK_BIB_FILES}
                        USE_INDEX
                        USE_GLOSSARY
)



