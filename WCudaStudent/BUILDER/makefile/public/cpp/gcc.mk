# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les definitions de variables ci-dessous, mefiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apres le += de surcharge : exemple : xxx+= yyyy
#

ifndef __GCC_PUBLIC_OPTION_MK__
__GCC_PUBLIC_OPTION_MK__=true

###############################################
#  					GCC						  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_CPP}/gcc_arm.mk

########################
#   	public		   #
########################

# Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#CXXFLAGS+=

#################
# 	Warning     #
#################

#CXXFLAGS+= -w 					# Disable warning
#CXXFLAGS+= -W 					# Print extra warning messages
#CXXFLAGS+= -Wall 				# Enable all
#CXXFLAGS+= -Wunused-variable 	# show unused-variable
#CXXFLAGS+= -Wunused-function	# show unused-function
#CXXFLAGS+= -Wunused-parameter 	# show unused-parameter

#################
# Optimisation  #
#################

# Common X86 et ARM
CXX_OPTIMISATION+= -O3 

#######
# x86 #
#######

# General
X86_CXX_OPTIMISATION+= -frerun-loop-opt 
#X86_CXX_OPTIMISATION+= -fgcse 
X86_CXX_OPTIMISATION+= -fomit-frame-pointer

# CPU specific
#X86_CXX_OPTIMISATION+= -march=core2 
#X86_CXX_OPTIMISATION+= -march=corei7 				# cuda1
#X86_CXX_OPTIMISATION+= -march=corei7-avx 			# cuda2,i7
#X86_CXX_OPTIMISATION+= -march=sandybridge			# i7 work
#X86_CXX_OPTIMISATION+= -march=ivybridge			# i7 home
#X86_CXX_OPTIMISATION+= -march=haswell		

X86_CXX_OPTIMISATION+= -march=native 							# Detection automatique arch		

#######
# ARM #
#######

ARM_CXXFLAGS+=#

#################
# debug         #
#################

#decommneter la ligne pour 
#	(1) empecher l'optimisation
#	(2) activer les flag de debug

#DEBUG=true

#################
# linkage       #
#################

# Static Lib
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

ARFLAGS+=#
 
# Shared lib
#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

LDFLAGS+=#

#################
# extension     #
#################

#Injection de variable dans le code 
#	same as #define XXX YYY
#	same as -DXXX
#Attention, pas mettre -D, ni #define, que XXX

CODE_DEFINE_VARIABLES+=

# Attention :
#	separateur est espac
#	sans extension .lib
#	sans prefixe lib

EXCLUDE_LIBRARY_FILES+=
ADD_LIBRARY_FILES+=

###############################################
#  					End						  #
###############################################

endif#__GCC_PUBLIC_OPTION_MK__