#!/bin/bash
#
# Version:	0.0.2
#

#http://www.cyberciti.biz/faq/bash-shell-script-function-examples/

#-----------------------------------------------
#		Functions Project
#-----------------------------------------------

# va global used : 
#
#	$projectName	
#	$CBICC_OPTIONS_SMART
#
#	Si projet cuda, remplace intel/gcc par cuda dans CBICC_OPTIONS
#	si projet intel, remplace gcc/cuda par intel dans CBICC_OPTIONS
#
function cbiccOptionsSmart()
		{
		#http://www.patpro.net/blog/index.php/2006/04/07/20-manipulations-sur-les-variables-dans-bash/
		
		#cuda project
		if [[ ${projectName} == *Cuda* ]] 
		then
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/gcc/cuda}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/intel/cuda}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/visual/cuda}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/mingw/cuda}
				
		#only intel
		elif [[ ${projectName} == *Intel* ]] 
		then
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/gcc/intel}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/cuda/intel}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/visual/intel}
			CBICC_OPTIONS_SMART=${CBICC_OPTIONS_SMART/mingw/intel}	
		fi
		}

# va global used : 
#
#	$project	
#	$CBICC_OPTIONS
#
function processProject()
		{
		#http://stackoverflow.com/questions/10520623/how-to-split-one-string-into-multiple-variables-in-bash-shell
		#separateur :

		projectName=$(echo $project | cut -d':' -f1)
		export INSTALL_PATH=$(echo $project | cut -d':' -f2)
		#export car INSTALL_PATH use dans makefile
	
		CBICC_OPTIONS_SMART=$CBICC_OPTIONS
		cbiccOptionsSmart
		
		echo ""		
		echo "----------------------------------------------------------------------------------"	
		echo "Project           =" ${projectName}	
		echo "CIBCC Options     =" ${CBICC_OPTIONS_SMART}		
		echo "InstallPath       =" ${INSTALL_PATH}		
		echo "----------------------------------------------------------------------------------"		
		
		WORKSPACE_ROOT=$(pwd)
		
		cd ./${projectName}
		
		cbicc $CBICC_OPTIONS_SMART
	
		echo ""
		
		#cd - #verbeux dommage
		cd $WORKSPACE_ROOT
		}

#-----------------------------------------------
#		end
#-----------------------------------------------


