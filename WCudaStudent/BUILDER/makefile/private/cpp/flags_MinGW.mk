# Version 	: 0.0.3
# Date		: 02.02.2012
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#			  MakeFileNotice.txt
#
# Hyp		: Application that must be in path

ifndef __CPP_FLAG_MINGW_MK__
__CPP_FLAG_MINGW_MK__=true

######################
#    Variables       #
######################

#Compilateur ,Archiveur (static lib)
CXX:=g++
AR:=ar

NAME_COMPILATEUR:=mingw
NAME_COMPILATEUR_INSTALL:=mingw

include ${ROOT_MAKEFILE_PRIVATE_CPP}/name.mk

#############
# Extension  #
#############

EXTENSION_OBJ:=obj#
EXTENSION_LIB:=a#
EXTENSION_DLL:=dll#
EXTENSION_EXE:=exe#
# Note enstension sans le .

#############
#Compilateur#
#############

SYS_LIBRARY_FILES:=#minimum rien
OPTION_SEPARATOR:=-#
LIB_FLAG_SEPARATOR:=l#
LIB_PATH_SEPARATOR:=L#
HEADER_OPTION:=I#attention end with space!
OUT_FILE_COMPILE:=-o #attention end with space!
OUT_FILE_LINK:=-o #attention end with space!
LINK_TAG:=#rien
LINK_FLAG_DLL:=-shared #with espace !

LIB_PREFIXE:=lib#rien

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
#		All files libXXX.a, libXXX.dll and XXX.dll, without XXX.a !
#	Objectifs :
#		Les .a prefix� par lib (libXXX.a) seront donnee a GCC sous la forme -lXXX)
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a
SRC_A_FILES_STANDART:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/$(LIB_PREFIXE)*.$(EXTENSION_LIB)))
SRC_A_FILES_STANDART+=$(SRC_DLL_FILES)

# Libraries #
#	Input : 
#		SRC_PATH_ALL
#	Output :
#		All files XXX.a without libXXX.a, libXXX.dll and XXX.dll !
#	Objectifs :
#		Les .a prefix� par lib (libXXX.a) seront donnee a GCC sous la forme -lXXX
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a avec la path complet (par exemple ../libs/YYY.a).
SRC_A_FILES_NOT_STANDART:=$(foreach dir,$(SRC_PATH_ALL),$(filter-out $(dir)/$(LIB_PREFIXE)%.$(EXTENSION_LIB),$(wildcard $(dir)/*.$(EXTENSION_LIB))))

#################
# PREPARE FLAGS	#
#################

# dans api now
#Ajoute automatiquement gomp si on use OpenMP
#ifneq (, $(findstring openmp,$(CXXFLAGS)))#findstring return vide si openmp pas trouver!
#		 ADD_LIBRARY_FILES+=gomp
#endif

#only fileName (./libs/libXXX.a ./libs/YYY.dll -> lixXXX.a YYY.dll)
LIB_FLAG:=$(notdir $(SRC_A_FILES_STANDART))

#removing prefix lib (libXXX.a libYYY.a libZZZ.dll -> XXX.a YYY.a ZZZ.dll)
LIB_FLAG:=$(subst $(LIB_PREFIXE),,$(LIB_FLAG))#remplace lib par rien

#Delete extension .a (XXX.a YYY.a -> XXX YYY)
LIB_FLAG:=$(LIB_FLAG:.$(EXTENSION_LIB)=)

#Delete extension .dll (XXX.dll YYY.dll -> XXX YYY)
LIB_FLAG:=$(LIB_FLAG:.$(EXTENSION_DLL)=)

#ADDING custom LIB and System LIB
LIB_FLAG+= $(ADD_LIBRARY_FILES) $(SYS_LIBRARY_FILES)

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
LIB_PATH:=$(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.a)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override LIB_PATH:=$(call uniq,${LIB_PATH})
#${info "LIB_PATH= "${LIB_PATH}}
LIB_PATH_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_PATH_SEPARATOR),$(LIB_PATH))

#Adding Include FLAG separator -I (../header ../header/api -> -I../header -I../header/api)
#HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(HEADER_PATH_ALL))#old
HEADER_FLAG:= $(addprefix $(OPTION_SEPARATOR)$(HEADER_OPTION),$(INC_PATH))

ifeq ($(TARGET_MODE),SHARED_LIB)

		#deja dans cpp.mk
		#ifneq ($(ARCH),arm)
   		#	TARGET_NAME:=${TARGET_NAME}_$(NAME_COMPILATEUR)_$(ARCHI_32_64)
		#else
  		#    TARGET_NAME:=$(TARGET_NAME)_$(NAME_COMPILATEUR)_$(PLATFORME)_$(ARCHI_32_64)
		#endif

	   #TARGET_NAME_LIB_COMMON:=$(TARGET_BIN_PATH)/${LIB_PREFIXE}$(TARGET_NAME)_$(ARCHI_32_64)
	   TARGET_NAME_LIB_DLL_COMMON:=$(TARGET_BIN_PATH)/${LIB_PREFIXE}${TARGET_NAME}
	   TARGET_NAME_LIB_DLL:=${TARGET_NAME_LIB_DLL_COMMON}.dll.$(EXTENSION_LIB)
	   TARGET_NAME_LIB_DLL_DEF:=${TARGET_NAME_LIB_DLL_COMMON}.def
		
	   #${info "TARGET_NAME_LIB="${TARGET_NAME_LIB_DLL}}

       GENERATEUR_DLL_DEF:= -Wl,--output-def,${TARGET_NAME_LIB_DLL_DEF}
       GENERATEUR_DLL_LIB_IMPORTATION:= -Wl,--out-implib,${TARGET_NAME_LIB_DLL}
      
       #override LDFLAGS:= $(GENERATEUR_DLL_LIB_IMPORTATION) $(GENERATEUR_DLL_DEF)
       override LDFLAGS+= $(GENERATEUR_DLL_LIB_IMPORTATION) $(GENERATEUR_DLL_DEF)
      # CXXFLAGS += -fPIC
    	   
	   override CXXFLAGS := -fvisibility=hidden ${CXXFLAGS}	   
endif

#Injection variable in .cpp code (VAR1 VAR2 -> -DVAR1 -DVAR2)
CODE_DEFINE_VARIABLES_D:= $(addprefix -D,$(CODE_DEFINE_VARIABLES))

#OUTPUTS
override LDFLAGS_AUX+= $(SRC_A_FILES_NOT_STANDART)
override CXXFLAGS += $(HEADER_FLAG)
override CXXFLAGS += $(CODE_DEFINE_VARIABLES_D)
override LDFLAGS  += $(LINK_TAG) $(LIB_PATH_FLAG) $(LIB_FLAG) $(LDFLAGS_AUX)

#########
#  End  #
#########

endif#__CPP_FLAG_MINGW_MK__