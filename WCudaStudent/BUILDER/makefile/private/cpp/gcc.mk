# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les definitions de variables ci-dessous, mefiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apres le += de surcharge : exemple : xxx+= yyyy
#

ifndef __GCC_MK__
__GCC_MK__=true

###############################################
#  					GCC						  #
###############################################

########################
#   	bug		   #
########################

ARFLAGS=# pas= car valeur vaut rv avant sous windows ???

########################
#   	pivate		   #
########################

COMPILATEUR:=g++

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/commonLinux.mk

include ${ROOT_MAKEFILE_PUBLIC_CPP}/gcc.mk
-include gcc.mk#optionel, dans path courant du project

include ${ROOT_MAKEFILE_PRIVATE_CPP}/api.mk # avant filset

include $(ROOT_MAKEFILE_PRIVATE_CPP)/fileSet.mk
include $(ROOT_MAKEFILE_PRIVATE_CPP)/flags_GccIntel.mk
include $(ROOT_MAKEFILE_PRIVATE_CPP)/cpp.mk

###############################################
#  					End						  #
###############################################

endif#__GCC_MK__