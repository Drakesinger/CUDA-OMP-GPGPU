# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_JNI_HIDDEN_MK__
__API_JNI_HIDDEN_MK__=true

##########################################
#   		jni				   			 #
##########################################

############
# commmon   #
############


API_INC+= $(subst ${SEPARATOR}, ,${JNI_INC})
API_LIB+= $(subst ${SEPARATOR}, ,${JNI_LIB}) 
#API_LIB_STATIC+= $(subst ${SEPARATOR}, ,${JNI_LIB_STATIC}) 
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${JNI_LIBRARIES}) 
#API_BIN+=  $(subst ${SEPARATOR}, ,${JNI_BIN}) 

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

#JAVA_HOME_64=C:/Soft/java64/jdk

#old deprecated
#ifeq  (${OS},Win)
	#PATH des Headers
	# Inputs :
	#		"Program" "File"
	# Outputs :
	#		"Program Files"
#	JAVA_HEADER_JNI := $(subst  Program Files,Program Files,$(JAVA_HEADER_JNI)) #correction de "Program" "Files" en "Program Files"
#endif
#SRC_AUX+= ${JAVA_HEADER_JNI}



 

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compilation
	#CXXFLAGS+= -I${JAVA_HOME_64}/include
	#CXXFLAGS+= -I${JAVA_HOME_64}/include/win32

	#linkage
	#SRC_AUX+=${JAVA_HOME_64}/lib
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#compilation
	#CXXFLAGS+= -I${JAVA_HOME_64}/include
	#CXXFLAGS+= -I${JAVA_HOME_64}/include/win32
	
	#linkage
	#rien
	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	#compilation
	#CXXFLAGS+= -I${JAVA_HOME_64}/include
	#CXXFLAGS+= -I${JAVA_HOME_64}/include/win32
	
	#linkage
	#rien
	
endif

endif



#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

#JAVA_HOME=/usr/lib/jvm/java-6-sun-1.6.0.26
#JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64

############
# common   #
############

	#compilation
	#CXXFLAGS+= -I$(subst :, -I,${JAVA_INC})

	#linkage
	#LDFLAGS+= -L$(subst :, -L,${JAVA_LIB})
	#LDFLAGS+= -l$(subst :, -l,${JAVA_LIBRARIES})

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
	#RPATH_LINK+=${JAVA_LIB}
endif

endif #end OS

##########################################
#   			 END 		   			 #
##########################################

endif#__API_JNI_HIDDEN_MK__

