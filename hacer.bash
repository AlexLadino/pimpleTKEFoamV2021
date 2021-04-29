#!/bin/sh
cd ${0%/*} || exit 1    # Run from this directory


# Solve a given case with different TURBULENCE MODELS

# Source tutorial run functions
. $WM_PROJECT_DIR/bin/tools/RunFunctions

wclean

rm /home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/bin/$1

wmake