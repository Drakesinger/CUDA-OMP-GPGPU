# Version 	: 0.0.6
# Date		: 20.01.2014
# Author 	: Cedric.Bilat@he-arc.ch

ifndef __OPTIMISATION_MK__
__OPTIMISATION_MK__=true


##############################################
#   			 Optimisation  				 #
##############################################

ifneq (${ARCH},arm)	
	
	ifneq (${DEBUG},true)
		override CXXFLAGS+= ${CXX_OPTIMISATION}
		override CXXFLAGS+= ${X86_CXX_OPTIMISATION}
	else#debug
		#todo
	endif

else #ARM
	ifneq (${DEBUG},true)
		override CXXFLAGS+= ${CXX_OPTIMISATION}
	else#debug
		#todo
	endif
endif

#############################################
#       			 END     			    #
#############################################

endif#__OPTIMISATION_MK__
