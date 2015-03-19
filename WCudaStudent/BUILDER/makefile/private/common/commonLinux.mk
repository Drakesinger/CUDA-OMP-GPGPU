# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __COMMON_LINUX_MK__
__COMMON_LINUX_MK__=true

###############################################
#  		COMMON LINUX						  #
###############################################

OS:=Linux
SEPARATOR:=:#

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/common.mk

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/dataProjectLinux.mk

###############################################
#  					End						  #
###############################################

endif#__COMMON_LINUX_MK__
