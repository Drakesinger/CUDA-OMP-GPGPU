# Version 	: 0.0.2
# Date		: 26.01.2012
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#			  MakeFileNotice.txt
#
# Hyp		: Application that must be in path
#				sh
#

ifndef __CPP_FILSE_SET_MK__
__CPP_FILSE_SET_MK__=true



#############
#	Path	#
#############

SRC_ROOT:=src
RESOURCES_PATH:=$(SRC_ROOT)/resources
TARGET_OBJ_PATH:=${TARGET_PATH}/obj
TARGET_BIN_PATH:=${TARGET_PATH}/bin

#TARGET_DEPLOY_PATH_BIN=${TARGET_DEPLOY_PATH}/bin
TARGET_DEPLOY_PATH_DOC=${TARGET_DEPLOY_PATH}/doc

SRC_PATH:=$(shell find $(SRC_ROOT) -type d)
	
ifdef SRC_AUX
	SRC_PATH_AUX:=$(shell find $(SRC_AUX) -type d)
else
	SRC_PATH_AUX:=
endif

SRC_PATH_ALL:=$(SRC_PATH) $(SRC_PATH_AUX) 

#############
# SET FILES	#
#############

#all
SRC_CPP_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cpp)) 
SRC_C_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.c)) 
SRC_HEADER_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.h)) 

#visual,intel
SRC_LIB_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.lib))
SRC_DLL_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.dll))

#gcc,mingw
SRC_SO_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.so))
SRC_A_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.a))

#nvcc
SRC_CU_FILES  := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cu)) 

override INC_PATH:=${INC_PATH} $(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.h)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override INC_PATH:=$(call uniq,${INC_PATH})
#${info "INC_PATH= "${INC_PATH}}#print immediately

#########
#  End  #
#########

endif#__CPP_FILSE_SET_MK__