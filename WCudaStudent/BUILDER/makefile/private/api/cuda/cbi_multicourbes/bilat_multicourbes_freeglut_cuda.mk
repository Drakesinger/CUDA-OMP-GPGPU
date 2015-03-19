# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BILAT_MULTICOURBES_GL_FREEGLUT_MK__
__API_BILAT_MULTICOURBES_GL_FREEGLUT_MK__=true

##########################################
#   		Bilat CUDA MULTICOURBES 	 #
##########################################


#dependance
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_freeglut_tools.mk
include $(API_BILAT_MULTICOURBES_CUDA)/bilat_multicourbes_gl_cuda.mk

#path
BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH=${BILAT_MULTICOURBES_CUDA_PATH}/${BILAT_MULITCOURBES_FREEGLUT_CUDA_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/,${BILAT_MULITCOURBES_FREEGLUT_CUDA_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/,${BILAT_MULITCOURBES_FREEGLUT_CUDA_LIB})  

#Runtime
API_BIN+= ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/$(subst ${SEPARATOR}, ${BILAT_MULITCOURBES_FREEGLUT_CUDA_PATH}/,${BILAT_MULITCOURBES_FREEGLUT_CUDA_BIN})

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

endif#__API_BILAT_MULTICOURBES_GL_FREEGLUT_MK__
