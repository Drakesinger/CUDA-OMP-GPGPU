# Version 	: 0.0.3
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __MINGW_PUBLIC_OPTION_MK__
__MINGW_PUBLIC_OPTION_MK__=true


###############################################
#  			MinGW							  #
###############################################

########################
#   	public		   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#CXXFLAGS+=#
#CXXFLAGS+= -std=c++0x


#################
# 	Warning     #
#################

#CXXFLAGS+= -w 					# disable warning
#CXXFLAGS+= -W 					# Print extra warning messages
#CXXFLAGS+= -Wall 				# enable all warning
#CXXFLAGS+= -Wunused-variable 	# show unused-variable
#CXXFLAGS+= -Wunused-function	# show unused-function
#CXXFLAGS+= -Wunused-parameter 	# show unused-parameter

#################
# Optimisation  #
#################

# General
CXX_OPTIMISATION+= -O3

CXX_OPTIMISATION+= -frerun-loop-opt 
CXX_OPTIMISATION+= -fgcse 
CXX_OPTIMISATION+= -fomit-frame-pointer

# CPU specific

#X86_CXX_OPTIMISATION+= -march=core2 				# xeon x4 home,portable
#X86_CXX_OPTIMISATION+= -march=corei7			 	# cuda1
#X86_CXX_OPTIMISATION+= -march=corei7-avx  			# cuda2, mieux?
#X86_CXX_OPTIMISATION+= -march=sandybridge			# i7 work
#X86_CXX_OPTIMISATION+= -march=ivybridge			# i7 home
#X86_CXX_OPTIMISATION+= -march=haswell	

X86_CXX_OPTIMISATION+= -march=native 				# Detection automatique arch

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

LDFLAGS+=

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

ADD_LIBRARY_FILES+=#
EXCLUDE_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__MINGW_PUBLIC_OPTION_MK__

