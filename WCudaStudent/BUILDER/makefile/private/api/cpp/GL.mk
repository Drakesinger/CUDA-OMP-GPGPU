# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_GL_MK__
__API_GL_MK__=true

##########################################
#   		GL				   			 #
##########################################

#API_GL=../API_GL

#dependance
include ${API}/X11.mk

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# commmon   #
############

#version
GL_VERSION=001

#path
GL_PATH=${GL_HOME}/${GL_VERSION}

API_INC+= ${GL_PATH}/$(subst ;,  ${GL_PATH}/,${GL_INC})
API_LIB+= ${GL_PATH}/$(subst ;,  ${GL_PATH}/,${GL_LIB})  
#API_LIB_STATIC+=
API_LIBRARIES+= $(subst ;, ,${GL_LIBRARIES}) 
API_BIN+= ${GL_PATH}/$(subst ;,  ${GL_PATH}/,${GL_BIN})  

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${GL_INC})

	#link
	#LDFLAGS_AUX+= /LIBPATH:${GL_LIB} #ok
	
	#ADD_LIBRARY_FILES+= $(subst ;, ,${GL_LIBRARIES}) 
	
	#ADD_LIBRARY_FILES+= glew64.lib  
	
	#api system		
	#ADD_LIBRARY_FILES+= kernel32.lib  
	#ADD_LIBRARY_FILES+= gdi32.lib
	#ADD_LIBRARY_FILES+= user32.lib
	#ADD_LIBRARY_FILES+= opengl32.lib
	#ADD_LIBRARY_FILES+= glu32.lib
	
	#runtime
	#API_BIN+= ${GL_BIN}
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${GL_INC})

	#link
	#LDFLAGS_AUX+= /LIBPATH:${GL_LIB} #ok
	
	#ADD_LIBRARY_FILES+= $(subst ;, ,${GL_LIBRARIES}) 
		
	#ADD_LIBRARY_FILES+= glew64.lib  	
	
	#api system	
	#ADD_LIBRARY_FILES+= kernel32.lib  
	#ADD_LIBRARY_FILES+= gdi32.lib
	#ADD_LIBRARY_FILES+= user32.lib
	#ADD_LIBRARY_FILES+= opengl32.lib
	#ADD_LIBRARY_FILES+= glu32.lib
	
	#runtime
	#API_BIN+= ${GL_BIN}

endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	#compilation
	#CXXFLAGS+= -I$(subst ;, -I,${GL_INC})
	
	#link
	#LDFLAGS+= -L$(subst ;, -L,${GL_LIB})
	
	#LDFLAGS+= -l$(subst ;, -l,${GL_LIBRARIES}) 
	
	#LDFLAGS+= -llibglew64dll 
	
	#api system	
	#LDFLAGS+= -lkernel32 
	#LDFLAGS+= -lgdi32
	#LDFLAGS+= -luser32
	#LDFLAGS+= -lopengl32
	#LDFLAGS+= -lglu32

	#runtime
	#API_BIN+= ${GL_BIN}
	
endif

endif#win



#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# common   #
############

#LDFLAGS+= -l$(subst :, -l,${GL_LIBRARIES})
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${GL_LIBRARIES}) 

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
	#CXXFLAGS+= -I$(subst :, -I,${GL_INC})
	#LDFLAGS+= -L$(subst :, -L,${GL_LIB})
	
	#compilation
	API_INC+= $(subst ${SEPARATOR}, ,${GL_INC})
	
	#linkage
	API_LIB+= $(subst ${SEPARATOR}, ,${GL_LIB})
	
	#RPATH_LINK+=${GL_LIB}
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_GL_MK__

