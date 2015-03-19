# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#


ifndef __API_BILAT_OPENGL_TOOLS_MK__
__API_BILAT_OPENGL_TOOLS_MK__=true

##########################################
#   		Bilat GL	   			 #
##########################################


#dependance
include $(API_BILAT_TOOLS)/bilat_tools_dll.mk
include ${API_BILAT_OPENGL}/bilat_opengl_version.mk
include ${API}/GL.mk

#path
BILAT_OPENGL_TOOLS_PATH=${BILAT_OPEN_GL_PATH}/${BILAT_OPENGL_TOOLS_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_OPENGL_TOOLS_PATH}/$(subst ${SEPARATOR}, ${BILAT_OPENGL_TOOLS_PATH}/,${BILAT_OPENGL_TOOLS_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_OPENGL_TOOLS_PATH}/$(subst ${SEPARATOR}, ${BILAT_OPENGL_TOOLS_PATH}/,${BILAT_OPENGL_TOOLS_LIB})  

#Runtime
API_BIN+= ${BILAT_OPENGL_TOOLS_PATH}/$(subst ${SEPARATOR}, ${BILAT_OPENGL_TOOLS_PATH}/,${BILAT_OPENGL_TOOLS_BIN})

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

endif#__API_BILAT_OPENGL_TOOLS_MK__
