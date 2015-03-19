#!/bin/bash
#
# Version:	0.0.2
#

#-----------------------------------------------
#		init
#-----------------------------------------------

#stop des erreur
set -e

#racine workspace
cd ../../../..
#ls
#sleep 100000

workspaceRoot=$(pwd)


#-----------------------------------------------
#		os management
#-----------------------------------------------

echo "--------------------------------------------------------------------------------------------------------"
echo "[OS Management]"
echo ""

if [ $(uname) == "Linux" ]
then
	OS=Linux
	echo "Linux detect"
else
	OS=Win
	echo "Windows detect"
fi

#if [ ${OS} == "Linux" ]
#then
	#echo "Linux init"	
	#source /usr/local/etc/cbi/dev/init/cbiMakeInit.sh
#else
	#echo "Windows init"
	#cmd.exe //c G:/CBI/HEARC/SoftLocal/ScriptLaucher/makefile/makeInit.cmd#ko why?
#fi

echo "--------------------------------------------------------------------------------------------------------"
echo ""
echo ""
echo ""
echo ""

#-----------------------------------------------
#		end
#-----------------------------------------------


