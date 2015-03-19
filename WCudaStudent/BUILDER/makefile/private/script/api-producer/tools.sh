#!/bin/bash
#

# ---------------------------------------
#               Function tools
#----------------------------------------

function printList()
	{	
	local PROJECT_LIST=$@
	
	for PROJECT in $PROJECT_LIST
		do
		
			#http://stackoverflow.com/questions/10520623/how-to-split-one-string-into-multiple-variables-in-bash-shell
			#separateur :

			local PROJECT_NAME=$(echo $PROJECT | cut -d':' -f1)
			local INSTALL_PATH=$(echo $PROJECT | cut -d':' -f2)
			
			echo -e "\t${PROJECT_NAME}\t\t${INSTALL_PATH}"
		done	
	}		

# ---------------------------------------
#               end
#----------------------------------------
