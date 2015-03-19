# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#


ifndef __API_BILAT_IMAGE_GL_MK__
__API_BILAT_IMAGE_GL_MK__=true

##########################################
#   		BilatGLImage	   			 #
##########################################


#dependance
include $(API)/openmp.mk
include $(API)/GL.mk
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_displayable.mk
include ${API_BILAT_IMAGE}/bilat_image_version.mk

#path
BILAT_IMAGE_GL_PATH=${BILAT_IMAGE_PATH}/${BILAT_IMAGE_GL_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_IMAGE_GL_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_GL_PATH}/,${BILAT_IMAGE_GL_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_IMAGE_GL_PATH}/$(subst ${SEPARATOR}, ${${BILAT_IMAGE_GL_PATH}/,${BILAT_IMAGE_GL_LIB})  

#Runtime
API_BIN+= ${BILAT_IMAGE_GL_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_GL_PATH}/,${BILAT_IMAGE_GL_BIN})

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

endif#__API_BILAT_IMAGE_GL_MK__

