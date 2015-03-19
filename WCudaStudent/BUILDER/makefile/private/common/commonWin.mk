# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __COMMON_WIN_MK__
__COMMON_WIN_MK__=true

###############################################
#  					common win				  #
###############################################

OS:=Win
USER=${USERNAME}
SEPARATOR:=;#

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/common.mk

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/dataProjectWin.mk

###############################################
#  					End						  #
###############################################

endif#__COMMON_WIN_MK__
