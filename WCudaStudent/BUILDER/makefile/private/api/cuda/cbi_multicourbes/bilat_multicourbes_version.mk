# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_MULTICOURBES_CUDA_VERSION_MK__
__API_BILAT_MULTICOURBES_CUDA_VERSION_MK__=true

##########################################
#   		Bilat PATH			 #
##########################################

#dependance
include ${API}/bilat_api_version.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_MULTICOURBES_CUDA_VERSION:=${BILAT_API_VERSION}#
	BILAT_MULTICOURBES_CUDA_PATH:=${BILAT_MULTICOURBES_CUDA_HOME}/${BILAT_MULTICOURBES_CUDA_VERSION}#

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_MULTICOURBES_CUDA_VERSION:=${BILAT_API_VERSION}#
	BILAT_MULTICOURBES_CUDA_PATH:=${BILAT_MULTICOURBES_CUDA_HOME}/${BILAT_MULTICOURBES_CUDA_VERSION}#

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_MULTICOURBES_CUDA_VERSION_MK__

