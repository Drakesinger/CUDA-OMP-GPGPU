# Version 	: 0.0.8
# Date		: 01.08.2014
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#
# Hyp		: Application that must be in path
#				nvcc
#				make
#				g++
#				gcc
#


ifndef __MAKE_CUDA_GCC_MK__
__MAKE_CUDA_GCC_MK__=true

##############################################
#   			 Variables     				 #
##############################################

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

########
# Path #
########

SRC_ROOT:=src
TARGET_OBJ:=${TARGET_PATH}/obj
TARGET_BIN:=${TARGET_PATH}/bin
TARGET_CUBIN:=${TARGET_PATH}/cubin

#synonime ameliorer
TARGET_BIN_PATH:=${TARGET_BIN}
TARGET_OBJ_PATH:=${TARGET_OBJ}

#TARGET_DEPLOY_PATH_BIN=${TARGET_DEPLOY_PATH}/bin
TARGET_DEPLOY_PATH_DOC=${TARGET_DEPLOY_PATH}/doc

########
# cpp #
########

CXX=g++

NAME_COMPILATEUR:=gcc_cuda

ifeq (${ARCH},arm)	
	NAME_COMPILATEUR_INSTALL:=gcc_cuda_arm
else
	NAME_COMPILATEUR_INSTALL:=gcc_cuda
endif

########
# Cuda #
########

NVCC := nvcc
PTXAS_FLAGS := -fastimul
OBJ_EXTENSION:=o
OPTION_SEPARATOR:=-#attention, end without space
LINK_FLAG_DLL:=-shared #with space ! pour nvcc
EXTENSION_LIB:=.a
EXTENSION_DLL:=.so
LIB_PREFIXE:=lib# example : libXXX.a
LIB_FLAG_SEPARATOR:=l#attention end without space!
LIB_PATH_SEPARATOR:=L#attention end with space!

##############
#TARGET_NAME #
##############

SCRIPT=${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/cudaVersion.sh
NVCC_VERSION:=$(shell $(SCRIPT))
#${info "NVCC_VERSION"=${NVCC_VERSION}}

ifneq ($(ARCH),arm)
   TARGET_NAME:=${TARGET_NAME}_$(NAME_COMPILATEUR)_${NVCC_VERSION}_$(ARCHI_32_64)
else
   TARGET_NAME:=$(TARGET_NAME)_$(NAME_COMPILATEUR)_${NVCC_VERSION}_$(PLATFORME)_$(ARCHI_32_64)
endif

###########
#Extension#
###########

EXTENSION_OBJ:=o#
EXTENSION_LIB:=a#
EXTENSION_DLL:=so#
EXTENSION_EXE:=run#
# Note enstension sans le .

##########
# TARGET #
##########

#deja ci-dessus
#LIB_PREFIXE:=lib

TARGET_NAME_EXE:=$(TARGET_NAME).${EXTENSION_EXE}
TARGET_NAME_DLL:=${LIB_PREFIXE}$(TARGET_NAME).$(EXTENSION_DLL)
TARGET_NAME_LIB:=${LIB_PREFIXE}$(TARGET_NAME).${EXTENSION_LIB}

TARGET_EXE:=${TARGET_BIN_PATH}/$(TARGET_NAME_EXE)
TARGET_DLL:=${TARGET_BIN_PATH}/$(TARGET_NAME_DLL)
TARGET_LIB:=${TARGET_BIN_PATH}/$(TARGET_NAME_LIB)
#TARGET_OBJ:=$(addprefix $(TARGET_OBJ_PATH)/,$(notdir $(OBJ_FILES)))

#Selection de la target en fonction TARGET_MODE
ifeq ($(TARGET_MODE),EXE)
	TARGET:=${TARGET_EXE}
	TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_EXE)
endif

ifeq ($(TARGET_MODE),SHARED_LIB)
	TARGET:=${TARGET_DLL}
	TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_DLL)
	
	override NVCCLDFLAGS += $(LINK_FLAG_DLL)
	
	#Attention ARM : doit venir juste après le -Xcompiler!
    override CXXFLAGS := -fPIC -fvisibility=hidden ${CXXFLAGS}
  

endif

ifeq ($(TARGET_MODE),STATIC_LIB)
	TARGET:=${TARGET_LIB}
	TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_LIB)
endif

#old

#ifeq ($(TARGET_MODE),SHARED_LIB)
#	override NVCCLDFLAGS+= $(LINK_FLAG_DLL) 
#	override CXXFLAGS += -fPIC -fvisibility=hidden
#	TARGET_NAME_FULL=lib$(TARGET_NAME).so
#endif
#
#ifeq ($(TARGET_MODE),EXE)
#	TARGET_NAME_FULL=$(TARGET_NAME).run
#endif

#TARGET:=$(TARGET_BIN)/$(TARGET_NAME_FULL)
#TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_FULL)

##########
#ARCHIVEUR#
###########

ifneq ($(ARCH),arm)
    AR:=ar
else
    AR:=arARM
endif

ARFLAGS=# pas= car valeur vaut rv avant sous windows ???
AR_OUT_FLAG:=-r #with espace important !

############
# Params   #
############

#ameliorer deja avant mais sans .
EXTENSION_LIB:=.a
EXTENSION_DLL:=.so
#LIB_PREFIX:=#pas de prefixe

############
#Set files #
############

SRC_PATH:=$(shell find $(SRC_ROOT) -type d)	

ifdef SRC_AUX
	SRC_PATH_AUX:=$(shell find $(SRC_AUX) -type d)
else
	SRC_PATH_AUX:=
endif

SRC_PATH_ALL:=$(SRC_PATH) $(SRC_PATH_AUX)
SRC_SO_FILES:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.so))

# Libraries au format standard
#
#	Input : 
#		SRC_PATH_ALL
#	Output :
#		All files 
#			libXXX.a
#		 	libXXX.so
#			XXX.so
#		Excepted
#			XXX.a 
#	Goals :
#		Les .a prefixe par lib (example libXXX.a) seront donnee a GCC sous la forme -lXXX)
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a
#	Convention
#		Sous linux les .a standards sont libXXX.a
#		Les YYY.a sont non standards.
#
SRC_A_FILES_STANDART:=$(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/$(LIB_PREFIXE)*$(EXTENSION_LIB)))
SRC_A_FILES_STANDART+=$(SRC_SO_FILES)

# Libraries au format non standard
#
#	Input : 
#		SRC_PATH_ALL
#	Output :
#		All files XXX.a (without libXXX.a)
#	Objectifs :
#		Les .a prefixer par lib (libXXX.a) seront donnee a GCC sous la forme -lXXX
#		Alors que les YYY.a devront etre donner a GCC sous la forme YYY.a avec la path complet (par exemple ../libs/YYY.a)
#
SRC_A_FILES_NOT_STANDARD:=$(foreach dir,$(SRC_PATH_ALL),$(filter-out $(dir)/$(LIB_PREFIXE)%$(EXTENSION_LIB),$(wildcard $(dir)/*$(EXTENSION_LIB))))

SRC_CPP_FILES := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cpp)) 
SRC_C_FILES := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.c)) 
SRC_CU_FILES  := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cu)) 

OBJ_FILES_CPP:= $(SRC_CPP_FILES:.cpp=.$(OBJ_EXTENSION))
OBJ_FILES_C:= $(SRC_C_FILES:.c=.$(OBJ_EXTENSION))
OBJ_FILES:= ${OBJ_FILES_CPP} ${OBJ_FILES_C}
OBJ_FILES:= $(addprefix $(TARGET_OBJ)/,$(notdir $(OBJ_FILES)))

CU_FILES := $(SRC_CU_FILES:.cu=.$(OBJ_EXTENSION))
CU_FILES := $(addprefix $(TARGET_OBJ)/,$(notdir $(CU_FILES))) 

OBJ_CU_FILES:=$(OBJ_FILES) $(CU_FILES)

#################
# PREPARE FLAGS	#
#################

#only fileName (./libs/libXXX.a ./libs/YYY.so -> lixXXX.a YYY.so)
LIB_FLAG:=$(notdir $(SRC_A_FILES_STANDART))

#removing prefix lib (libXXX.a libYYY.a libZZZ.so -> XXX.a YYY.a ZZZ.so)
LIB_FLAG:=$(subst $(LIB_PREFIXE),,$(LIB_FLAG))#remplace lib par rien

#Delete extension .a (XXX YYY)
LIB_FLAG:=$(LIB_FLAG:$(EXTENSION_LIB)=)

#Delete extension .so (AAA.so BBB.so -> AAA BBB)
LIB_FLAG:=$(LIB_FLAG:$(EXTENSION_DLL)=)

#ADDING user specified lib  (GL GLUT gomp ...)
LIB_FLAG+=$(ADD_LIBRARY_FILES)

# Input :
#	list lib to delete example (AAA ZZZ)
#
#	before : LIB_FLAG (XXX YYY ZZZ)
#	after  : LIB_FLAG (XXX YYY) without ZZZ
LIB_FLAG:=$(filter-out $(EXCLUDE_LIBRARY_FILES),$(LIB_FLAG))

#Adding Lib FLAG separator (XXX YYY -> -lXXX -lYYY)
LIB_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_FLAG_SEPARATOR),$(LIB_FLAG))
LIB_FLAG+=$(CUDA_LIB_FILES_l) $(CULA_LIB_FILES_l)

#Adding Lib path FLAG separator -L (../AAA ./BBB -> -L../AAA _L./BBB)
LIB_PATH:=$(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.so)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override LIB_PATH:=$(call uniq,${LIB_PATH})
#LIB_PATH_FLAG+=$(CUDA_LIB_L) $(CULA_LIB_L)#old
#LIB_PATH_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_PATH_SEPARATOR),$(SRC_PATH_ALL))#old
LIB_PATH_FLAG:=$(addprefix $(OPTION_SEPARATOR)$(LIB_PATH_SEPARATOR),$(LIB_PATH))

#Adding Include FLAG separator
override INC_PATH:=${INC_PATH} $(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.h)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override INC_PATH:=$(call uniq,${INC_PATH})
#${info "INC_PATH= "${INC_PATH}}#print immediately
#SRC_HEADER_I := $(addprefix  $(OPTION_SEPARATOR)I,$(SRC_PATH_ALL))#old
SRC_HEADER_I := $(addprefix  $(OPTION_SEPARATOR)I,$(INC_PATH))
#ALL_HEADERS_I:= $(SRC_HEADER_I)#old 


#Injection variable in .cpp code (VAR1 VAR2 -> -DVAR1 -DVAR2)
CODE_DEFINE_VARIABLES_D:= $(addprefix  -D,$(CODE_DEFINE_VARIABLES))

#override NVCCFLAGS   += $(ALL_HEADERS_I)#old 
override NVCCFLAGS   += $(SRC_HEADER_I) 
override NVCCLDFLAGS += $(LIB_PATH_FLAG) $(LIB_FLAG) $(SRC_A_FILES_NOT_STANDARD)
override CXXFLAGS += $(CODE_DEFINE_VARIABLES_D)

##########
# securite #
##########

#Directory search path (use implicit in rules)
VPATH := $(SRC_PATH_ALL)

##########
# runtime #
##########

space:= #ne suufit pas ajoutre espaca, mais += le fait!
space+=#

ifeq (${OS},Win)
	separateurPath:=;#	
else
	separateurPath:=:#
endif

API_BIN_FORMATTER:=$(subst ${space},${separateurPath},${API_BIN})

ifeq (${OS},Win)
	override PATH:=${PATH}${separateurPath}${API_BIN_FORMATTER}	
	export ${PATH}
else
	override LD_LIBRARY_PATH:=${LD_LIBRARY_PATH}${separateurPath}${API_BIN_FORMATTER}
	export ${LD_LIBRARY_PATH}#fixme semble pas marcher
endif

########
#Optimisation #
########

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/optimisation.mk

########
#arm #
########

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/cudaGCC_arm.mk

##########
# exclude #
##########

override CXXFLAGS:=$(filter-out $(CXXFLAGS_EXCLUDE),$(CXXFLAGS))
override NVCCFLAGS:=$(filter-out $(NVCCFLAGS_EXCLUDE),$(NVCCFLAGS))

#https://www.gnu.org/software/make/manual/make.html#Functions


##########
# unicitye #
##########

UNICITY=true

ifdef UNICITY

	override CXXFLAGS:=$(call uniq,${CXXFLAGS})
	override CXXLDFLAGS:=$(call uniq,${CXXLDFLAGS})
	#override NVCCFLAGS:=$(call uniq,${NVCCFLAGS}) pas possible car enleve -gencode
	override NVCCLDFLAGS:=$(call uniq,${NVCCLDFLAGS})
	override ARFLAGS:=$(call uniq,${ARFLAGS})
	#override AR_OUT_FLAG:=$(call uniq,${AR_OUT_FLAG})
	
	#debug
#${info "CXXFLAGS= "${CXXFLAGS}}#print immediately
#${info "CXXLDFLAGS"= ${CXXLDFLAGS}}#print immediatel
#${info "NVCCLDFLAGS= "${NVCCLDFLAGS}}#print immediatel
#${info "NVCCFLAGS= "${NVCCFLAGS}}#print immediatel
#${info "ARFLAGS= "${ARFLAGS}}#print immediatel
#${info "AR_OUT_FLAG= "${AR_OUT_FLAG}}#print immediatel

endif#UNICITY

##########
# remove space #
##########

#let a minimum of one space
REMOVE_SPACE=true

ifdef REMOVE_SPACE

	override CXXFLAGS:=$(strip ${CXXFLAGS})
	override CXXLDFLAGS:=$(strip ${CXXLDFLAGS})
	override NVCCLDFLAGS:=$(strip ${NVCCLDFLAGS})
	override NVCCFLAGS:=$(strip ${NVCCFLAGS})
	override ARFLAGS:=$(strip ${ARFLAGS})
	#override AR_OUT_FLAG:=$(strip ${AR_OUT_FLAG})#pas pour gcc (enleve espace apres -r)

	#override CXXFLAGS:=$(subst $(space),,$(CXXFLAGS))

endif#REMOVE_SPACE


##########
# bug #
##########

#Adding " " around CXXFLAGS and CXXLDFLAGS, otherwise we can't specifie more than one options !
override CXXFLAGS:=" $(CXXFLAGS) " 
override CXXLDFLAGS:=" $(CXXLDFLAGS) "

###########
#chrono#
###########

override TIME_START:=$(shell date +%T)
TIME_CURRENT=$(shell date +%T)
#TIME_DELTA:=$(shell echo $(TIME_CURRENT) - $(TIME_START) | bc) #marche pas sous win, a tester sous linux

##############################################
#      			  Rules 				     #
##############################################

TITLE:=$(TARGET_NAME)

################
#.o->.run      #
################

$(TARGET) : $(OBJ_CU_FILES)
#@echo "$(NVCC) $(NVCCLDFLAGS) -Xlinker $(CXXLDFLAGS)  $^ -o $(TARGET)"
	@echo ""
	@echo "[CBI] -> Linking to   : "$(TARGET)
	@echo ""
	@echo "[CBI] -> Library Link :"
	@echo "[CBI] ->"  
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call containing,-l,$(NVCCLDFLAGS)))
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call containing,-l,$(CXXLDFLAGS)))
	@echo "" 
	@$(NVCC) $(NVCCLDFLAGS) -Xlinker $(CXXLDFLAGS) $^ -o $(TARGET)
	@echo ""
	@echo "=================================================================================="
	@echo "[CBI] -> Target Name  : "$(TARGET_NAME)
	@echo "[CBI] -> Location     : "$(TARGET)
	@echo "[CBI] -> Deploy 	  : "$(TARGET_DEPLOY_PATH_BIN)
	@echo "[CBI] ->"
	@echo "[CBI] -> Type	 	  : "$(TARGET_MODE)
	@echo "[CBI] -> Arch	 	  : "$(ARCHI_32_64)
	@echo "[CBI] -> OS	 	      : "$(OS)
	@echo "[CBI] -> User	 	  : "$(USER)
	@echo "[CBI] ->"
	@echo "[CBI] -> Compilateur  : ${CXX}) && ${NVCC}"
	@echo "[CBI] -> Task		  : End Compiling-Linking !" 
	@echo "[CBI] -> Time	      : "${TIME_CURRENT} 
	@echo "=================================================================================="
	@echo ""

# -o =outfile
# tabulation obligatoire before @

################
#  .o->.lib    #
################

${TARGET_LIB}:$(OBJ_CU_FILES)
	@${AR} ${AR_OUT_FLAG}${TARGET_LIB} ${ARFLAGS} $^
	@echo ""
	@echo "=================================================================================="
	@echo "[CBI] -> Target Name  : "$(TARGET_NAME)
	@echo "[CBI] -> Location     : "$(TARGET)
	@echo "[CBI] -> Deploy 	  : "$(TARGET_DEPLOY_PATH_BIN)
	@echo "[CBI] ->"
	@echo "[CBI] -> Type	 	  : "$(TARGET_MODE)
	@echo "[CBI] -> Arch	 	  : "$(ARCHI_32_64)
	@echo "[CBI] -> OS	 		  : "$(OS)
	@echo "[CBI] -> User	 	  : "$(USER)
	@echo "[CBI] ->"
	@echo "[CBI] -> Compilateur  : ${CXX}) && ${NVCC}"
	@echo "[CBI] -> Task	      : End Compiling-Archive !" 
	@echo "[CBI] -> Time		  : "${TIME_CURRENT} 
	@echo "=================================================================================="
	@echo ""

################
#   .cpp->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.cpp
#@echo "$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -c $< -o $@"
ifdef ARM
	@echo "[${TITLE}] -> g++ARM compiling .cpp : "$<  	
else
	@echo "[${TITLE}] -> ${CXX} compiling .cpp : "$<
endif
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -o $@ -c $<

# -c = compilation
# -o =outfile

################
#   .c->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.c
#@echo "$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -c $< -o $@"
ifdef ARM
	@echo "[${TITLE}] -> g++ARM compiling .cpp : "$<  	
else
	@echo "[${TITLE}] -> ${CXX} compiling .cpp : "$<
endif
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -o $@ -c $<

# -c = compilation
# -o =outfile

################
#   .cu->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.cu
#@echo "@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler ""$(filter-out -std=c++0x,$(CXXFLAGS))"" -c $< -o $@"
	@echo "[${TITLE}] -> ${NVCC} compiling .cu : "$<
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler ""$(filter-out -std=c++0x,$(CXXFLAGS))"" -c $< -o $@
#cuda6: Il ne faut pas utiliser le flag �std=c++0x lorsque l�on compile un fichier .cu !
#cuda6.5: devrait etre ok
##Adding "" "" around final CXXFLAGS, to keep one " " around final CXXFLAGS , in order to can specifie more than one options !

# -c = compilation
# -o =outfile

##############################################
#      			  TARGET 				     #
##############################################

#all: version help
#all: echoing $(TARGET) deploy
.DEFAULT_GOAL:=all  
all: echoing init $(TARGET) deploy cleanTempCudaFile
	@echo ""
	@echo "[CBI] -> "$(TITLE)"   : End ALL!"

.PHONY: version	
version:
	@echo ""
	@nvcc --version
	@echo ""
	@gcc --version
	@echo ""
	@g++ --version
	@echo ""
	@make --version
	@echo ""
	@bash --version
	@echo ""

.PHONY: help	
help:
	@echo ""
	@nvcc --help
	
##########
# deploy #
##########

.PHONY: deploy	
deploy:
ifdef TARGET_DEPLOY_PATH
	@$(shell cp $(TARGET) $(TARGET_DEPLOY))
	@echo ""
	@echo "[CBI] -> Deploying      : "$(TARGET_DEPLOY)
endif

##########
# run    #
##########

.PHONY: run	
run: printRuntimeInfo
	@echo ""
	@echo "[CBI] -> Running  : "$(TARGET)  $(ARGS)
	@echo ""
	@echo "------------------------------------------------------------------------"
	@echo ""
	@echo ""
	@$(TARGET) $(ARGS)

.PHONY: runDeploy		
runDeploy: printRuntimeInfo
	@echo ""
	@echo "[CBI] -> Running  : "$(TARGET_DEPLOY)  $(ARGS)
	@echo ""
	@echo "------------------------------------------------------------------------"
	@echo ""
	@echo ""
	@$(TARGET_DEPLOY) $(ARGS)	

.PHONY: runGl	
runGl: printRuntimeInfo
	#gl is a wrapper of virtualgl
	#gl is necessary to run opengl remotely with turbovnc
	#OS : linux only
	@echo ""
	@echo "[CBI] -> Running remote-gl : "$(TARGET) $(ARGS)
	@gl $(TARGET) $(ARGS)

.PHONY: runGlDeploy	
runGlDeploy: printRuntimeInfo
	#gl is a wrapper of virtualgl
	#gl is necessary to run opengl remotely with turbovnc
	#OS : linux only!
	@echo ""
	@echo "[CBI] -> Running remote-gl : "$(TARGET_DEPLOY)  $(ARGS)
	@gl $(TARGET_DEPLOY) $(ARGS)


.PHONY: printRuntimeInfo	
printRuntimeInfo:
	@echo "[CBI] -> API BIN      :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh ${sort ${API_BIN}}	
	@echo ""
	@echo "[CBI] -> ARGS         :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh ${sort ${ARGS}}	

##########
# kill   #
##########

#todo a tester
.PHONY: killLinux		
killLinux:
	@echo "[CBI] -> killing : "${TARGET_NAME_EXE}
	@killall ${TARGET_NAME_EXE}
	@echo "[CBI] -> ..."
	@echo "[CBI] -> done!"

##########
# depends #
##########
	
.PHONY: dependenciesLinux
dependenciesLinux: printRuntimeInfo
	@echo ""
	@echo "[${TARGET}] depends from :"
	@echo ""
	@ldd -v ${TARGET_DEPLOY}

##########
# contents #
##########

.PHONY: contentsLinux
contentsLinux:
	@echo ""
ifeq (${TARGET_MODE},STATIC_LIB)	
	@echo "[${TARGET_NAME}.${EXTENSION_LIB}] export :"
	@echo ""
	@ar -t ${TARGET_DEPLOY}
else ifeq (${TARGET_MODE},SHARED_LIB)
	@echo "[${TARGET_NAME}.${EXTENSION_DLL}] export:"
	@echo ""
	@echo "[CBI] -> nm"
	@echo ""
	@nm -D --defined-only --extern--only ${TARGET_DEPLOY}
	@echo ""
	@echo "[CBI] -> readelf"
	@echo ""
	@readelf -s ${TARGET_DEPLOY}
endif	
	@echo ""

##########
# init   #
##########

.PHONY: init	
init:
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_BIN),$(wildcard $(TARGET_BIN) )))
	@$(shell mkdir -p $(TARGET_BIN))
	@echo "[CBI] -> Create folder : "$(TARGET_BIN)
endif
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_OBJ),$(wildcard $(TARGET_OBJ) )))
	@$(shell mkdir -p $(TARGET_OBJ))
	@echo "[CBI] -> Create folder : "$(TARGET_OBJ)
endif
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_CUBIN),$(wildcard $(TARGET_CUBIN) )))
	@$(shell mkdir -p $(TARGET_CUBIN))
	@echo "[CBI] -> Create folder : "$(TARGET_CUBIN)
endif
ifeq (,$(findstring $(TARGET_DEPLOY_PATH_BIN),$(wildcard $(TARGET_DEPLOY_PATH_BIN) )))
	@$(shell mkdir -p $(TARGET_DEPLOY_PATH_BIN))
	@echo "[CBI] -> Create folder : "$(TARGET_DEPLOY_PATH_BIN)
	@echo ""
endif
	@echo ""

##########
# install #
##########

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/install.mk
#same cpp

##########
# doc    #
##########

include ${ROOT_MAKEFILE_PRIVATE_DOC}/doxyCPP.mk

##########
# clean #
##########

.PHONY: clean	
clean:
	@rm -f $(TARGET_OBJ)/*.o
	@rm -f $(TARGET_OBJ)/*.obj
	@rm -f $(TARGET_BIN)/*.exp
	@rm -f $(TARGET_BIN)/*.lib
	@rm -f $(TARGET)
	@rm -f $(TARGET_DEPLOY)
	@rm -f $(TARGET_CUBIN)/*
	@rm -f $(TARGET_DOC_DEPLOY_FILE)
	@rm -f -r $(TARGET_DOC_PATH)
	@echo ""
	@echo "=================================================================================="
	@echo "[CBI] -> Target            : "$(TARGET_NAME)
	@echo "[CBI] -> Task			     : DELETE"
	@echo "[CBI]"
	@echo "[CBI] -> Delete .obj       : "$(TARGET_OBJ)
	@echo "[CBI] -> Delete .bin       : "$(TARGET_BIN)
	@echo "[CBI] -> Delete .cubin     : "$(TARGET_CUBIN)
	@echo "[CBI] -> Delete doc        : "$(TARGET_DOC_PATH)
	@echo "[CBI]"
	@echo "[CBI] -> Delete deploy     : "$(TARGET_DEPLOY)
	@echo "[CBI] -> Delete deploy doc : "$(TARGET_DOC_DEPLOY_FILE)
	@echo "=================================================================================="
	@echo ""

.PHONY: cleanTempCudaFile	
cleanTempCudaFile:
	@rm -f ${TARGET_CUBIN}/*.c
	@rm -f ${TARGET_CUBIN}/*.cpp
	@rm -f ${TARGET_CUBIN}/*.gpu
	@rm -f ${TARGET_CUBIN}/*.i
	@rm -f ${TARGET_CUBIN}/*.ii
	@rm -f ${TARGET_CUBIN}/*.hash
	@rm -f ${TARGET_CUBIN}/*.ptx
#@echo "[CBI] -> Cleaning     : Cuda temp files, excepted .cubin for JCuda"
#@echo ""

#rm -r #serait recursif (dangereux!!)
#rm -f #pas d'erreur si file existe pas!

##########
# echo   #
##########

.PHONY: echoing	
echoing:
	@echo ""
	@echo "=================================================================================="
	@echo "[CBI] -> Target Name  : "$(TARGET_NAME)
	@echo "[CBI] ->"
	@echo "[CBI] -> Build        : "$(TARGET)
	@echo "[CBI] -> Deploy       : "$(TARGET_DEPLOY_PATH_BIN)
	@echo "[CBI] ->"
	@echo "[CBI] -> Type	      : "$(TARGET_MODE)
	@echo "[CBI] -> Arch	      : "$(ARCHI_32_64)
	@echo "[CBI] -> OS	 		  : "$(OS)
	@echo "[CBI] -> User	 	  : "$(USER)
	@echo "[CBI] ->"
	@echo "[CBI] -> Task		  : Compiling-Linking !" 
#@echo "[CBI]->Time           : "${TIME_CURRENT} 
	@echo "=================================================================================="
	@echo ""
	@echo "[CBI] -> SRC AUX (Recursif) :" 
	@echo "[CBI] ->"   
#@echo $(SRC_AUX)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(SRC_AUX)
	@echo "" 
	@echo "[CBI] -> CXXFLAGS (Partial) :"
	@echo "[CBI] ->" 
#@echo $(CXXFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(call not-containing,-I,$(CXXFLAGS)) #sort ko why	
	@echo "" 
	@echo "[CBI] -> CXXLDFLAGS (Partial) :"
	@echo "[CBI] ->" 
#@echo $(CXXLDFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh $(call not-containing,-L, $(call not-containing,-l,$(CXXLDFLAGS))) #sort ko, why?
	@echo "" 
	@echo "[CBI] -> NVCCFLAGS (Partial) :"
	@echo "[CBI] ->" 
#@echo $(NVCCFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh $(sort $(call not-containing,-I,$(NVCCFLAGS)))
	@echo "" 
	@echo "[CBI] -> NVCCLDFLAGS (Partial) :"
	@echo "[CBI] ->"
#@echo $(NVCCLDFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call not-containing,-L, $(call not-containing,-l,$(NVCCLDFLAGS))))
	@echo ""   
	@echo "[CBI] -> INC_PATH (auto detect):"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(INC_PATH))
	@echo "" 
	@echo "" 
	@echo "[CBI] -> LIB_PATH (auto detect):"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(LIB_PATH))
	@echo "" 
	@echo "[CBI] -> LIB_PATH (auto detect):"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(LIB_PATH))
	@echo ""
	@echo "[CBI] -> API_INC :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(API_INC))
	@echo "" 
	@echo "[CBI] -> API_LIB :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(API_LIB))
	@echo "" 
	@echo "[CBI] -> API_BIN :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(API_BIN))
	@echo "" 
	@echo "[CBI] -> API_LIBRARIES :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(API_LIBRARIES))
	@echo ""
	
##############################################
#       			 HELP  				     #
##############################################

# target : dependencies
#
# $@ = name of the target
# $^ = all dependencie of a target
# $< =first (unique dependency of a target) (rm, compilation,linking)
#
# @ = diminue verbosit� commande
#
# Attention : tabulation obligatoire avant commande dans rule!!
#
# http://www.gnu.org/software/make/manual/

#############################################
#       			 END     			    #
#############################################


endif#__MAKE_CUDA_GCC_MK__



