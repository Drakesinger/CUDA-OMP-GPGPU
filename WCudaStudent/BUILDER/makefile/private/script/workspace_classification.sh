#!/bin/bash
#
# Version:	0.0.3
# Date:		04.03.2014
#
# link:
#	http://www.cyberciti.biz/faq/unix-linux-extract-filename-and-extension-in-bash/
#	http://stackoverflow.com/questions/2625976/sorting-space-delimited-numbers-with-linux-bash
#	http://stackoverflow.com/questions/3236871/how-to-return-a-string-value-from-a-bash-function

#-----------------------------------------------
#		init
#-----------------------------------------------

set -e

source ./workspace_os_management.sh

#-----------------------------------------------
#		CLassification Project
#-----------------------------------------------

#buildable
setCUDA=""
setCPP=""
setIntel=""

#buildable: os specific only
setLinux=""
setWin=""

#not buildable
setETUDE=""

setDataProject=$(find ${workspaceRoot} -name 'dataProject.mk')

for filePath in ${setDataProject}
	do
		
		folderPath=${filePath%/*}
		folder=${folderPath##*/}
	
		#echo ${filePath}
		#echo "folderPath = " ${folderPath}
		#echo "folder     = " ${folder}
		
		if [ -d ./${folder} ] # test si folder est bien sun sous folder de workspaceRoot
		then

			#Etude
			if [[ ${folder} == *Etude* ]] 
			then
 				setETUDE="${setETUDE} ${folder}"
			fi

			#Os specific
			if [[ ${folder} == *Linux* ]] 
			then
				setLinux="${setLinux} ${folder}"

			elif [[ ${folder} == *Win* ]] 
			then
				setWin="${setWin} ${folder}"
			fi
			
			#GCC, INTEL ou Cuda
			if [[ ${folder} == *Cuda* ]] 
			then
				setCUDA="${setCUDA} ${folder}"
			
			elif [[ ${folder} == *Intel* ]] 
			then
				setIntel="${setIntel} ${folder}"

			else
				setCPP="${setCPP} ${folder}"
			fi
		fi

	done

#-----------------------------------------------
#		ensemble operation
#-----------------------------------------------

# result=$1 - $2
# ie, ce qui est dans $1 mais pas dans $2
#
# Example:
# 	un='a b c d e'
# 	deux='e c'
# 	result=$(sub "$un" "$deux")
# 	echo "result=" $result # donne a b d
function sub()
	{
	input1=$1
	input2=$2
	
	for e1 in $1
	do
		isFound=false		
		for e2 in $2
		do
			if [[ $e1 == $e2 ]]
			then
				isFound=true				
				break
			fi
		done	
		#echo "[ $isFound $e2 ]"
		if [[ $isFound != true ]]
		then
			echo ${e1}
		fi
	done
	}

#soustarction de Etude
setCPP=$(sub "$setCPP" "$setETUDE")
setIntel=$(sub "$setIntel" "$setETUDE")
setCUDA=$(sub "$setCUDA" "$setETUDE")

#soustarction de os specific
if [[ $OS == "Linux" ]]
then
	setCPP=$(sub "$setCPP" "$setWin")
	setIntel=$(sub "$setIntel" "$setWin")
	setCUDA=$(sub "$setCUDA" "$setWin")

elif [[ $OS == "Win" ]]
then
	setCPP=$(sub "$setCPP" "$setLinux")
	setIntel=$(sub "$setIntel" "$setLinux")
	setCUDA=$(sub "$setCUDA" "$setLinux")
fi

#-----------------------------------------------
#		sort
#-----------------------------------------------

#setCPP=$(printf "%s\n" $setCPP | sort -n)
function sorting()
	{
	input=$@
	result=$(printf "%s\n" $input | sort -n)
	echo $result
	}

setCPP=$(sorting "$setCPP")
setCUDA=$(sorting "$setCUDA") 
setETUDE=$(sorting "$setETUDE") 
setIntel=$(sorting "$setIntel") 
setLinux=$(sorting "$setLinux") 
setWin=$(sorting "$setWin") 

#-----------------------------------------------
#		show classification
#-----------------------------------------------

function printing()
	{
	echo ""
	
	input=$@
	for element in ${input}
	do
		echo "    " ${element}
	done

	echo ""
	}

echo ""
echo "--------------------------------------------------------------------------------------------------------"
echo "[Classification of project]"
echo ""
echo " Workspace       = "${workspaceRoot}
echo " State           = Please wait ..."
echo -n " Time            = "
date +"%T"
echo "--------------------------------------------------------------------------------------------------------"
echo ""

echo "[CUDA] Projects :"
printing $setCUDA

echo "[CPP] Projects  :"
printing $setCPP

echo "[CPP_Intel] Projects  :"
printing $setIntel

echo "[Linux] Projects : "
printing $setLinux

echo "[WIN] Projects : "
printing $setWin

echo "[ETUDE] Projects: (not build here)"
printing $setETUDE

#Liasser de temps au user de voir classification
echo ""
echo "Pause ..."
sleep 2

#-----------------------------------------------
#		end
#-----------------------------------------------


