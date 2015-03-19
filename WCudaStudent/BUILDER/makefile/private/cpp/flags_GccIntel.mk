# Version 	: 0.0.3
# Date		: 12.02.2014
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#			  MakeFileNotice.txt
#
# Hyp		: Application that must be in path


ifndef __FLAG_GCC_INTEL_MK__
__FLAG_GCC_INTEL_MK__=true

######################
#   Init	    	 #
######################

#SHELL=/bin/bash

machine:=${shell uname -m}
ifeq (${machine},x86_64)
	ARCHI_32_64:=x86_64
else
	ARCHI_32_64:=x86_32
endif

ifeq (${ARCH},arm) 
	ifeq ($(PLATFORME),jetson)
		ARCHI_32_64:=ARM_32
	endif
	
	ifeq ($(PLATFORME),kayla)
		ARCHI_32_64:=ARM_32
	endif
endif

######################
#    Variables       #
######################

ifeq ($(COMPILATEUR),INTEL)
	#Compilateur ,Archiveur (static lib)
    CXX:=icpc
    AR:=xiar
    NAME_COMPILATEUR:=intel
    NAME_COMPILATEUR_INSTALL:=intel
else
    #Compilateur ,Archiveur (static lib)
    
   	ifneq ($(ARCH),arm)
    	CXX:=g++
    	AR:=ar
    	NAME_COMPILATEUR:=gcc
    	NAME_COMPILATEUR_INSTALL:=gcc
    else
    	CXX:=g++ARM
    	AR:=arARM
    	NAME_COMPILATEUR:=gcc
    	NAME_COMPILATEUR_INSTALL:=gcc_arm
    endif
    
endif

include ${ROOT_MAKEFILE_PRIVATE_CPP}/name.mk

#############
# Extension  #
#############

EXTENSION_OBJ:=o#
EXTENSION_LIB:=a#
EXTENSION_DLL:=so#
EXTENSION_EXE:=run#
# Note enstension sans le .



#############
#Compilateur#
#############

SYS_LIBRARY_FILES:=#minimum rien
OPTION_SEPARATOR:=-#
LIB_FLAG_SEPARATOR:=l#
LIB_PATH_SEPARATOR:=L#
HEADER_OPTION:=I#
OUT_FILE_COMPILE:=-o #attention end with space!
OUT_FILE_LINK:=-o #attention end with space!
LINK_TAG:=#rien
LINK_FLAG_DLL:=-shared #with espace !

LIB_PREFIXE:=lib#

VERSION_CXX:=$(CXX) --version
CXX_HELP:=$(CXX) --help

##########
#ARCHIVEUR#
###########

AR_OUT_FLAG:=-r #with espace important !

#############
# SET FILES	#
#############

#	Input : 
#		SRC_PATH_ALL
#	Output :
#		All files libXXX.a, libXXX.so and XXX.so, without XXX.a !
#	Objectifs :
#		Les .a prefix� par lib (libXXX.a) seront donnee a GCC sous la forme -lXXX)
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a
SRC_A_FILES_STANDART:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/$(LIB_PREFIXE)*.$(EXTENSION_LIB)))
SRC_A_FILES_STANDART+=$(SRC_SO_FILES)

#	Input : 
#		SRC_PATH_ALL
#	Output :
#		All files XXX.a without libXXX.a, libXXX.so and XXX.so !
#	Objectifs :
#		Les .a prefix� par lib (libXXX.a) seront donnee a GCC sous la forme -lXXX
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a avec la path complet (par exemple ../libs/YYY.a)
SRC_A_FILES_NOT_STANDART:=$(foreach dir,$(SRC_PATH_ALL),$(filter-out $(dir)/$(LIB_PREFIXE)%.$(EXTENSION_LIB),$(wildcard $(dir)/*.$(EXTENSION_LIB))))

#################
# PREPARE FLAGS	#
#################

#plus ici dans api
#Ajoute automatiquement gomp(gcc) or iomp5(Intel)  si on use OpenMP
#ifneq (, $(findstring openmp,$(CXXFLAGS)))#findstring return vide si openmp pas trouver!
#	ifeq ($(COMPILATEUR),INTEL)
#		ADD_LIBRARY_FILES+=iomp5
#	else
#		ADD_LIBRARY_FILES+=gomp
#	endif
#endif

#only fileName (./libs/libXXX.a ./libs/YYY.so -> lixXXX.a YYY.so)
LIB_FLAG:=$(notdir $(SRC_A_FILES_STANDART))

#removing prefix lib (libXXX.a libYYY.a libZZZ.so -> XXX.a YYY.a ZZZ.so)
LIB_FLAG:=$(subst $(LIB_PREFIXE),,$(LIB_FLAG))#remplace lib par rien

#Delete extension .a (XXX.a YYY.a -> XXX YYY)
LIB_FLAG:=$(LIB_FLAG:.$(EXTENSION_LIB)=)

#Delete extension .so (AAA.so BBB.so -> AAA BBB)
LIB_FLAG:=$(LIB_FLAG:.$(EXTENSION_DLL)=)

#ADDING custom LIB and System LIB
LIB_FLAG+=$(ADD_LIBRARY_FILES) $(SYS_LIBRARY_FILES)

# Input :
#	list lib to delete example (AAA ZZZ)
#
#	before : LIB_FLAG (XXX YYY ZZZ)
#	after  : LIB_FLAG (XXX YYY) without ZZZ
LIB_FLAG:=$(filter-out $(EXCLUDE_LIBRARY_FILES),$(LIB_FLAG))

#Adding Lib FLAG separator -l (XXX YYY -> -lXXX -lYYY)
LIB_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_FLAG_SEPARATOR),$(LIB_FLAG))

#Adding Lib path FLAG separator -L (../AAA ./BBB -> -L../AAA _L./BBB)
#LIB_PATH_FLAG:=${SRC_PATH_ALL}#old
#LIB_PATH_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_PATH_SEPARATOR),$(LIB_PATH_FLAG))#old
LIB_PATH:=$(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.so)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override LIB_PATH:=$(call uniq,${LIB_PATH})
#${info "LIB_PATH= "${LIB_PATH}}
LIB_PATH_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_PATH_SEPARATOR),$(LIB_PATH))

#Adding Include FLAG separator -I (../header ../header/api -> -I../header -I../header/api)
#HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(HEADER_PATH_ALL))#old
HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(INC_PATH))


#Injection variable in .cpp code (VAR1 VAR2 -> -DVAR1 -DVAR2)
CODE_DEFINE_VARIABLES_D:= $(addprefix  -D,$(CODE_DEFINE_VARIABLES))

ifeq ($(TARGET_MODE),SHARED_LIB)
	 override CXXFLAGS := -fPIC -fvisibility=hidden ${CXXFLAGS}	
endif

ifeq ($(TARGET_MODE),STATIC_LIB)
 	override CXXFLAGS := -fPIC ${CXXFLAGS}	
endif

#OUTPUTS#
override LDFLAGS_AUX+= $(SRC_A_FILES_NOT_STANDART)
override CXXFLAGS += $(HEADER_FLAG)
override CXXFLAGS += $(CODE_DEFINE_VARIABLES_D)
override LDFLAGS  += $(LINK_TAG) $(LIB_PATH_FLAG) $(LIB_FLAG) $(LDFLAGS_AUX)

#########
#  End  #
#########

endif#__FLAG_GCC_INTEL_MK__