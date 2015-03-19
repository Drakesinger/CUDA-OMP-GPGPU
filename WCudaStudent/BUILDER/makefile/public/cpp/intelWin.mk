# Version 	: 0.0.3
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __INTEL_WIN_PUBLIC_OPTION_MK__
__INTEL_WIN_PUBLIC_OPTION_MK__=true

###############################################
#  			Intel Win						  #
###############################################

########################
#   	public		   #
########################

# Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#################
# 	Warning     #
#################

#CXXFLAGS+= /w 		#Suppres warning messages

#################
# 	Divers     #
#################

#exception
CXXFLAGS+= /EHsc

#linkage dll
CXXFLAGS+= /MD 

#################
# Optimisation  #
#################

# General
CXX_OPTIMISATION+= /O3
CXX_OPTIMISATION+= /fast
CXX_OPTIMISATION+= /Qparallel
CXX_OPTIMISATION+= /Qpar-threshold100

# CPU specific
#X86_CXX_OPTIMISATION+= /QxSSSE3  
#X86_CXX_OPTIMISATION+= /QxSSE4.1 		# xeon x8 home
#X86_CXX_OPTIMISATION+= /QxSSE4.2		# cuda1
#X86_CXX_OPTIMISATION+= /QxAVX 			# i7 work
#X86_CXX_OPTIMISATION+= /QxCORE-AVX2 	# cuda2,i7 home

X86_CXX_OPTIMISATION+= /QxHost 		#generate instructions for the highest instruction set and processor available on the compilation host machine

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

# Injection automatique de lib windows standard
#		true (ou n'importe quoi) pour activer!
#		rien pour desactiver
#		Version minimale : vide (avec # pour le montrer)
IS_DEFAULT_SYS_LIBRARY_ENABLE:=#
IS_ADVANCED_SYS_LIBRARY_ENABLE:=#

###############################################
#  					End						  #
###############################################

endif#__INTEL_WIN_PUBLIC_OPTION_MK__
