#!/bin/bash
#
# Version:	0.0.2
#

#-----------------------------------------------
#		init
#-----------------------------------------------

set -e

source ./workspace_classification.sh

#-----------------------------------------------
#		doc
#-----------------------------------------------	

echo ""
echo ""
echo ""
echo ""
echo "--------------------------------------------------------------------------------------------------------"
echo "[Doc Workspace]"
echo ""
echo " Workspace       = "${workspaceRoot}
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
		echo "[Doc Cuda Project]"
		echo ""	
		echo "Project           =" ${cuda}		
		echo "Workspace         =" $(pwd)
		echo "----------------------------------------------------------------------------------"		
		cd ./${cuda}

		if [ ${OS} == "Linux" ]
		then
			${MAKE_CUDA_GCC} doc 
		
		elif [ ${OS} == "Win" ]
		then
			cmd.exe //c ${MAKE_CUDA_VISUAL} doc
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
		echo "[Doc CPP Project]"	
		echo ""		
		echo "Project           =" ${cpp}		
		echo "Workspace         =" $(pwd)
		echo "----------------------------------------------------------------------------------"		
		cd ./${cpp}

		if [ ${OS} == "Linux" ]
		then
			${MAKE_GCC} doc 
		
		elif [ ${OS} == "Win" ]
		then
			cmd.exe //c ${MAKE_VISUAL} doc
		fi

		cd ..
	done

echo ""
echo ""	
echo ""
echo ""	
echo "--------------------------------------------------------------------------------------------------------"
echo "[Doc Workspace] "
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



