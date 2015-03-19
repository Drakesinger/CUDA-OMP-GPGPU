# Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __API_WIN_ADVANCED_LIBRARY_MK__
__API_WIN_ADVANCED_LIBRARY_MK__=true

##########################################
#   		win advanced library		 #
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

	ifneq (, $(findstring /MD,$(CXXFLAGS)))#findstring return vide si /MD pas trouver!
		CXXFLAGS+= /MD #dynamicaly link CRT with the target
	endif
	
	#CXXFLAGS+= /MT #statically link the MS CRT to the DLL par d�faut !
	# en commentaire, pour pouvoir mettre /MD pour linker own lib 

	#link
	DEFAULT_SYS_LIBRARY_FILES+= kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib 
	DEFAULT_SYS_LIBRARY_FILES+= shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
	
	ADVANCED_SYS_LIBRARY:=$(LIB)	#where LIB is a va set by the script vcvarsamd64.bat. Requiert speccifique .dll as msvcr90.dll for running)
	ADVANCED_SYS_LIBRARY:=$(subst  \,/,$(ADVANCED_SYS_LIBRARY)) 
	ADVANCED_SYS_LIBRARY:=$(subst  ;, ,$(ADVANCED_SYS_LIBRARY))  
	#CRT =C runtime library.
	#Only one of: libcmt.lib libcmt.lib  libcmtd.lib msvcrtd.lib msvcmrt.lib msvcurt.lib  msvcrt.lib
	#must be used
	#Choice smart 1: use msvcrt.lib (Contrainte use /MD)
	#Choice smart 2: use libcmt.lib (Contrainte use /MT)
	EXCLUDE_LIBRARY_FILES+= libcmt.lib libcmtd.lib msvcrtd.lib msvcmrt.lib 	
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	ADVANCED_SYS_LIBRARY:=$(LIB)	#where LIB is a va set by the script vcvarsamd64.bat. Requiert speccifique .dll as msvcr90.dll for running)
	ADVANCED_SYS_LIBRARY:=$(subst  \,/,$(ADVANCED_SYS_LIBRARY)) 
	ADVANCED_SYS_LIBRARY:=$(subst  ;, ,$(ADVANCED_SYS_LIBRARY))  
	#CRT =C runtime library.
	#Only one of: libcmt.lib libcmt.lib  libcmtd.lib msvcrtd.lib msvcmrt.lib msvcurt.lib  msvcrt.lib
	#must be used
	#Choice smart 1: use msvcrt.lib (Contrainte use /MD)
	#Choice smart 2: use libcmt.lib (Contrainte use /MT)
	EXCLUDE_LIBRARY_FILES+= libcmt.lib libcmtd.lib msvcrtd.lib msvcmrt.lib libcpmtd.lib libcpmt.lib	
	
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

endif#__API_WIN_ADVANCED_LIBRARY_MK__

