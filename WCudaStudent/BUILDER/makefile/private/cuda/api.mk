# Version 	: 0.0.5
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_ALL_CUDA_MK__
__API_ALL_CUDA_MK__=true

##########################################
#   			 API CUDA	   			 #
##########################################

#remove space
override API_INC:=$(strip ${API_INC})
override API_LIB:=$(strip ${API_LIB})
override API_LIB_STATIC:=$(strip ${API_LIB_STATIC})
override API_LIBRARIES:=$(strip ${API_LIBRARIES})
override API_BIN:=$(strip ${API_BIN})

#${info API_INC=[${API_INC}]}
#${info API_LIB=[${API_LIB}]}
#${info API_LIB_STATIC=[${API_LIB_STATIC}]}
#${info API_LIBRARIES=[${API_LIBRARIES}]}
#${info API_BIN=[${API_BIN}]}

ESPACE:=#
ESPACE+=#astice de guere

##########################################
#   			 Common		   			 #
##########################################

#compilation
ifdef API_INC
	override NVCCFLAGS+= -I$(subst ${ESPACE}, -I,${API_INC})
endif

#link (link shared)
ifdef API_LIB
	override NVCCLDFLAGS+= -L$(subst ${ESPACE}, -L,${API_LIB}) 
endif

#link (link shared)	
ifdef API_LIBRARIES
	override NVCCLDFLAGS+= -l$(subst ${ESPACE}, -l,${API_LIBRARIES}) 
endif
	
#link (link static lib)
ifdef API_LIB_STATIC
	override SRC_AUX+= ${API_LIB_STATIC}
	override NVCCLDFLAGS+= -L$(subst ${ESPACE}, -L,${API_LIB_STATIC})
endif

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# commmon   #
############

#rien

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

endif#end win

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# common   #
############

#rien
	
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
	ifdef API_RPATH_LINK
		RPATH_LINK+=${API_RPATH_LINK}
	endif
endif

endif#end linux

#########################
# 		 common			#
#########################

#remove space
override NVCCFLAGS:=$(strip ${NVCCFLAGS})
override NVCCLDFLAGS:=$(strip ${NVCCLDFLAGS})

#call unique
override NVCCFLAGS:=$(call uniq,${NVCCFLAGS})
override NVCCLDFLAGS:=$(call uniq,${NVCCLDFLAGS})

##########################################
#   			 END 		   			 #
##########################################

endif#__API_ALL_CUDA_MK__
