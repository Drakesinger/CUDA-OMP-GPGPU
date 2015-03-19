#!/bin/bash
#


# ---------------------------------------
#                input
#----------------------------------------

# $@ : all para
# $1 : premier para
# $2 : second para

# ---------------------------------------
#               private
#----------------------------------------

# Use from sh:
#
# 	source ${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/cudaVersion.sh
#
# 	versionNVCC=$(cudaVersion)
# 	echo $versionNVCC #donne 65
#
# Use from makefile:
#	
#	SCRIPT=${ROOT_MAKEFILE_PRIVATE_COMMON_SCRIPT}/cudaVersion.sh
#	NVCC_VERSION:=$(shell $(SCRIPT))
#
# Validite:
#
#	cuda60 : ok
#	cuda65 : ok
# 
# Exemple:
#
# 	nvcc --version donne
#
# 	nvcc: NVIDIA (R) Cuda compiler driver
# 	Copyright (c) 2005-2014 NVIDIA Corporation
# 	Built on Thu_Jul_17_21:41:27_CDT_2014
# 	Cuda compilation tools, release 6.5, V6.5.12
#
function cudaVersion()
	{
	local ligne=$(nvcc --version | grep release)
	#echo $ligne #Cuda compilation tools, release 6.5, V6.5.12

	#http://stackoverflow.com/questions/10520623/how-to-split-one-string-into-multiple-variables-in-bash-shell
	#separateur ,

	local release=$(echo $ligne | cut -d',' -f2) # f2 prend le deuxièeme element parser par ,
	#echo $release #release 6.5

	local version=$(echo $release | cut -d' ' -f2) #f2 prend le deuxièeme element parser par ,
	#echo $version#6.5

	#http://stackoverflow.com/questions/10520623/how-to-split-one-string-into-multiple-variables-in-bash-shell
	#remplace . par rien
	versionINT=${version/./''}
	#echo $versionINT#65

	#http://www.linuxjournal.com/content/return-values-bash-functions
	#return with command substitution technique
	echo $versionINT
	}

export NVCC_VERSION=$(cudaVersion)

#pour utilisation depuis makefile:
#cette ligne exporte $NVCC_VERSION

echo $NVCC_VERSION

# ---------------------------------------
#               end
#----------------------------------------
