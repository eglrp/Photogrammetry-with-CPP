#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    11/9/2015
#
#    Purpose: Construct the Photogrammetry-with-C++ Book
#


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
        chapter3/gdal-examples.tex
        ../code/common/Coordinate_Utilities.cpp
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
)



