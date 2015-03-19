#!/bin/bash
#
# Version:	0.0.2
#

set -e

#-----------------------------------------------
#		Input
#-----------------------------------------------

#rien

#------------------------------------------------------------------------------------
#		Principe
#------------------------------------------------------------------------------------

# Jar side:
#
#	un jar (unique)
#   contenant : 
#		class java (standard)
#		un file properties avec les names des shared lib (astuce), toutes!
#
# Build side:
#
#	un file properties avec names all shared lib
#	ant inject good name in propertie file just before make jar, in particular :
#			-version (conetnu dans namefile)
#
# Java side:
#
#	java Loader detect 
#			os
#			architecture
#			compliateur (see -Dcxx ci-dessous)
#	lors du runtime, et cherche dans properties le name de la shared lib aproprier a loader
#
# User side:
#
#	Lancemnet de la jvm
#
#	 	java -Dcxx= visual ou intel ou gcc
#
#	pour indiquer compilateur
#

#------------------------------------------------------------------------------------
#		Main
#------------------------------------------------------------------------------------

#source ./jni_XXX.sh

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------


