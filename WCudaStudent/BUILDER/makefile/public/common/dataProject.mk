# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __CUDA_DATA_PROJECT_PUBLIC_MK__
__CUDA_DATA_PROJECT_PUBLIC_MK__=true

###############################################
#  			DataProject						  #
###############################################

SRC_AUX+=

# Define Path where target will be build (.o .lib .exe ...)
#	Mimimum : Comment the ligne! Default value will be used.
#	Tip		: In server Cuda1 and Cuda2, default value is Ram disk.
#	Tip     : Use target to use a local directory at the root your project

#TARGET_PATH_ROOT:=target#local

#	Tip     : define if traget will be copied after build
#	Mimimum : empty
IS_DEPLOY=true

ifndef TARGET_DEPLOY_PATH
	TARGET_DEPLOY_PATH:=../RELEASE
	TARGET_DEPLOY_PATH_BIN=${TARGET_DEPLOY_PATH}/bin
else	
	TARGET_DEPLOY_PATH_BIN=${TARGET_DEPLOY_PATH}
endif

###############################################
#  					End						  #
###############################################

endif#__CUDA_DATA_PROJECT_PUBLIC_MK__