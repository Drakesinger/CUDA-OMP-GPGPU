# Version 	: 0.0.6
# Date		: 20.01.2014
# Author 	: Cedric.Bilat@he-arc.ch

ifndef __C++11_MK__
__C++11_MK__=true


#-std=gnu++0x ou -std=c++0x, difference? 

#########################
# 		 WINDOWS		#
#########################

ifeq ($(OS),Win)

############
# Visual   #
############

ifeq ($(COMPILATEUR),VISUAL)

	#rien, par default
	
endif

############
# Intel   #
############

ifeq  ($(COMPILATEUR),INTEL)

	#rien, par default
	
endif

############
# MINGW   #
############

ifeq  ($(COMPILATEUR),MINGW)
	
	override CXXFLAGS:= -std=c++0x ${CXXFLAGS}
	#To access C++11 threads in Windows, you will need a build of Mingw with posix-threads. 
	
endif

endif#end win

#########################
# 		 LINUX			#
#########################

ifeq ($(OS),Linux)

############
# ARM   #
############

ifeq  ($(ARCH),arm)

	override CXXFLAGS:= -std=c++0x ${CXXFLAGS}

endif

############
# GCC   #
############

ifeq  ($(COMPILATEUR),g++)

	override CXXFLAGS:= -std=c++0x ${CXXFLAGS}
	
endif

############
# INTEL   #
############

ifeq  ($(COMPILATEUR),INTEL)

	override CXXFLAGS:= -std=c++0x ${CXXFLAGS}
	
endif

endif#linux


#############################################
#       			 END     			    #
#############################################

endif#__C++11_MK__
