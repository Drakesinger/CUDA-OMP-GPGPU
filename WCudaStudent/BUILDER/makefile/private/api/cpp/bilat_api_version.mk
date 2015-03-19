# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_VERSION_MK__
__API_BILAT_VERSION_MK__=true

##########################################
#   		Bilat PATH			 #
##########################################



#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

	BILAT_API_VERSION:=002

endif

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

	BILAT_API_VERSION:=002

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_VERSION_MK__

