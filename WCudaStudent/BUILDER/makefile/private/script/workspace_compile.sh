#!/bin/bash
#
# Version:	0.0.2
#

set -e

#-----------------------------------------------
#		Input
#-----------------------------------------------

#$1: compilateur

#linux
#	gcc
#	intellinux
#
#windows
#	visual
#	intelwin
#	mingw



#-----------------------------------------------
#		init
#-----------------------------------------------

source ./workspace_classification.sh

#-----------------------------------------------
#		check
#-----------------------------------------------

if [ -z $1 ]
then

	if [ ${OS} == "Linux" ]
	then
		echo "[ERROR] : .sh : input missing : gcc or intellinux"		
	 
	elif [ ${OS} == "Win" ]
	then
		echo "[ERROR] : .sh : input missing : visual or intelwin or mingw"
	fi
	
	exit
fi

compilateur=$1

#-----------------------------------------------
#		compile
#-----------------------------------------------

echo ""
echo ""
echo ""
echo ""
echo "--------------------------------------------------------------------------------------------------------"
echo "[Compiling Workspace]"
echo ""
echo " Workspace       = "${workspaceRoot}
echo " Compilateur     = "${compilateur}
echo " State           = Please wait ..."
echo -n " Time            = "
date +"%T"
echo "--------------------------------------------------------------------------------------------------------"


for cuda in ${setCUDA}
	do
		echo ""
		echo ""	
		echo ""
		echo ""	
		echo "----------------------------------------------------------------------------------"
		echo "[Compiling Cuda Project]"
		echo ""	
		echo "Project           =" ${cuda}		
		echo "Workspace         =" $(pwd)
		echo "Compilateur       = g++ && nvcc"	
		echo "----------------------------------------------------------------------------------"		
		cd ./${cuda}
		
		if [ ${OS} == "Linux" ]
		then
			${MAKE_CUDA_GCC} all 
		
		elif [ ${OS} == "Win" ]
		then
			cmd.exe //c ${MAKE_CUDA_VISUAL} all
		fi
		
		cd ..
	done

for cpp in ${setCPP}
	do
		echo ""
		echo ""	
		echo ""
		echo ""		
		echo "----------------------------------------------------------------------------------"
		echo "[Compiling CPP Project]"	
		echo ""		
		echo "Project           =" ${cpp}		
		echo "Workspace         =" $(pwd)
		echo "Compilateur       = ${compilateur}"
		echo "----------------------------------------------------------------------------------"		
		cd ./${cpp}
		
		if [ ${OS} == "Linux" ]
		then

			if  [ ${compilateur} == "gcc" ]
			then
				${MAKE_GCC} all 

			elif [ ${compilateur} == "intellinux" ]
			then
				${MAKE_INTEL_LINUX} all 
			fi

		elif [ ${OS} == "Win" ]
		then

			if  [ ${compilateur} == "visual" ]
			then
				cmd.exe //c ${MAKE_VISUAL} all 

			elif [ ${compilateur} == "intelwin" ]
			then
				cmd.exe //c ${MAKE_INTEL_WIN} all  

			elif [ ${compilateur} == "mingw" ]
			then
				cmd.exe //c ${MAKE_MINGW} all  
			fi
			
		fi

		cd ..
	done

for intel in ${setIntel}
	do
		echo ""
		echo ""	
		echo ""
		echo ""		
		echo "----------------------------------------------------------------------------------"
		echo "[Compiling CPP-intel only Project]"	
		echo ""		
		echo "Project           =" ${cpp}		
		echo "Workspace         =" $(pwd)
		echo "Compilateur       = icpp"
		echo "----------------------------------------------------------------------------------"		
		cd ./${intel}
	
		if [ ${OS} == "Linux" ]
		then
			${MAKE_INTEL_LINUX} all 
		
		elif [ ${OS} == "Win" ]
		then
			cmd.exe //c ${MAKE_INTEL_WIN} all
		fi

		cd ..
	done

echo ""
echo ""	
echo ""
echo ""	
echo "--------------------------------------------------------------------------------------------------------"
echo "[Compiling Workspace]"
echo ""
echo " Workspace = "${workspaceRoot}
echo " State           = Success!"
echo -n " Time            = "
date +"%T"
echo "--------------------------------------------------------------------------------------------------------"
echo ""
echo ""	
echo ""
echo ""

#-----------------------------------------------
#		end
#-----------------------------------------------


