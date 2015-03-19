# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_GRAPH2D_VERSION_MK__
__API_BILAT_GRAPH2D_VERSION_MK__=true

##########################################
#   		Bilat PATH			 #
##########################################

#dependance
include ${API}/bilat_api_version.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_GRAPH2D_VERSION:=$(BILAT_API_VERSION)#
	BILAT_GRAPH2D_PATH:=${BILAT_GRAPH2D_HOME}/${BILAT_GRAPH2D_VERSION}#

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_GRAPH2D_VERSION:=$(BILAT_API_VERSION)#
	BILAT_GRAPH2D_PATH:=${BILAT_GRAPH2D_HOME}/${BILAT_GRAPH2D_VERSION}#

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_GRAPH2D_VERSION_MK__

