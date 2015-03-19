# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_WIN_SYSTEM_LIBRARY_MK__
__API_WIN_SYSTEM_LIBRARY_MK__=true

##########################################
#   		win systenm library			 #
##########################################

#deprecated

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	# flag permettant de linker statically les librairies systemes de visual (la CRT entre autre)
	# en commentaire, pour pouvoir mettre /MD pour linker own lib without winAdvancedSystemLib.mk
	# CXXFLAGS+= /MT 
	
	#link
	DEFAULT_SYS_LIBRARY_FILES+= kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib 
	DEFAULT_SYS_LIBRARY_FILES+= shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#link
	#rien
	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	#link
	#rien
	
endif

endif



#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)

	#link
	#rien
	
endif

############
# INTEL   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#link
	#rien
	
endif

endif

##########################################
#   			 END 		   			 #
##########################################

endif#__API_WIN_SYSTEM_LIBRARY_MK__

