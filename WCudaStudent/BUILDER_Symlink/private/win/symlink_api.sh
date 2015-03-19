#!/bin/bash
#
# version	: 0.0.1
# author	: cedric.bilat@he-arc.ch


# ---------------------------------------
#		Init
#----------------------------------------

set -e
source ../linux/symlink_tools.sh

# ---------------------------------------
#		Destination
#----------------------------------------

SOFT_API=/C/Soft_API
API_EXT=${SOFT_API}/ext
API_CBI=${SOFT_API}/cbi

DESTINATION_API_CBI=${SOFT_API}/SYMLINK/INC
DESTINATION_API_EXT=${SOFT_API}/SYMLINK/INC

purgeSymlink $DESTINATION_API_CBI
#purgeSymlink $DESTINATION_API_EXT

# ---------------------------------------
#		api cbi
#----------------------------------------

SOURCE=$API_CBI
VERSION=002

symlinkIncVersion $SOURCE $VERSION $DESTINATION_API_CBI

# ---------------------------------------
#		api ext
#----------------------------------------

# -------------
# boost
#--------------

SOURCE=${API_EXT}/Boost
VERSION=001

symlinkIncVersion $SOURCE $VERSION $DESTINATION_API_EXT

# -------------
# cpptest
#--------------

SOURCE=${API_EXT}/cpptest
VERSION=001

symlinkIncVersion $SOURCE $VERSION $DESTINATION_API_EXT

# -------------
# opencv
#--------------

SOURCE=${API_EXT}/openCV
VERSION=001

symlinkIncVersion $SOURCE $VERSION $DESTINATION_API_EXT

# ---------------------------------------
#		end
#----------------------------------------
