# Version 	: 0.0.7
# Date		: 04.03.2014
# Author 	: Cedric.Bilat@he-arc.ch

ifndef __NAME_MK__
__NAME_MK__=true

##################################################
# 				install							 #
##################################################

##############
#TARGET_NAME #
##############

ifneq ($(ARCH),arm)
   TARGET_NAME:=${TARGET_NAME}_$(NAME_COMPILATEUR)_$(ARCHI_32_64)
else
   TARGET_NAME:=$(TARGET_NAME)_$(NAME_COMPILATEUR)_$(PLATFORME)_$(ARCHI_32_64)
endif

##################################################
# 				end							 #
##################################################

endif#__NAME_MK__


