# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#

ifndef __COMMON_MK__
__COMMON_MK__=true

###############################################
#  					COMMON						  #
###############################################

########################
#   	pivate		   #
########################

API_ROOT:=${ROOT_MAKEFILE_PRIVATE}/api
API:=${API_ROOT}/cpp
API_CUDA:=${API_ROOT}/cuda

############
#API/BILAT #
############

API_BILAT_TOOLS:=${API}/cbi_tools

API_BILAT_FENETRAGE:=${API}/cbi_fenetrage
API_BILAT_OPENGL:=${API}/cbi_opengl

#image
API_BILAT_IMAGE:=${API}/cbi_image
API_BILAT_IMAGE_CUDA:=${API_CUDA}/cbi_image

#graphe2D
API_BILAT_GRAPH2D:=${API}/cbi_graph2d

#multicourbes
API_BILAT_MULTICOURBES_CUDA:=${API_CUDA}/cbi_multicourbes

##############
#dataProject #
##############

include dataProject.mk

########
#c++11 #
########

include ${ROOT_MAKEFILE_PRIVATE_COMMON}/c++11.mk

########################
#   	macro		   #
########################

#http://stackoverflow.com/questions/12315834/makefile-how-to-apply-an-equivalent-to-filter-on-multiple-wildcards
not-containing = $(foreach v,$2,$(if $(findstring $1,$v),,$v))
containing = $(foreach v,$2,$(if $(findstring $1,$v),$v))

#example
#LIST := a_old_tt x_old_da a_new_da q_ty_we
#LIST_OLD := $(call containing,old,$(LIST))
#LIST_NOT_OLD := $(call not-containing,old,$(LIST))

#http://stackoverflow.com/questions/16144115/makefile-remove-duplicate-words-without-sorting

#v1: linux : ko : win : ok
#define uniq =
#	$(eval seen :=)
#	$(foreach _,$1,$(if $(filter $_,${seen}),,$(eval seen += $_)))
#	${seen}
#endef
#exemple
#w := z z x x y c x
#w:=$(call uniq,${w})
#w:=$(strip ${w})
#${info ${w}}#print immediately ww

#v2 : linux ok : win ok
uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))
#exemple
#w := z z x x y c x
#w:=$(call uniq,${w})
#${info ${w}}#print immediately ww

###############################################
#  					End						  #
###############################################

endif#__COMMON_MK__
