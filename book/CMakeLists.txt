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
)



