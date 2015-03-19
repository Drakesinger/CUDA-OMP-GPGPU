# Version 	: 0.0.4
# Author 	: vincent.grivel@master.hes-so.ch
#

ifndef __API_X11_MK__
__API_X11_MK__=true

##########################################
#   		X11 			   			 #
##########################################

#linux only!

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# common   #
############

#compilation
API_INC+= $(subst ${SEPARATOR}, ,${X11_INC})

#linkage
API_LIB+= $(subst ${SEPARATOR}, ,${X11_LIB})
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${X11_LIBRARIES}) 
#LDFLAGS+= -l$(subst :, -l,${X11_LIBRARIES}) 

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)

	#compilation
	#CXXFLAGS+= -I/usr/include/X11
	#CXXFLAGS+= -I$(subst :, -I,${X11_INC})
	#API_INC+= $(subst ${SEPARATOR}, ,${X11_INC})

	#linkage
	#LDFLAGS+= -L/usr/lib/x86_64-linux-gnu
	#LDFLAGS+= -lX11 
	
	#ifdef X11_LIB
	#LDFLAGS+= -L$(subst :, -L,${X11_LIB})
	#endif
	
	#API_LIB+= $(subst ${SEPARATOR}, ,${X11_LIB})
	
endif

############
# INTEL   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#compilation
	#CXXFLAGS+= -I/usr/include/X11
	#CXXFLAGS+= -I$(subst :, -I,${X11_INC})

	#linkage
	#LDFLAGS+= -L/usr/lib/x86_64-linux-gnu
	#LDFLAGS+= -lX11 
	
	#ifdef X11_LIB
	#LDFLAGS+= -L$(subst :, -L,${X11_LIB})
	#endif
	
endif

############
# ARM   #
############

ifeq  ($(ARCH),arm)
	#RPATH_LINK+=${X11_LIB}
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_X11_MK__

