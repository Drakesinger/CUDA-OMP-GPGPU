# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __CUDA_VISUAL_MK__
__CUDA_VISUAL_MK__=true

###############################################
#  			Cuda Visual Win					  #
###############################################

########################
#   	pivate		   #
########################

COMPILATEUR:=VISUAL

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/commonWin.mk

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/api.mk # avant filset

include ${ROOT_MAKEFILE_PUBLIC_CUDA}/cudaVisual.mk
-include cudaVisual.mk#mk a la racine du projet, optionel

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/makeCudaVisual.mk

###############################################
#  					End						  #
###############################################

endif#__CUDA_VISUAL_MK__
