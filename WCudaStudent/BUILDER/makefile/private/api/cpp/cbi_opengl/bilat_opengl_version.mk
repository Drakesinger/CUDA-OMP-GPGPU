# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_OPENGL_VERSION_MK__
__API_BILAT_OPENGL_VERSION_MK__=true

##########################################
#   		Bilat PATH			 #
##########################################

#dependance
include ${API}/bilat_api_version.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_OPENGL_VERSION:=$(BILAT_API_VERSION)#
	BILAT_OPEN_GL_PATH:=${BILAT_OPENGL_HOME}/${BILAT_OPENGL_VERSION}#

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_OPENGL_VERSION:=$(BILAT_API_VERSION)#
	BILAT_OPEN_GL_PATH:=${BILAT_OPENGL_HOME}/${BILAT_OPENGL_VERSION}#

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_OPENGL_VERSION_MK__

