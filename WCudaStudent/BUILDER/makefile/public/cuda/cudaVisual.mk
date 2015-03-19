# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __CUDA_VISUAL_PUBLIC_OPTION_MK__
__CUDA_VISUAL_PUBLIC_OPTION_MK__=true

###############################################
#  			Cuda Visual Win					  #
###############################################

##################################
#   		public			     #
##################################

########################
# 		visual	   	   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#CXXFLAGS+=

#################
# 	Warning     #
#################

#linkage dll
CXXFLAGS+= /MD

#################
# Optimisation  #
#################

# General
CXX_OPTIMISATION+= /Ox			# All optimisation

# CPU specific
#
#CXX_OPTIMISATION+= /arch:SSE 	# By default with 64bits processor
#CXX_OPTIMISATION+= /arch:SSE2 	# By default with 64bits processor
CXX_OPTIMISATION+= /arch:AVX	# ko home, i7 work
#X86_CXX_OPTIMISATION+= /arch:AVX2	# cuda2,i7 home

#################
# linkage       #
#################

#Option de linkage
#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

CXXLDFLAGS+=#

########################
# 		nvcc	   	   #
########################

#################
# target       #
#################

# NVCCFLAGS
# https://developer.nvidia.com/cuda-gpus
# Quadro Fx4600 : 				sm_10 
# Quadro nvs140M : 				sm_11 
# GTX_295 : 					sm_13
# GTX 580					 	sm_20
# Tesla m2090					sm_20
# Quadro6000					sm_20
# Quadroplex 7000				sm_20
# GTX 680						sm_30
# Quadro k5000					sm_30
# jetson k1						sm_32
# Tesla k20c					sm_35
# Gforce titan					sm_35
# Quadro k6000					sm_35
# GeForce GTX 980				sm_52

# NVCCFLAGS possibilities:
#
#	-arch=<compute_xy> 				Generate PTX for capability x.y
#	-code=<sm_xy> 					Generate binary for capability x.y, by default same as -arch
#	-gencode arch=...,code=... 		Same as -arch and -code, but may be repeated (executable is bigger, and compilation time longer)

# Target : Syntaxe light (shorcut)
#		 : Avantage 	: short,easy, quick
#		 : Incovenient  : only one target can be specify!
#
NVCCFLAGS+= -arch=sm_20
#
# Target : Syntaxe full
#		 : Avantage 	: many target can be specify! 
#		 :				: Allow jit compilation at runtime, for deploying in a gpu with higher arch than arch use for developpement. 
#
#		 : Option : -arch : Virtual architecture
#						  : generate PTX (ptx code is the same as byte code in java) 
#						  : Like java,  a jit compilation at runtime is performed.
#						  : Jit compilatioonce is performed only once, fortunately a cache is used to persist a final binary image.
#
#		 : Option : -code : Real architecture
#						  : nvcc embeded a compiled code image in the executable for each specified architecture -arch,
#						  : Code image is a true binary load image for each real architecture (present at compilation time?), and ptx code for earch virtual architecture (not present at compilation time?)
#		                
#		  		         
#
# Enable or disable all following lignes
#NVCCFLAGS+= -gencode arch=compute_20,code=sm_20 #idem NVCCFLAGS+= -arch=sm_20
#NVCCFLAGS+= -gencode arch=compute_30,code=sm_30 #idem NVCCFLAGS+= -arch=sm_30
#NVCCFLAGS+= -gencode arch=compute_35,code=sm_35 #idem NVCCFLAGS+= -arch=sm_35
#NVCCFLAGS+= -gencode arch=compute_50,code=sm_50 #idem NVCCFLAGS+= -arch=sm_50

NVCCFLAGS+= -m64 #

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#################
# Optimisation  #
#################

NVCCFLAGS+= -use_fast_math	#idem -ftz=true -prec_div=false -prec_sqrt=false
NVCCFLAGS+= --fmad=true #

#################
# linkage       #
#################

#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

NVCCLDFLAGS+=#

#################
# debug         #
#################

#decommneter la ligne pour 
#	(1) empecher l'optimisation
#	(2) activer les flag de debug

#DEBUG=true

#NVCCFLAGS+= -dryrun
#NVCCFLAGS+= -v

#################
# extension     #
#################

#Injection de variable dans le code 
#	same as #define XXX YYY
#	same as -DXXX
#Attention, pas mettre -D, ni #define, que XXX

CODE_DEFINE_VARIABLES+=#

# Injection automatique de lib windows standard
#		true (ou n'importe quoi) pour activer!
#		rien pour desactiver
#		Version minimale : vide (avec # pour le montrer)

EXCLUDE_LIBRARY_FILES+=#
ADD_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__CUDA_VISUAL_PUBLIC_OPTION_MK__

