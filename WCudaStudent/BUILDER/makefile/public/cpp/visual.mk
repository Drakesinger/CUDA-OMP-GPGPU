# Version 	: 0.0.2
# Author 	: Cedric.Bilat@he-arc.ch
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __VISUAL_PUBLIC_OPTION_MK__
__VISUAL_PUBLIC_OPTION_MK__=true

###############################################
#  			Visual							  #
###############################################

########################
#   	public		   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#CXXFLAGS+=

#################
# 	Warning     #
#################

#CXXFLAGS+= /w 		# Suppres warning messages 
#CXXFLAGS+= /Wall	# Enables all warning 
#CXXFLAGS+= /W3		# Warning level

#################
# 	divers     #
#################

#exception
CXXFLAGS+= /EHsc 

#linkage dll
CXXFLAGS+= /MD
#CXXFLAGS+= /MT

#################
# Optimisation  #
#################

# General
CXX_OPTIMISATION+= /Ox 			# All optimisation

# CPU specific
#X86_CXX_OPTIMISATION+= /arch:SSE 	# By default with 64bits processor
#X86_CXX_OPTIMISATION+= /arch:SSE2 	# By default with 64bits processor , xeon x4 home
X86_CXX_OPTIMISATION+= /arch:AVX	# ko home, i7 work
#X86_CXX_OPTIMISATION+= /arch:AVX2	# cuda2,i7 home

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

IS_DEFAULT_SYS_LIBRARY_ENABLE+=
IS_ADVANCED_SYS_LIBRARY_ENABLE+=

# Injection automatique de lib windows standard
#		true (ou n'importe quoi) pour activer!
#		rien pour desactiver
#		Version minimale : vide (avec # pour le montrer)

EXCLUDE_LIBRARY_FILES+=#
ADD_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__VISUAL_PUBLIC_OPTION_MK__
