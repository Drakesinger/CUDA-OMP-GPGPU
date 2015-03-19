# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_TOOLS_VERSION_MK__
__API_BILAT_TOOLS_VERSION_MK__=true

##########################################
#   		Bilat Fenetrage				 #
##########################################

#dependance
include ${API}/bilat_api_version.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_TOOLS_VERSION:=$(BILAT_API_VERSION)#
	BILAT_TOOLS_PATH:=${BILAT_TOOLS_HOME}/${BILAT_TOOLS_VERSION}#

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_TOOLS_VERSION:=$(BILAT_API_VERSION)#
	BILAT_TOOLS_PATH:=${BILAT_TOOLS_HOME}/${BILAT_TOOLS_VERSION}#

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_TOOLS_VERSION_MK__

