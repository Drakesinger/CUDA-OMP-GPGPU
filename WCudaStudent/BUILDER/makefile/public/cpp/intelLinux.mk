# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#


ifndef __INTEL_LINUX_PUBLIC_OPTION_MK__
__INTEL_LINUX_PUBLIC_OPTION_MK__=true

###############################################
#  			Intel Linux						  #
###############################################


########################
#   	public		   #
########################

# Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#CXXFLAGS+=#

#################
# 	Warning     #
#################

CXXFLAGS+= -w #supress warning message

#################
# Optimisation  #
#################

# General
CXX_OPTIMISATION+= -O3

X86_CXX_OPTIMISATION+= -fast
X86_CXX_OPTIMISATION+= -parallel 			#linux pose probleme si projet trop simple (undefined reference to `__kmpc_begin'). Solution : use in local intelLinux.mk : CXXFLAGS_EXCLUDE+= -parallel
X86_CXX_OPTIMISATION+= -par-threshold100

# CPU specific
#X86_CXX_OPTIMISATION+= -axSSSE3
#X86_CXX_OPTIMISATION+= -axSSE4.1 		# xeon home
X86_CXX_OPTIMISATION+= -axSSE4.2 		# cuda1
#X86_CXX_OPTIMISATION+= -axAVX 			# i7 work
#X86_CXX_OPTIMISATION+= -axAVX2 		# cuda2, i7 home

#X86_CXX_OPTIMISATION+= -axHost			#generate instructions for the highest instruction set and processor available on the compilation host machine

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

LDFLAGS_AUX+=



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

endif#__INTEL_LINUX_PUBLIC_OPTION_MK__

