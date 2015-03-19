# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_FENETRAGE_FREEGLUT_TOOLS_MK__
__API_BILAT_FENETRAGE_FREEGLUT_TOOLS_MK__=true

##########################################
#   		Bilat FREEGLUT TOOLS     	 #
##########################################

#dependance
include ${API}/freeGlut.mk
include $(API)/openmp.mk
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_displayable.mk

#path
BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH=${BILAT_FENETRAGE_PATH}/${BILAT_FENETRAGE_FREEGLUT_TOOLS_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/$(subst ;, ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/,${BILAT_FENETRAGE_FREEGLUT_TOOLS_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/$(subst ;, ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/,${BILAT_FENETRAGE_FREEGLUT_TOOLS_LIB})  

#Runtime
API_BIN+= ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/$(subst ;, ${BILAT_FENETRAGE_FREEGLUT_TOOLS_PATH}/,${BILAT_FENETRAGE_FREEGLUT_TOOLS_BIN})

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

endif#__API_BILAT_FENETRAGE_FREEGLUT_TOOLS_MK__

