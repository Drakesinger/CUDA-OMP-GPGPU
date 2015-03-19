# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_CULA_MK__
__API_CULA_MK__=true

##########################################
#   		 Cula 		  	 			 #
##########################################

#########################
# 		 Common			#
#########################

API_INC+= $(subst ${SEPARATOR}, ,${CULA_INC})
API_LIB+= $(subst ${SEPARATOR}, ,${CULA_LIB})
API_BIN+= $(subst ${SEPARATOR}, ,${CULA_LIB}) 
#API_LIB_STATIC+= 
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${CULA_LIBRARIES}) 

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compil
	#NVCCFLAGS+= -I${CULA_INC}
	#NVCCFLAGS+= -I$(subst ;, -I,${CULA_INC})
	
	#link
	#NVCCLDFLAGS+= -L${CULA_LIB}
	#NVCCLDFLAGS+= cula_lapack.lib
	
	#NVCCLDFLAGS+= -L$(subst ;, -L,${CULA_LIB})
	#NVCCLDFLAGS+= -l$(subst ;, -l,${CULA_LIBRARIES}) 
	
endif

endif#win

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)


############
# common   #
############

	#compil
	#NVCCFLAGS+= -I$(subst :, -I,${CULA_INC})
	
	#link
	#NVCCLDFLAGS+= -L${CULA_LIB}
	#NVCCLDFLAGS+= -L$(subst :, -L,${CULA_LIB})
	#NVCCLDFLAGS+= -l$(subst :, -l,${CULA_LIBRARIES}) 

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)
	#rien
endif

############
# ARM   #
############

ifeq  ($(ARCH),arm)
	#pas disponible
endif

endif#end linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_CULA_MK__

