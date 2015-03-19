# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_IMAGE_CUDA_FREEGLUT_MK__
__API_BILAT_IMAGE_CUDA_FREEGLUT_MK__=true

##########################################
#   		Bilat CUDA IMAGE FREEGLUT	 #
##########################################


#dependance
include $(API_BILAT_IMAGE)/bilat_image_freeglut.mk
include $(API_BILAT_IMAGE_CUDA)/bilat_image_gl_cuda.mk

#path
BILAT_IMAGE_FREEGLUT_CUDA_PATH=${BILAT_IMAGE_PATH}/${BILAT_IMAGE_FREEGLUT_CUDA_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/,${BILAT_IMAGE_FREEGLUT_CUDA_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/,${BILAT_IMAGE_FREEGLUT_CUDA_LIB})  

#Runtime
API_BIN+= ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_IMAGE_FREEGLUT_CUDA_PATH}/,${BILAT_IMAGE_FREEGLUT_CUDA_BIN})

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

endif#__API_BILAT_IMAGE_CUDA_FREEGLUT_MK__
