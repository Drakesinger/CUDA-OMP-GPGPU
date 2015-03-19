# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_FENETRAGE_VERSION_MK__
__API_BILAT_FENETRAGE_VERSION_MK__=true

##########################################
#   		Bilat Fenetrage				 #
##########################################

#dependance
include ${API}/bilat_api_version.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_FENETRAGE_VERSION:=$(BILAT_API_VERSION)#
	BILAT_FENETRAGE_PATH:=${BILAT_FENETRAGE_HOME}/${BILAT_FENETRAGE_VERSION}#

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_FENETRAGE_VERSION:=$(BILAT_API_VERSION)#
	BILAT_FENETRAGE_PATH:=${BILAT_FENETRAGE_HOME}/${BILAT_FENETRAGE_VERSION}#

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_FENETRAGE_VERSION_MK__

