# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#


ifndef __API_BILAT_GRAPH2D_GL_MK__
__API_BILAT_GRAPH2D_GL_MK__=true

##########################################
#   		BilatGraph		   			 #
##########################################

#dependance
include ${API_BILAT_GRAPH2D}/bilat_graph2d_version.mk
include ${API_BILAT_FENETRAGE}/bilat_fenetrage_displayable.mk
include ${API_BILAT_OPENGL}/bilat_opengl_tools.mk

#path
BILAT_GRAPH2D_GL_PATH=${BILAT_GRAPH2D_PATH}/${BILAT_GRAPH2D_GL_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+= CBI_GRAPH_DLL
API_INC+= ${BILAT_GRAPH2D_GL_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_GL_PATH}/,${BILAT_GRAPH2D_GL_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_GRAPH2D_GL_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_GL_PATH}/,${BILAT_GRAPH2D_GL_LIB})  

#Runtime
API_BIN+= ${BILAT_GRAPH2D_GL_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_GL_PATH}/,${BILAT_GRAPH2D_GL_BIN})

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

endif#__API_BILAT_GRAPH2D_GL_MK__
