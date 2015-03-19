## Version 	: 0.0.4
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#			  MakeFileNotice.txt
#
# Hyp		: Application that must be in path

ifndef __CPP_FLAG_VISUAL_INTEL_MK__
__CPP_FLAG_VISUAL_INTEL_MK__=true

######################
#    Variables       #
######################

ifeq ($(COMPILATEUR),VISUAL)
	#Compilateur , Archiveur (static lib)
	CXX:=cl
	AR:=lib
	NAME_COMPILATEUR:=visual
	NAME_COMPILATEUR_INSTALL:=visual
endif

ifeq ($(COMPILATEUR),INTEL)
	#Compilateur , Archiveur (static lib)
	CXX:=icl
	AR:=xilib
	NAME_COMPILATEUR:=intel
	NAME_COMPILATEUR_INSTALL:=intel
endif

include ${ROOT_MAKEFILE_PRIVATE_CPP}/name.mk

#############
# Extension  #
#############

EXTENSION_OBJ:=obj#
EXTENSION_LIB:=lib#
EXTENSION_DLL:=dll#
EXTENSION_EXE:=exe#
# Note enstension sans le .

#############
#Compilateur#
#############

OPTION_SEPARATOR:=/#
LIB_FLAG_SEPARATOR:=#
LIB_PATH_SEPARATOR:=/LIBPATH:#
HEADER_OPTION:=I#
OUT_FILE_COMPILE:=/Fo#attention, end without space
OUT_FILE_LINK:=/Fe#idem
LINK_TAG:=/link#
LINK_FLAG_DLL:=/DLL#
SYS_LIBRARY_FILES:=#minimum rien

LIB_PREFIXE:=#rien

VERSION_CXX:=$(CXX)
CXX_HELP:=$(CXX) /help

##########
#ARCHIVEUR#
###########

AR_OUT_FLAG:=/OUT:#Sans espace

#############
# SET FILES	#
#############

SRC_LIB_FILES+=$(foreach dir,$(ADVANCED_SYS_LIBRARY),$(wildcard $(dir)/$(EXTENSION_LIB))) 

#################
# PREPARE FLAGS	#
#################

#only fileName (./libs/XXX.lib ./libs/YYY.lib -> XXX.lib YYY.lib)
LIB_FLAG:=$(notdir $(SRC_LIB_FILES))
LIB_FLAG+=${DEFAULT_SYS_LIBRARY_FILES}

#Custom exclude libs
LIB_FLAG:=$(filter-out $(EXCLUDE_LIBRARY_FILES),$(LIB_FLAG))

#ADDING User defined LIB
LIB_FLAG+=$(ADD_LIBRARY_FILES)

#Adding Lib path FLAG separator /LIBPATH: (../AAA ./BBB -> -/LIBPATH:../AAA /LIBPATH:./BBB)
#LIB_PATH_FLAG:=${SRC_PATH_ALL}#old
#LIB_PATH_FLAG:=$(addprefix $(LIB_PATH_SEPARATOR),$(LIB_PATH_FLAG))#old
LIB_PATH:=$(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.lib)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override LIB_PATH:=$(call uniq,${LIB_PATH})
#${info "LIB_PATH= "${LIB_PATH}}
LIB_PATH_FLAG:=$(addprefix $(LIB_PATH_SEPARATOR),$(LIB_PATH))


#HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(HEADER_PATH_ALL))#old
HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(INC_PATH))

CODE_DEFINE_VARIABLES_D:= $(addprefix  /D,$(CODE_DEFINE_VARIABLES))

override CXXFLAGS += /nologo 
override CXXFLAGS += $(HEADER_FLAG)
override CXXFLAGS += $(CODE_DEFINE_VARIABLES_D)

override LDFLAGS += $(LINK_TAG) $(LIB_PATH_FLAG) $(LIB_FLAG) $(LDFLAGS_AUX) /nologo

ifeq ($(TARGET_MODE),SHARED_LIB)
	TARGET_NAME_LIB_DLL:=$(TARGET_BIN_PATH)/${TARGET_NAME}.lib
endif

#########
#  End  #
#########

endif#__CPP_FLAG_VISUAL_INTEL_MK__