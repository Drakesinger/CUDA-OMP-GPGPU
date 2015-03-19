# Version 	: 0.0.7
# Date		: 17.01.2014
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __DOXYGEN_MK__
__DOXYGEN_MK__=true

##############################################
#   			 Variables     				 #
##############################################

TARGET_DOC_PATH:=${TARGET_PATH}/doc

TARGET_DOC_TEMP:=${TARGET_DOC_PATH}/temp
TARGET_DOC_FINAL:=${TARGET_DOC_PATH}/final
TARGET_DOC_DEPLOY:=${TARGET_DEPLOY_PATH_DOC}
TARGET_DOC_NAME=$(TARGET_NAME).doc.tar.gz
TARGET_DOC_DEPLOY_FILE:=$(TARGET_DOC_DEPLOY)/$(TARGET_DOC_NAME)

-include ${ROOT_MAKEFILE}/public/doc/doxygen.mk

##############################################
#      			  Set  				     #
##############################################

DOX_SRC_FINAL:= $(filter-out $(DOX_SRC_EXCLUDE),$(DOX_SRC))
#https://www.gnu.org/software/make/manual/make.html#Functions

##############################################
#      			  TARGET 				     #
##############################################


######################
#        Doxygen     #
######################

.PHONY: doc
doc: docTitleStart docTools docPurge docPrepare docConfig docBuild docDeploy docTitleEnd

.PHONY: docTitleStart	
docTitleStart:
	@echo "=================================================================================="
	@echo "[CBI] -> Target              : "$(TARGET_NAME)
	@echo "[CBI] -> Task			     : Doc"
	@echo "[CBI] -> Doc src			 : "${DOX_SRC_FINAL} 
	@echo "[CBI] -> Directory doc html  : "${TARGET_DOC_FINAL}
ifdef IS_DEPLOY
	@echo "[CBI] -> Directory doc tar   : "$(TARGET_DOC_DEPLOY)
endif
	@echo "=================================================================================="
	@echo ""

.PHONY: docTitleEnd	
docTitleEnd:
	@echo ""
	@echo "=================================================================================="
	@echo "[CBI] -> Target              : "$(TARGET_NAME)
	@echo "[CBI] -> Task			     : Doc"
	@echo "[CBI] -> Doc src		     : "${DOX_SRC_FINAL}
	@echo "[CBI] -> Directory doc html  : "${TARGET_DOC_FINAL}
ifdef IS_DEPLOY
	@echo "[CBI] -> Directory doc tar   : "$(TARGET_DOC_DEPLOY)
endif
	@echo "=================================================================================="

.PHONY: docTools		
docTools:
	@echo "[Tools]"
	@echo ""
	@echo "doxygen version : "
	@doxygen --version
	@dot -V
	@echo ""

.PHONY: docPurge	
docPurge:
	@echo "[Purge]"
	@echo ""
	@echo "delete " $(TARGET_DOC_PATH)
	@echo "delete " $(TARGET_DOC_DEPLOY_FILE)
	@rm -f -r $(TARGET_DOC_PATH)
	@rm -f $(TARGET_DOC_DEPLOY_FILE)
	@echo ""

.PHONY: docPrepare	
docPrepare:
	@echo "[Prepare]"
	@echo ""
	@echo "mkdir " $(TARGET_DOC_FINAL)
	@echo "mkdir " $(TARGET_DOC_TEMP)
	@mkdir -p $(TARGET_DOC_FINAL)
	@mkdir -p ${TARGET_DOC_TEMP}
ifdef IS_DEPLOY
	@echo "mkdir " $(TARGET_DOC_DEPLOY)
	@mkdir -p $(TARGET_DOC_DEPLOY)
endif	
	@echo ""	

.PHONY: docConfig	
docConfig:
	@echo "[Configuration]"
	@doxygen -g $(TARGET_DOC_TEMP)/doxyFileDefaultTMP
	@echo "Parse and fill defaut doxy-config with project-specific-config ..."
	@echo ""
#DO NOT MODIFY THE SPACE at left of the first =
#Choice for separateur sed is ;
	@sed -e 's;My Project;$(TARGET_NAME);' \
	-e 's;INPUT                  =;INPUT                  = $(DOX_SRC_FINAL);' \
	-e 's;CREATE_SUBDIRS         = NO;CREATE_SUBDIRS         = $(DOX_CREATE_SUBDIRS);' \
	-e 's;OUTPUT_DIRECTORY       =;OUTPUT_DIRECTORY       = \"$(TARGET_DOC_FINAL)\";' \
	-e 's;RECURSIVE              = NO;RECURSIVE              = $(DOX_RECURSIVE);' \
	-e 's;OUTPUT_LANGUAGE        = English;OUTPUT_LANGUAGE        = $(DOX_OUTPUT_LANGUAGE);' \
	-e 's;GENERATE_LATEX         = YES;GENERATE_LATEX         = $(DOX_GENERATE_LATEX);'	\
	-e 's;CLASS_DIAGRAMS         = YES;CLASS_DIAGRAMS         = $(DOX_CLASS_DIAGRAMS);' \
	-e 's;EXTRACT_ALL            = NO;EXTRACT_ALL            = $(DOX_EXTRACT_ALL);' \
	-e 's;UML_LOOK               = NO;UML_LOOK               = $(DOX_UML_LOOK);' \
	-e 's;CALL_GRAPH             = NO;CALL_GRAPH             = $(DOX_CALL_GRAPH);' \
	-e 's;CALLER_GRAPH           = NO;CALLER_GRAPH           = $(DOX_CALLER_GRAPH);' \
	-e 's;EXTRACT_PRIVATE        = NO;EXTRACT_PRIVATE        = $(DOX_EXTRACT_PRIVATE);' \
	-e 's;HAVE_DOT               = NO;HAVE_DOT               = $(DOX_HAVE_DOT);' $(TARGET_DOC_TEMP)/doxyFileDefaultTMP >$(TARGET_DOC_TEMP)/doxyFileProjectTMP
#-e 's;INPUT                  =;INPUT                  = $(SRC_PATH_ALL) $(SRC_AUX);' \

.PHONY: docBuild
docBuild:
	@echo "[Build]"
	@echo ""
	@doxygen $(TARGET_DOC_TEMP)/doxyFileProjectTMP
	@echo ""

.PHONY: docDeploy	
docDeploy:
ifdef TARGET_DEPLOY_PATH
	@echo "[Deploy]"
	@echo ""
	@echo "creating "$(TARGET_NAME).doc.tar
ifeq ($(OS),Linux)
	@tar -cf  ${TARGET_DOC_TEMP}/$(TARGET_NAME).doc.tar -C ${TARGET_DOC_FINAL} .
	@echo "creating "$(TARGET_NAME).doc.tar.gz
	@gzip -q  ${TARGET_DOC_TEMP}/$(TARGET_NAME).doc.tar   ${TARGET_DOC_TEMP}/$(TARGET_NAME).doc.tar.gz
	@echo "moving   "$(TARGET_NAME).doc.tar.gz" -> "$(TARGET_DOC_DEPLOY)
	@mv -f $(TARGET_DOC_TEMP)/$(TARGET_NAME).doc.tar.gz $(TARGET_DOC_DEPLOY)
else
#@tar -cf '${TARGET_DOC_TEMP}/$(TARGET_NAME).doc.tar' -C ${TARGET_DOC_FINAL} .
#q: pose problem!
	@tar -cf  ${TARGET_DOC_DEPLOY}/$(TARGET_NAME).doc.tar -C ${TARGET_DOC_FINAL} .
	@echo "creating "$(TARGET_NAME).doc.tar.gz
	@gzip -q  ${TARGET_DOC_DEPLOY}/$(TARGET_NAME).doc.tar   ${TARGET_DOC_DEPLOY}/$(TARGET_NAME).doc.tar.gz
#@echo "moving   "$(TARGET_NAME).doc.tar.gz" -> "$(TARGET_DOC_DEPLOY)
#@mv -f $(TARGET_NAME).doc.tar.gz $(TARGET_DOC_DEPLOY)
endif
endif

.PHONY: docShow
docShow:
	@echo "show " ${TARGET_DOC_FINAL}/html/index.html
	@chrome ${TARGET_DOC_FINAL}/html/index.html

#############################################
#       			 END     			    #
#############################################

endif#__DOXYGEN_MK__

