# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_DLLTOOLS_MK__
__API_BILAT_DLLTOOLS_MK__=true

##########################################
#   		Bilat DLL TOOLS	   			 #
##########################################

#dependance
include ${API_BILAT_TOOLS}/bilat_tools_version.mk

#path
BILAT_TOOLS_DLL_PATH=${BILAT_TOOLS_PATH}/${BILAT_TOOLS_DLL_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
API_INC+= ${BILAT_TOOLS_DLL_PATH}/$(subst ${SEPARATOR}, ${BILAT_TOOLS_DLL_PATH}/,${BILAT_TOOLS_DLL_INC})

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)
	#rien
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)
	#rien
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	#rien
endif

endif#win

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# ARM   #
############

ifeq  ($(ARCH),arm)
	ARM_FOLDER="_arm"
else
	ARM_FOLDER=#
endif

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)
	#rien
endif

############
# INTEL   #
############

ifeq  ($(COMPILATEUR),INTEL)
	#rien
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_DLLTOOLS_MK__
