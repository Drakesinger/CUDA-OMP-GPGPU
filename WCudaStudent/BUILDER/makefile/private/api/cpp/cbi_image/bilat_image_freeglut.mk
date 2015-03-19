# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_IMAGE_FREEGLUT_MK__
__API_BILAT_IMAGE_FREEGLUT_MK__=true

##########################################
#   		Bilat IMAGE FREEGLUT		 #
##########################################


#dependance
include $(API_BILAT_IMAGE)/bilat_image_gl.mk
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_freeglut_tools.mk

#path
BILAT_IMAGE_FREEGLUT_PATH=${BILAT_IMAGE_PATH}/${BILAT_IMAGE_FREEGLUT_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_IMAGE_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_PATH}/,${BILAT_IMAGE_FREEGLUT_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_IMAGE_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_PATH}/,${BILAT_IMAGE_FREEGLUT_LIB})  

#Runtime
API_BIN+= ${BILAT_IMAGE_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_PATH}/,${BILAT_IMAGE_FREEGLUT_BIN})


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

############
# ARM   #
############

ifeq  ($(ARCH),arm)
	#RPATH_LINK+=${API_ImageFreeGlut}/BIN/gcc
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BILAT_IMAGE_FREEGLUT_MK__

