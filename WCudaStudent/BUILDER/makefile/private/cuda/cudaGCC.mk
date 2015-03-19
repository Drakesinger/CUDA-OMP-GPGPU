# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __CUDA_GCC_MK__
__CUDA_GCC_MK__=true

###############################################
#  			Cuda GCC Linux					  #
###############################################

########################
#   	pivate		   #
########################

COMPILATEUR:=g++

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/commonLinux.mk

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/api.mk # avant filset

include ${ROOT_MAKEFILE_PUBLIC_CUDA}/cudaGCC.mk
-include cudaLinux.mk#mk a la racine du projet, optionel

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/makeCudaGCC.mk

###############################################
#  					End						  #
###############################################

endif#__CUDA_GCC_MK__
