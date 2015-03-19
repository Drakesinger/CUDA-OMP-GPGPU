# Version 	: 0.0.6
# Date		: 20.01.2014
# Author 	: Cedric.Bilat@he-arc.ch

ifndef __CUDA_GCC_ARM_MK_PUBLIC__
__CUDA_GCC_ARM_MK_PUBLIC__=true

##############################################
#   			 Variables     				 #
##############################################

########
#arm #
########

ifeq (${ARCH},arm)	

	#Deploment data
	JETSON_IP:=157.26.100.60
	JETSON_USER:=ubuntu
	JETSON_BIN:=/home/ubuntu/HEARC/bin

	ifeq (${PLATFORME},kayla)	 
		PLATFORME_IP:=${KAYLA_IP}
		PLATFORME_BIN:=${KAYLA_BIN}
		PLATFORME_USER:=${KAYLA_USER}
	else ifeq ($(PLATFORME),jetson) 
		PLATFORME_IP:=${JETSON_IP}
		PLATFORME_BIN:=${JETSON_BIN}
		PLATFORME_USER:=${JETSON_USER}
	endif

endif


endif#__OCUDA_GCC_ARM_MK__

