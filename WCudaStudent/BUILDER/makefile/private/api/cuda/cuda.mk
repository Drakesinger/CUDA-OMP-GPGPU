# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_CUDA_MK__
__API_CUDA_MK__=true

##########################################
#   		 Cuda 		  	 			 #
##########################################

#########################
# 		 Common 		#
#########################

API_INC+= $(subst ${SEPARATOR}, ,${CUDA_INC})
API_LIB+= $(subst ${SEPARATOR}, ,${CUDA_LIB})
API_BIN+= $(subst ${SEPARATOR}, ,${CUDA_LIB}) 
#API_LIB_STATIC+= 
API_LIBRARIES+= $(subst ${SEPARATOR}, ,${CUDA_LIBRARIES}) 

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#compil
	#SRC_AUX+= ${CUDA_INC_ROOT} #ko
	#NVCCFLAGS+= -I${CUDA_INC}
	
	#NVCCFLAGS+= -I$(subst ;, -I,${CUDA_INC})
	
	#link
	#NVCCLDFLAGS+= -L${CUDA_LIB}
	#NVCCLDFLAGS+= -L$(subst ;, -L,${CUDA_LIB})

	#NVCCLDFLAGS+= -l$(subst ;, -l,${CUDA_LIBRARIES}) 

	#NVCCLDFLAGS+= -lcublas_device
	
	#NVCCLDFLAGS+= -lcublas
	#NVCCLDFLAGS+= -lcuda
	#NVCCLDFLAGS+= -lcudadevrt
	#NVCCLDFLAGS+= -lcudart
	#NVCCLDFLAGS+= -lcudart_static
	#NVCCLDFLAGS+= -lcufft
	#NVCCLDFLAGS+= -lcufftw
	#NVCCLDFLAGS+= -lcurand
	#NVCCLDFLAGS+= -lcusparse
	#NVCCLDFLAGS+= -lnppc
	#NVCCLDFLAGS+= -lnppi
	#NVCCLDFLAGS+= -lnpps	
	#NVCCLDFLAGS+= -lnvblas
	#NVCCLDFLAGS+= -lnvcuvid
	#NVCCLDFLAGS+= -lOpenCL
	
	#runtime
	#API_BIN+= ${CUDA_BIN}
	
	API_BIN+= $(subst ${SEPARATOR}, ,${CUDA_BIN}) 
	
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
	#NVCCFLAGS+= -I$(subst :, -I,${CUDA_INC})
	
	#link
	#NVCCLDFLAGS+= -L$(subst :, -L,${CUDA_LIB})
	#NVCCLDFLAGS+= -l$(subst :, -l,${CUDA_LIBRARIES}) 
	
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
	#LDFLAGS+= -L$(subst :, -L,${CUDA_LIB})
	#RPATH_LINK+=${CUDA_LIB}
endif

endif#linux

##########################################
#   			 END 		   			 #
##########################################

endif#__API_CUDA_MK__

