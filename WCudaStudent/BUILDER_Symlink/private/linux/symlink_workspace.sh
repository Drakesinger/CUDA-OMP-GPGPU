#!/bin/bash
#
# version	: 0.0.1
# author	: cedric.bilat@he-arc.ch


# ---------------------------------------
#		Init
#----------------------------------------

set -e

# ../.. accede root workpsace
pushd ..

source ./linux/symlink_tools.sh


# ---------------------------------------
#		Destination
#----------------------------------------

DESTINATION=../INC
DESTINATION_CUDA=../INC_CUDA

purgeSymlink $DESTINATION
purgeSymlink $DESTINATION_CUDA

# ---------------------------------------
#		List Projets
#----------------------------------------

source ../public/symlink_data.sh

# ---------------------------------------
#		Main
#----------------------------------------

for projeti in $listProjet
	do
		SOURCE=../../$projeti/src/core
		symlinkInc $SOURCE $DESTINATION
	done
	
for projeti in $listProjetCuda
	do
		SOURCE=../../$projeti/src/core
		symlinkInc $SOURCE $DESTINATION_CUDA
	done

popd

# ---------------------------------------
#		end
#----------------------------------------
