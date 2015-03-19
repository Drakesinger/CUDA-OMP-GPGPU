# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_FREEGLUT_MK__
__API_FREEGLUT_MK__=true

##########################################
#   		FREEGLUT		   			 #
##########################################

#dependance
include ${API}/GL.mk

#API_FreeGlut=../API_FreeGlut

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# commmon   #
############

FREEGLUT_VERSION=001
FREEGLUT_PATH=${FREEGLUT_HOME}/${FREEGLUT_VERSION}

API_INC+= ${FREEGLUT_PATH}/$(subst ;, ${FREEGLUT_PATH}/,${FREEGLUT_INC})
API_LIB+= ${FREEGLUT_PATH}/$(subst ;, ${FREEGLUT_PATH}/,${FREEGLUT_LIB})  
#API_LIB_STATIC+=
API_LIBRARIES+= $(subst ;, ,${FREEGLUT_LIBRARIES}) 
API_BIN+= ${FREEGLUT_PATH}/$(subst ;, ${FREEGLUT_PATH}/,${FREEGLUT_BIN})  

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${FREEGLUT_INC})

	#link
	#LDFLAGS_AUX+= /LIBPATH:${FREEGLUT_LIB}
		
	#ADD_LIBRARY_FILES+= freeglut64.lib  
	#ADD_LIBRARY_FILES+= $(subst ;, ,${FREEGLUT_LIBRARIES}) 

	#runtime
	#API_BIN+= ${FREEGLUT_BIN}
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${FREEGLUT_INC})

	#link
	#LDFLAGS_AUX+= /LIBPATH:${FREEGLUT_LIB}
		
	#ADD_LIBRARY_FILES+= freeglut64.lib  
	#ADD_LIBRARY_FILES+= $(subst ;, ,${FREEGLUT_LIBRARIES}) 

	#runtime
	#API_BIN+= ${FREEGLUT_BIN}
	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${FREEGLUT_INC})
	
	#link
	#LDFLAGS+= -L$(subst ;, -L,${FREEGLUT_LIB})
	
	#LDFLAGS+= -lfreeglut64dll 
	#LDFLAGS+= -l$(subst ;, -l,${FREEGLUT_LIBRARIES}) 

	#runtime
	#API_BIN+= ${FREEGLUT_BIN}
	
endif

endif#win



#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# common   #
############

#link
LDFLAGS+= -l$(subst :, -l,${FREEGLUT_LIBRARIES}) 

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
	CXXFLAGS+= -I$(subst :, -I,${FREEGLUT_INC})
	LDFLAGS+= -L$(subst :, -L,${FREEGLUT_LIB})
	
	#RPATH_LINK+=${FREEGLUT_LIB}
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_FREEGLUT_MK__


