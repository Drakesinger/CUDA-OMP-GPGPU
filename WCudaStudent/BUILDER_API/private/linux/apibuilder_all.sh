#!/bin/bash
#
# Version:	0.0.2
#

set -e

#------------------------------------------------------------------------------------
#		input
#------------------------------------------------------------------------------------

#rien

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

#cbirt pour recuperer uniquemnet variable path

pushd ../common

cbirt ./apibuilder_all.sh 

popd

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------


