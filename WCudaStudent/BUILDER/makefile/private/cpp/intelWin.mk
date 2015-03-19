# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#


ifndef __INTEL_WIN_MK__
__INTEL_WIN_MK__=true

###############################################
#  			Intel Win						  #
###############################################

########################
#   	bug		   #
########################

ARFLAGS=# pas= car valeur vaut rv avant sous windows ???

########################
#   	pivate		   #
########################

COMPILATEUR:=INTEL

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/commonWin.mk

include ${ROOT_MAKEFILE_PUBLIC_CPP}/intelWin.mk
-include intelWin.mk#optionel, dans path courant du project

include ${ROOT_MAKEFILE_PRIVATE_CPP}/api.mk # avant filset

include $(ROOT_MAKEFILE_PRIVATE_CPP)/fileSet.mk
include $(ROOT_MAKEFILE_PRIVATE_CPP)/flags_VisualIntel.mk
include $(ROOT_MAKEFILE_PRIVATE_CPP)/cpp.mk

###############################################
#  					End						  #
###############################################

endif#__INTEL_WIN_MK__
