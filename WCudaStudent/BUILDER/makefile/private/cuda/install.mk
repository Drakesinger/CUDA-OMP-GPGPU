# Version 	: 0.0.7
# Date		: 04.03.2014
# Author 	: Cedric.Bilat@he-arc.ch

ifndef __INSTALL_MK__
__INSTALL_MK__=true

##################################################
# 				install							 #
##################################################

# idem cpp


###############################
# 				variable	  #
###############################

INSTALL_PATH_INC:=$(INSTALL_PATH)/INC
INSTALL_PATH_DOC:=$(INSTALL_PATH)/DOC
INSTALL_PATH_BIN:=$(INSTALL_PATH)/BIN/$(NAME_COMPILATEUR_INSTALL)
INSTALL_PATH_LIB_STATIC:=$(INSTALL_PATH)/LIB_STATIC/$(NAME_COMPILATEUR_INSTALL)
INSTALL_PATH_LIB_DLL:=$(INSTALL_PATH)/LIB/$(NAME_COMPILATEUR_INSTALL)
INSTALL_PATH_SRC:=$(INSTALL_PATH)/SRC

ifeq ($(OS),Win)
	#avant 	c:/Soft_API/ext/...
	#apres:	/C/Soft_API/ext/...
	
	#INSTALL_PATH_INC_RSYNC:=$(subst c:, /C,${INSTALL_PATH_INC})
	INSTALL_PATH_INC_RSYNC:=$(subst ${DRIVE_INSTALL}:, /${DRIVE_INSTALL},${INSTALL_PATH_INC})   
else
	INSTALL_PATH_INC_RSYNC:=${INSTALL_PATH_INC}
endif

###############################
# 				rule	  #
###############################

.PHONY: install
install: installTitle installBin installInc installSrc installDoc

.PHONY: installBin
installBin: 
#ifeq (($(TARGET_MODE),SHARED_LIB) OR ($(TARGET_MODE),EXE))
ifeq ($(TARGET_MODE),$(filter $(TARGET_MODE),SHARED_LIB EXE))
	@mkdir -p ${INSTALL_PATH_BIN}
	@echo "[CBI] ->      - Binaries        : $(TARGET_DEPLOY)"
	@cp $(TARGET_DEPLOY) ${INSTALL_PATH_BIN}
endif
ifeq ($(TARGET_MODE),STATIC_LIB)	
	@mkdir -p ${INSTALL_PATH_LIB_STATIC}
	@echo "[CBI] ->      - Static Lib      : $(TARGET_DEPLOY)"
	@cp $(TARGET_DEPLOY) ${INSTALL_PATH_LIB_STATIC}
endif
#windows only
#lib associe a dll (import lib)
ifeq ($(OS),Win)
ifeq ($(TARGET_MODE),SHARED_LIB)  	
	@mkdir -p ${INSTALL_PATH_LIB_DLL}
	@echo "[CBI] ->      - Lib (from DLL)  : $(TARGET_NAME_LIB_DLL)"
	@cp $(TARGET_NAME_LIB_DLL) ${INSTALL_PATH_LIB_DLL}
endif
endif

#http://ubuntuforums.org/archive/index.php/t-1240150.html
#http://www.computerhope.com/unix/rsync.htm
# cp --parents -r -v $$srcINC/**/*.h $(INSTALL_PATH)/inc; \

.PHONY: installInc
installInc:
	@mkdir -p $(INSTALL_PATH_INC)
	@for srcINC in $(PATH_INC_INSTALL); \
	do \
		echo "[CBI] ->      - Include         : $$srcINC"; \
		rsync -amr --include='*.h' -f 'hide,! */' $$srcINC/  $(INSTALL_PATH_INC_RSYNC); \
	done
.PHONY: installDoc
installDoc:
	@mkdir -p $(INSTALL_PATH_DOC)
	@echo "[CBI] ->      - Doxygen         : $(TARGET_DOC_FINAL)"
	@cp -r $(TARGET_DOC_FINAL)/html/* $(INSTALL_PATH_DOC);
	
.PHONY: installSrc
installSrc:	
ifeq ($(SRC_INSTALL),true)
	@mkdir -p $(INSTALL_PATH_SRC)
	@echo "[CBI] ->      - Src             : ./src"
	@cp -r ./src/* $(INSTALL_PATH_SRC); 
endif	

.PHONY: installTitle
installTitle:	
	@echo ""
	@echo "------------------------------------------------------------------------"
	@echo "[CBI] -> Installing             : $(TARGET_NAME)"
	@echo "------------------------------------------------------------------------"
	@echo ""
	@echo "[CBI] -> Destination : "
	@echo "[CBI] ->      - Binaries        : $(INSTALL_PATH_BIN)"
	@echo "[CBI] ->      - Static Lib      : $(INSTALL_PATH_LIB_STATIC)"
	@echo "[CBI] ->      - Include         : $(INSTALL_PATH_INC)"
	@echo "[CBI] ->      - Doxygen         : $(INSTALL_PATH_DOC)"
	@echo "[CBI] ->      - Src             : $(INSTALL_PATH_SRC)"
	@echo ""
	@echo "[CBI] -> Source : "
		
##################################################
# 				uninstall							 #
##################################################

.PHONY: uninstall
uninstall:
	@echo "[CBI] -> Uninstalling    : $(TARGET_NAME)"
	@echo "[CBI] -> Cleaning        : "$(PATH_INSTALL_API_VERSION)
	@rm -r -f $(PATH_INSTALL_API_VERSION)
# -r recursif
# -f pas d'erreur si file existe pas


.PHONY: uninstallcxx
uninstallcxx:
	@echo "[CBI] -> Uninstalling    : $(TARGET_NAME)"
	@echo "[CBI] -> Cleaning        : "$(INSTALL_PATH_BIN)
	@rm -r -f $(INSTALL_PATH_BIN)
# -r recursif
# -f pas d'erreur si file existe pas

##################################################
# 				end							 #
##################################################

endif#__INSTALL_MK__


