# Version 	: 0.0.5
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_OPEN_CV_MK__
__API_OPEN_CV_MK__=true

##########################################
#   			 OpenCV		   			 #
##########################################

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# commmon   #
############

#version
OPENCV_VERSION=001

#path
OPENCV_PATH=${OPENCV_HOME}/${OPENCV_VERSION}

API_INC+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_INC})
API_LIB+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_LIB})  
API_BIN+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_BIN}) 
#API_LIB_STATIC+=

API_LIBRARIES+= $(subst ${SEPARATOR}, ,${OPENCV_LIBRARIES}) 
 
############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	##############
	#Version full
	##############
	
	#compil
	#SRC_AUX+= ${OPENCV64_INC} #ok
	#CXXFLAGS+= -I${OPENCV64_INC} #ko car sous folder

	#link
	#SRC_AUX+= ${OPENCV64_VISUAL_LIB}#ok
	#LDFLAGS_AUX+= /LIBPATH:${OPENCV64_VISUAL_LIB} #embettant il faut lister lib now -lxxx
	#LDFLAGS_AUX+= opencv_highgui244.lib
	#LDFLAGS_AUX+= opencv_core244.lib
	#LDFLAGS_AUX+= opencv_imgproc244.lib
	
	##############
	#Version light 
	##############
	
	#compilation ok
	#CXXFLAGS+= -I${OPENCV64_INC}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/highgui
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/core
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/flann
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/imgproc
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/video
	
	#CXXFLAGS+= -I$(subst ;, -I,${OPENCV_INC})

	#link ok : 
	#LDFLAGS_AUX+=  /LIBPATH:${OPENCV64_VISUAL_LIB_STATIC} #ko
	#LDFLAGS_AUX+=  /LIBPATH:${OPENCV_LIB} #ok
	#v1 : ko
	#SRC_AUX+= ${OPENCV64_VISUAL_LIB}
	#v2 : ok
	#ADD_LIBRARY_FILES+= opencv_highgui249.lib  
	#ADD_LIBRARY_FILES+= opencv_core249.lib
	#ADD_LIBRARY_FILES+= opencv_imgproc249.lib
	
	#ADD_LIBRARY_FILES+= $(subst ;, ,${OPENCV_LIBRARIES}) 
	
	#runtime
	#API_BIN+= ${OPENCV_BIN}
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#todo
	
	##############
	#Version full
	##############
	
	#compil
	#SRC_AUX+= ${OPENCV64_INC}#ok
	#CXXFLAGS+= -I${OPENCV64_INC} #ko car sous folder

	#link
	#SRC_AUX+= ${OPENCV64_VISUAL_LIB}#ok
	#LDFLAGS+= /LIBPATH:${OPENCV64_VISUAL_LIB} #embettant il faut lister lib now -lxxx
	
	##############
	#Version light 
	##############
	
	#compilation ok
	#CXXFLAGS+= -I${OPENCV64_INC}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/highgui
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/core
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/flann
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/imgproc
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/video
	
	#CXXFLAGS+= -I$(subst ;, -I,${OPENCV_INC})

	#link ok: 
	#LDFLAGS_AUX+=  /LIBPATH:${OPENCV_LIB} #il faut lister lib now
	#v1 : ko
	#SRC_AUX+= ${OPENCV64_VISUAL_LIB}
	#v2: ok
	#ADD_LIBRARY_FILES+= opencv_highgui249.lib 
	#ADD_LIBRARY_FILES+= opencv_core249.lib
	#ADD_LIBRARY_FILES+= opencv_imgproc249.lib
	
	#ADD_LIBRARY_FILES+= $(subst ;, ,${OPENCV_LIBRARIES}) 
	
	#runtime
	#API_BIN+= ${OPENCV_BIN}
	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	#compil : ok
	#SRC_AUX+= ${OPENCV64_INC}#ok
	#CXXFLAGS+= -I${OPENCV64_INC}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/highgui
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/core
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/flann
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/imgproc
	#CXXFLAGS+= -I${OPENCV64_INC_CV2}/video
	
	#CXXFLAGS+= -I$(subst ;, -I,${OPENCV_INC})

	#link : ok
	#SRC_AUX+= ${OPENCV64_MINGW_BIN}#ko
	#LDFLAGS+= -L${OPENCV64_MINGW_LIB_STATIC} #ko existe pas
	#LDFLAGS+= -L${OPENCV64_MINGW_LIB} #il faut lister lib now -lxxx
	
	#LDFLAGS+= -L${OPENCV_LIB} #il faut lister lib now -lxxx
	
	#LDFLAGS+= -lopencv_highgui249 
	#LDFLAGS+= -lopencv_core249 
	#LDFLAGS+= -lopencv_imgproc249
	
	#LDFLAGS+= -l$(subst ;, -l,${OPENCV_LIBRARIES}) 
	
	#runtime
	#API_BIN+= ${OPENCV_BIN}
	 
endif

endif#win


#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# common   #
############

#version
OPENCV_VERSION=001

#path
OPENCV_PATH=${OPENCV_HOME}/${OPENCV_VERSION}

API_INC+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_INC})
API_LIB+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_LIB})
API_BIN+= ${OPENCV_PATH}/$(subst ${SEPARATOR}, ${OPENCV_PATH}/,${OPENCV_LIB}) 
#API_LIB_STATIC+= 

API_LIBRARIES+= $(subst ${SEPARATOR}, ,${OPENCV_LIBRARIES}) 


#ifdef OPENCV_INC
	#compilation
	#CXXFLAGS+= -I$(subst :, -I,${OPENCV_INC})
#	API_INC+= ${OPENCV_INC}
#endif

#ifdef OPENCV_LIBRARIES
	#linkage
	#LDFLAGS+= -l$(subst :, -l,${OPENCV_LIBRARIES}) 
	#API_LIBRARIES+= ${OPENCV_LIBRARIES}
#endif

#ifdef OPENCV_LIB
	#linkage
	#LDFLAGS+= -L$(subst :, -L,${OPENCV_LIB})
#	API_LIB+= ${OPENCV_LIB}
#endif
	
	#execution
	#API_BIN+= ${OPENCV_LIBRARIES}

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
	RPATH_LINK+=${OPENCV_RPATH_LINK}
endif

endif#end os

##########################################
#   			 END 		   			 #
##########################################

endif#__API_OPEN_CV_MK__
