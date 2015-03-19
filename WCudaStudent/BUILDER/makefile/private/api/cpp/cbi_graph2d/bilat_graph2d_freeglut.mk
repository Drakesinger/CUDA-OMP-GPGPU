# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#


ifndef __API_BILAT_GRAPH2D_FREEGLUT_MK__
__API_BILAT_GRAPH2D_FREEGLUT_MK__=true

##########################################
#   		BilatGraph		   			 #
##########################################

#dependance
include ${API_BILAT_GRAPH2D}/bilat_graph2d_gl.mk
include $(API_BILAT_FENETRAGE)/bilat_fenetrage_freeglut_tools.mk

#path
BILAT_GRAPH2D_FREEGLUT_PATH=${BILAT_GRAPH2D_PATH}/${BILAT_GRAPH2D_FREEGLUT_HOME}

#########################
# 	COMMOM ALL OS		#
#########################

#compil
CODE_DEFINE_VARIABLES+=
API_INC+= ${BILAT_GRAPH2D_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_FREEGLUT_PATH}/,${BILAT_GRAPH2D_FREEGLUT_INC})

#Linkage
#Use SrcAux car nom lib complexe!
SRC_AUX+= ${BILAT_GRAPH2D_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_FREEGLUT_PATH}/,${BILAT_GRAPH2D_FREEGLUT_LIB})  

#Runtime
API_BIN+= ${BILAT_GRAPH2D_FREEGLUT_PATH}/$(subst ${SEPARATOR}, ${BILAT_GRAPH2D_FREEGLUT_PATH}/,${BILAT_GRAPH2D_FREEGLUT_BIN})

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

endif#__API_BILAT_GRAPH2D_FREEGLUT_MK__
