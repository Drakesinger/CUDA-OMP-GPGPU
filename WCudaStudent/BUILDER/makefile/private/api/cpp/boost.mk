# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_BOOST_MK__
__API_BOOST_MK__=true

##########################################
#   			 Boost 		   			 #
##########################################


#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# common   #
############

#version
BOOST_VERSION=001

#path
BOOST_PATH=${BOOST_HOME}/${BOOST_VERSION}

API_INC+= ${BOOST_PATH}/$(subst ${SEPARATOR}, ${BOOST_PATH}/,${BOOST_INC})
#API_LIB+=
API_LIB_STATIC+= ${BOOST_PATH}/$(subst ${SEPARATOR}, ${BOOST_PATH}/,${BOOST_LIB_STATIC})
#API_LIBRARIES+= 
#API_BIN+=  

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compilation
	#CXXFLAGS+= -I${BOOST_INC}
	
	
	#link (link static lib)
	#LDFLAGS_AUX+=  /LIBPATH:${BOOST_LIB_STATIC}

	
	#runtime
	#API_BIN+= ${BOOST_BIN}
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#compilation
	#CXXFLAGS+= -I${BOOST_INC}

	#link (link static lib)
	#LDFLAGS_AUX+= /LIBPATH:${BOOST_LIB_STATIC}
	
	#runtime
	#API_BIN+= ${BOOST64_INTEL_BIN}
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	#compilation
  	#CXXFLAGS+= -I${BOOST_INC}
  
	#link (Link dynamic lib)
	#SRC_AUX+= $(subst ;, ,${BOOST_LIB_STATIC})#ok
	#LDFLAGS+= -L${BOOST64_MINGW_LIB} 
	
	#runtime
	#API_BIN+= ${BOOST64_MINGW_BIN}
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
BOOST_VERSION=001

#path
BOOST_PATH=${BOOST_HOME}/${BOOST_VERSION}

API_INC+= ${BOOST_PATH}/$(subst ${SEPARATOR}, ${BOOST_PATH}/,${BOOST_INC})
API_LIB+= ${BOOST_PATH}/$(subst ${SEPARATOR}, ${BOOST_PATH}/,${BOOST_LIB})
API_BIN+= ${BOOST_PATH}/$(subst ${SEPARATOR}, ${BOOST_PATH}/,${BOOST_LIB}) 

#API_LIB_STATIC+= 
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${BOOST_LIBRARIES}) 

############
# common   #
############

	#instalation : sudo apt-get install libboost-all-dev
	#LDFLAGS+= -L/usr/lib  

	#installtion manuel

	#compilation
	#CXXFLAGS+= -I$(subst :, -I,${BOOST_INC})
	#API_INC+= -I$(subst :, -I,${BOOST_INC})
	#API_INC+= ${BOOST_INC}

	#link
	#LDFLAGS+= -L$(subst :, -L,${BOOST_LIB})
	#LDFLAGS+= -l$(subst :, -l,${BOOST_LIBRARIES}) 
	
	#API_LIB+= -L$(subst :, -L,${BOOST_LIB})
	#API_LIB+= ${BOOST_LIB}
	#API_LIBRARIES+= -l$(subst :, -l,${BOOST_LIBRARIES}) 
	#API_LIBRARIES+= ${BOOST_LIBRARIES}
		
	#runtime
	#API_BIN+= ${BOOST_LIB}

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
	#RPATH_LINK+=${BOOST_LIB}
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_BOOST_MK__

