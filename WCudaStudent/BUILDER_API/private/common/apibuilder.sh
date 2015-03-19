#!/bin/bash
#
# Version:	0.0.2
#

set -e


#------------------------------------------------------------------------------------
#		Path
#------------------------------------------------------------------------------------

export ROOT_WORKSPACE=../../..

#ROOT_SCRIPT=../../../BUILDER/makefile/private/script/api-producer
#ROOT_PUBLIC_DATA=../../public

#------------------------------------------------------------------------------------
#		Input
#------------------------------------------------------------------------------------

#input : api compilateur target-makefile

api=$1
shift

# shift pour enlever api !
# now :  $@ = compilateur target-makefile

#echo "api = $api"
#echo "compilation info = $@"

#------------------------------------------------------------------------------------
#		configure
#------------------------------------------------------------------------------------

OS=$(uname)
CXX=$1

#-----------------------------------------------
#		data project
#-----------------------------------------------

source ${ROOT_PUBLIC_DATA}/${api}

#provide
#	API_HOME
#	API_VERSION
#	API_LIST_PROJECT
#	API_LIST_PROJECT_PROJECT_NAME

#echo "API_HOME                      = $API_HOME"
#echo "API_VERSION                   = $API_VERSION"
#echo "API_LIST_PROJECT              = $API_LIST_PROJECT"
#echo "API_LIST_PROJECT_PROJECT_NAME = $API_LIST_PROJECT_PROJECT_NAME"

#-----------------------------------------------
#		private
#-----------------------------------------------

if [[ ${OS} == *Linux* ]] 
then
	export PATH_INSTALL_API_VERSION=${API_HOME}/${API_VERSION}
else
	# avant: C:/Soft_API/ext/CppTest/002
	# apres: /C:/Soft_API/ext/CppTest/002
	export PATH_INSTALL_API_VERSION=/${API_HOME}/${API_VERSION}
	
	# avant: /C:/Soft_API/ext/CppTest/002
	# apres: /C/Soft_API/ext/CppTest/002
	export PATH_INSTALL_API_VERSION=${PATH_INSTALL_API_VERSION/:/}
fi

#add path to project list 
#format :	nameProject:installPath
projectList=""
i=1
for projectFile in ${API_LIST_PROJECT}
		do
			#echo "i=$i"
			#https://viewsby.wordpress.com/2012/09/14/awk-split-string-using-a-delimiter/
			#http://www.unix.com/shell-programming-and-scripting/176447-awk-print-using-variable.html
			# echo "abc:def:poi:loi:lkj:kjh" | awk -F':' '{print $2}'#donne def
			#aaa=$(echo "abc:def:poi:loi:lkj:kjh" | awk -F':' '{print $2}')
			
			projetName=$(echo "$API_LIST_PROJECT_PROJECT_NAME" | awk -v b=$i '{print $b'})
			
			if [[ $projetName == "NULL" ]]
			then
				pathinstall=$PATH_INSTALL_API_VERSION
			else
				pathinstall=$PATH_INSTALL_API_VERSION/${projetName}
			fi
			
			#echo "process $projectFile"
			#echo "pathinstall=$pathinstall"
			
			projectList="$projectList $projectFile:$pathinstall"
			i=$((i+1))
		done
	
	
#echo "projectList"$projectList
#exit 	
		
#------------------------------------------------------------------------------------
#		run
#------------------------------------------------------------------------------------

source ${ROOT_SCRIPT}/wbuild.sh

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------


