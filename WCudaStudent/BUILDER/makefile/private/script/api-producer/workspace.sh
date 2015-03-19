#!/bin/bash
#
# Version:	0.0.2
#


#-----------------------------------------------
#		Functions Workspace
#-----------------------------------------------

#-----------------------------
#		Functions private
#-----------------------------

function printTime()
	{
	echo -n " Time           = "
	date +"%T"
	}

# va global used : 
#
#	$projectList	
#	$CBICC_OPTIONS
#
function printCommon()
	{
	echo ""
	echo "=============================================================================================================="
	echo "[Compiling Workspace]"
	echo ""
	echo " List Project/Install-Path :"
	echo ""
	
	printList $projectList
	
	echo ""
	echo " Options        = "${CBICC_OPTIONS}
	}

# va global used : 
#
#	$projectList	
#	$CBICC_OPTIONS
#
function titleStart()
	{
	printCommon
	echo " State          = Please wait ..."
	printTime
	echo "=============================================================================================================="
	}

# va global used : 
#
#	$projectList	
#	$CBICC_OPTIONS
#	
function titleEnd()
	{
	printCommon
	echo " State          = Success!"
	printTime
	echo "=============================================================================================================="
	echo ""
	}

#-----------------------------
#		Functions public
#-----------------------------

# va global used : 
#
#	$projectList	
#	$CBICC_OPTIONS
#
function processWorkspace()
	{
	OLD_PWD=$(pwd)
	
	#go woorkspaceroot
	#cd ../../..
	cd ${ROOT_WORKSPACE}
	
	titleStart

	for project in ${projectList}
		do
			processProject
		done

	titleEnd
	
	cd $OLD_PWD
	}

#-----------------------------------------------
#		end
#-----------------------------------------------


