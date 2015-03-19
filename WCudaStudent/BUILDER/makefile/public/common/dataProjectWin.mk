# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __CUDA_DATA_PROJECT_PUBLIC_WIN_MK__
__CUDA_DATA_PROJECT_PUBLIC_LINUX_MK__=true

###############################################
#  			Windows							  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/dataProject.mk

ifndef TARGET_PATH_ROOT
	TARGET_PATH_ROOT:=Q:/${USER}/Targets
	#windows ramdrive
endif

TARGET_PATH:=${TARGET_PATH_ROOT}/${TARGET_NAME}

###############################################
#  					End						  #
###############################################

endif#__CUDA_DATA_PROJECT_PUBLIC_LINUX_MK__