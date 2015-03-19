# Version 	: 0.0.8
# Date		: 01.08.2014
# Author 	: Cedric.Bilat@he-arc.ch
#
# See 		: OptionCompilateur.txt
#
# Hyp		: Application that must be in path
#				nvcc
#				mingw32-make
#				cl
#
# 			:  Environement Variables must be set
#
#				ARCHI_32_64			:	32 or 64

ifndef __MAKE_VISUAL_CUDA_MK__
__MAKE_VISUAL_CUDA_MK__=true


##############################################
#   			 Variables     				 #
##############################################

########
# Path #
########

SRC_ROOT   :=src
TARGET_OBJ:=${TARGET_PATH}/obj
TARGET_BIN:= ${TARGET_PATH}/bin
TARGET_CUBIN:=${TARGET_PATH}/cubin

#synonime ameliorer
TARGET_BIN_PATH:=${TARGET_BIN}
TARGET_OBJ_PATH:=${TARGET_OBJ}

#TARGET_DEPLOY_PATH_BIN=${TARGET_DEPLOY_PATH}/bin
TARGET_DEPLOY_PATH_DOC=${TARGET_DEPLOY_PATH}/doc

########
# cpp #
########

CXX=cl

NAME_COMPILATEUR:=visual_cuda
NAME_COMPILATEUR_INSTALL:=visual_cuda

########
# Cuda #
########

NVCC := nvcc
PTXAS_FLAGS := -fastimul
OBJ_EXTENSION:=obj
OPTION_SEPARATOR:=-#attention, end without space
LINK_FLAG_DLL:=-shared#attention,end without space

########
#32/64 #
########

#plus necessaire
#ifeq ($(ARCHI_32_64),64)
	# override NVCCFLAGS+= -m64#default -m64 #dans public
	#override CXXLDFLAGS+= /MACHINE:X64 #Deprecated! 	#En plus posait probl�me de guillement (� la d�finition de CXXLDFLAGS)
#endif

##############
#TARGET_NAME #
##############

#obtain NVCC_VERSION
SCRIPT=${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/cudaVersion.sh
NVCC_VERSION:=$(shell $(SCRIPT))

TARGET_NAME:=${TARGET_NAME}_$(NAME_COMPILATEUR)_$(NVCC_VERSION)_$(ARCHI_32_64)

#############
# Extension  #
#############

EXTENSION_OBJ:=obj#
EXTENSION_LIB:=lib#
EXTENSION_DLL:=dll#
EXTENSION_EXE:=exe#
# Note enstension sans le .

##########
# TARGET #
##########

LIB_PREFIXE:=#rien

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
	TARGET_NAME_LIB_DLL:=$(TARGET_BIN_PATH)/${TARGET_NAME}.lib
	
	override NVCCLDFLAGS += $(LINK_FLAG_DLL)
endif

ifeq ($(TARGET_MODE),STATIC_LIB)
	TARGET:=${TARGET_LIB}
	TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_LIB)
endif


###########
#Extension#
###########

#ifeq ($(TARGET_MODE),SHARED_LIB)
#	override NVCCLDFLAGS+= $(LINK_FLAG_DLL) 
#	TARGET_NAME_FULL=$(TARGET_NAME).dll
#endif

#ifeq ($(TARGET_MODE),EXE)
#	TARGET_NAME_FULL=$(TARGET_NAME).exe
#endif

#TARGET:=$(TARGET_BIN)/$(TARGET_NAME_FULL)
#TARGET_DEPLOY:=$(TARGET_DEPLOY_PATH_BIN)/$(TARGET_NAME_FULL)

##########
#ARCHIVEUR#
###########

AR:=lib
ARFLAGS=# pas= car valeur vaut rv avant sous windows ???
AR_OUT_FLAG:=/OUT:#Sans espace

############
# Params   #
############

#ameliorer deja avant mais sans .
EXTENSION_LIB:=.lib
EXTENSION_DLL:=.dll
#LIB_PREFIX:=#pas de prefixe

############
#Set files #
############

#Hyp : Shell sh
SRC_PATH:=$(shell find $(SRC_ROOT) -type d)	
ifdef SRC_AUX
	SRC_PATH_AUX:=$(shell find $(SRC_AUX) -type d)
else
	SRC_PATH_AUX:=
endif

SRC_PATH_ALL:=$(SRC_PATH) $(SRC_PATH_AUX)

SRC_CPP_FILES := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cpp)) 
SRC_C_FILES := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.c)) 
SRC_CU_FILES  := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.cu)) 
SRC_LIB_FILES := $(foreach dir,$(SRC_PATH_ALL),$(wildcard $(dir)/*.lib)) $(ADD_LIBRARY_FILES)

#################
# PREPARE FLAGS #
#################

#ifneq (, $(findstring openmp,$(CXXFLAGS)))#findstring return vide si openmp pas trouver!
#	ADD_LIBRARY_FILES+=libiomp5md.lib 

#Delete extension .lib
SRC_LIB_FILES:= $(SRC_LIB_FILES:$(EXTENSION_LIB)=)

SRC_LIB_FILES_l:= $(addprefix $(OPTION_SEPARATOR)l,$(notdir $(SRC_LIB_FILES))) 
#ALL_LIB_FILES_l:= $(CUDA_LIB_FILES_l) $(CULA_LIB_FILES_l) $(SRC_LIB_FILES_l)
ALL_LIB_FILES_l:= $(SRC_LIB_FILES_l)

LIB_PATH:=$(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.lib)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override LIB_PATH:=$(call uniq,${LIB_PATH})
#SRC_LIB_L:=$(addprefix $(OPTION_SEPARATOR)L,$(SRC_PATH_ALL))#old
SRC_LIB_L:=$(addprefix $(OPTION_SEPARATOR)L,$(LIB_PATH))

#ALL_LIB_L:=$(SRC_LIB_L) $(CUDA_LIB_L) $(CULA_LIB_L)
ALL_LIB_L:=$(SRC_LIB_L)


override INC_PATH:=${INC_PATH} $(foreach dir,$(SRC_PATH_ALL),$(dir $(wildcard $(dir)/*.h)))#dir extract directory of file,  $(wildcard $(dir)/*.h)=> take file.h if exist
override INC_PATH:=$(call uniq,${INC_PATH})
#${info "INC_PATH= "${INC_PATH}}#print immediately
#SRC_HEADER_I := $(addprefix  $(OPTION_SEPARATOR)I,$(SRC_PATH_ALL))#old
SRC_HEADER_I := $(addprefix  $(OPTION_SEPARATOR)I,$(INC_PATH))
#ALL_HEADERS_I:= $(SRC_HEADER_I)#old 

OBJ_FILES_CPP:= $(SRC_CPP_FILES:.cpp=.$(OBJ_EXTENSION))
OBJ_FILES_C:= $(SRC_C_FILES:.c=.$(OBJ_EXTENSION))
OBJ_FILES:= ${OBJ_FILES_CPP} ${OBJ_FILES_C}
OBJ_FILES:= $(addprefix $(TARGET_OBJ)/,$(notdir $(OBJ_FILES)))

CU_FILES := $(SRC_CU_FILES:.cu=.$(OBJ_EXTENSION))
CU_FILES := $(addprefix $(TARGET_OBJ)/,$(notdir $(CU_FILES))) 

OBJ_CU_FILES:=$(OBJ_FILES) $(CU_FILES)

#Injection variable in .cpp code (VAR1 VAR2 -> -DVAR1 -DVAR2)
CODE_DEFINE_VARIABLES_D:= $(addprefix  -D,$(CODE_DEFINE_VARIABLES))

#override NVCCFLAGS   += $(ALL_HEADERS_I)#old 
override NVCCFLAGS   += $(SRC_HEADER_I) 
override NVCCLDFLAGS += $(ALL_LIB_L) $(ALL_LIB_FILES_l)
override CXXFLAGS += $(CODE_DEFINE_VARIABLES_D)

ifneq (, $(findstring /MD,$(CXXFLAGS)))#findstring return vide si /MD pas trouver!
	override CXXLDFLAGS+= /NODEFAULTLIB:LIBCMT
endif

#Adding " " around CXXFLAGS and CXXLDFLAGS, otherwise we can't specifie more than one options !
#override CXXFLAGS:=" $(CXXFLAGS) " 
#override CXXLDFLAGS:=" $(CXXLDFLAGS) "
#plus tard apres optimisation

##########
# securite #
##########

#Directory search path(use implicit in rules)
VPATH := $(SRC_PATH_ALL)

########
#Optimisation #
########

include ${ROOT_MAKEFILE_PRIVATE_CUDA}/optimisation.mk

##########
# exclude #
##########

override NVCCFLAGS:=$(filter-out $(NVCCFLAGS_EXCLUDE),$(NVCCFLAGS))
override CXXFLAGS:=$(filter-out $(CXXFLAGS_EXCLUDE),$(CXXFLAGS))

#https://www.gnu.org/software/make/manual/make.html#Functions

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
	override PATH:=${PATH}${separateurPath}${API_BIN_FORMATTER}#
	export ${PATH}#
else
	override LD_LIBRARY_PATH:=${LD_LIBRARY_PATH}${separateurPath}${API_BIN_FORMATTER}#
	export ${LD_LIBRARY_PATH}#fixme semble pas marcher
endif

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
	#override AR_OUT_FLAG:=$(call uniq,${AR_OUT_FLAG})#met espace apres /out, pas pour visual/intel

#debug
#${info "CXXFLAGS= "${CXXFLAGS}}#print immediately
#${info "CXXLDFLAGS"= ${CXXLDFLAGS}}#print immediatel
#${info "NVCCFLAGS= "${NVCCFLAGS}}#print immediatel
#${info "NVCCLDFLAGS= "${NVCCLDFLAGS}}#print immediatel
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
	#override AR_OUT_FLAG:=$(strip ${AR_OUT_FLAG}) #pas pour mingw car enleve espace apres -r

	#override CXXFLAGS:=$(subst $(space),,$(CXXFLAGS))

endif#REMOVE_SPACE

##########
# bug #
##########

#Adding " " around CXXFLAGS and CXXLDFLAGS, otherwise we can't specifie more than one options !
override CXXFLAGS:=" $(CXXFLAGS) " 
override CXXLDFLAGS:=" $(CXXLDFLAGS) "

###########
# chrono  #
###########

override TIME_START:=$(shell date +%T)
TIME_CURRENT=$(shell date +%T)
#TIME_DELTA:=$(shell echo $(TIME_CURRENT) - $(TIME_START) | bc) #marche pas

######################
#        Rules       #
######################

TITLE:=$(TARGET_NAME)

################
#.o->.exe,.dll #
################

$(TARGET) : $(OBJ_CU_FILES)
#@echo "$(NVCC) $(NVCCLDFLAGS)  -Xlinker $(CXXLDFLAGS)  $^ -o $(TARGET)"
	@echo ""
	@echo "[CBI] -> Linking to   : "$(TARGET)
	@echo ""
	@echo "[CBI] -> Library Link :"
	@echo "[CBI] ->"  
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call containing,-l,$(NVCCLDFLAGS)))
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call containing,-l,$(CXXLDFLAGS)))
	@echo "" 
	@$(NVCC) $(NVCCLDFLAGS) -Xlinker  $(CXXLDFLAGS)  $^ -o $(TARGET)
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
	@echo "[CBI] -> Compilateur  : VISUAL (${CXX}) && NVIDIA (${NVCC})"
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
#@echo "${AR} ${AR_OUT_FLAG}${TARGET_LIB} ${ARFLAGS} $^"
	@echo ""
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
	@echo "[CBI] -> Compilateur  : VISUAL (${CXX}) && NVIDIA (${NVCC})"
	@echo "[CBI] -> Task	      : End Compiling-Archive !" 
	@echo "[CBI] -> Time		  : "${TIME_CURRENT} 
	@echo "=================================================================================="
	@echo ""

################
#   .cpp->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.cpp
#@echo "$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -c $< -o $@"
#@echo "[${TITLE}] -> ${CXX} compiling .cpp : "$<
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS)  $@ -c $<

# -c = compilation
# -o =outfile

################
#   .c->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.c
#@echo "$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS) -c $< -o $@"
#@echo "[${TITLE}] -> ${CXX} compiling .c   : "$<
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler $(CXXFLAGS)  $@ -c $<

# -c = compilation
# -o =outfile

################
#   .cu->.o   #
################

$(TARGET_OBJ)/%.$(OBJ_EXTENSION) :%.cu
#@echo "$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler ""$(filter-out -std=c++0x,$(CXXFLAGS))"" -c $< -o $@"
#@echo "[${TITLE}] -> ${NVCC} compiling .cu : "$<
	@$(NVCC) $(NVCCFLAGS) -odir $(TARGET_OBJ) -Xcompiler ""$(filter-out -std=c++0x,$(CXXFLAGS))"" -c $< -o $@
#cuda6: Il ne faut pas utiliser le flag �std=c++0x lorsque l�on compile un fichier .cu !
#cuda6.5: devrait etre ok
##Adding "" "" around final CXXFLAGS, to keep one " " around final CXXFLAGS , in order to can specifie more than one options !
#$(filter-out pas necesaire with visual&intel windows

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
	@cl 

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
	@echo "[CBI] -> Deploying    : "$(TARGET_DEPLOY) 
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


.PHONY: printRuntimeInfo	
printRuntimeInfo:
	@echo ""
	@echo "[CBI] -> API BIN      :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh ${sort ${API_BIN}}	
	@echo ""
	@echo "[CBI] -> ARGS         :"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh ${sort ${ARGS}}	

##########
# kill   #
##########

.PHONY: killWin
killWin:
	@echo "[CBI] -> killing : "${TARGET_NAME_EXE}
	@powershell stop-process -processname ${TARGET_NAME}
	@echo "[CBI] -> ..."
	@echo "[CBI] -> done"!


##########
# depends #
##########
	
.PHONY: dependenciesWin
dependenciesWin:	printRuntimeInfo
	@echo ""
	@echo "[CBI] -> Dependencies .dll : "${TARGET}
	@${DEPENDS_EXE} ${TARGET_DEPLOY}

##########
# contents #
##########

.PHONY: contententsWin
contententsWin:	printRuntimeInfo
	@echo ""
	@echo "[CBI] -> Dependencies .dll : "${TARGET_NAME_EXE}
	@${DEPENDS_EXE} ${TARGET_DEPLOY}

##########
# init   #
##########

.PHONY: init	
init:
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_BIN),$(wildcard $(TARGET_BIN) )))
	@$(shell mkdir -p $(TARGET_BIN))
	@echo "[CBI] -> Create folder  : "$(TARGET_BIN)
endif
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_OBJ),$(wildcard $(TARGET_OBJ) )))
	@$(shell mkdir -p $(TARGET_OBJ))
	@echo "[CBI] -> Create folder  : "$(TARGET_OBJ)
endif
#create folder heirerarchy TARGET_BIN_PATH iff don't exist
ifeq (,$(findstring $(TARGET_CUBIN),$(wildcard $(TARGET_CUBIN) )))
	@$(shell mkdir -p $(TARGET_CUBIN))
	@echo "[CBI] -> Create folder  : "$(TARGET_CUBIN)
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
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh $(call not-containing,-I,$(CXXFLAGS)) #sort kp, why
	@echo "" 
	@echo "[CBI] -> CXXLDFLAGS (Partial) :"
	@echo "[CBI] ->" 
#@echo $(CXXLDFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh $(call not-containing,-L, $(call not-containing,-l,$(CXXLDFLAGS)))   #sort ko why?
	@echo "" 
	@echo "[CBI] -> NVCCFLAGS (Partial) :"
	@echo "[CBI] ->" 
#@echo $(NVCCFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call not-containing,-I,$(NVCCFLAGS)))
	@echo "" 
	@echo "[CBI] -> NVCCLDFLAGS (Partial) :"
	@echo "[CBI] ->"  
#@echo $(NVCCLDFLAGS)
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(call not-containing,-L, $(call not-containing,-l,$(NVCCLDFLAGS))))
	@echo ""  
	@echo "[CBI] -> INC_PATH (auto detect):"
	@${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/print.sh  $(sort $(INC_PATH))
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

endif#__MAKE_VISUAL_CUDA_MK__
