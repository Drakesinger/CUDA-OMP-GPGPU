#!/bin/bash
#
# Version:	0.0.2
#

#-----------------------------------------------
#		Functions 
#-----------------------------------------------


		if [ $# -gt 0 ]
		then

			#rien
			echo ""
			echo ""$@
			echo ""
	
		else
			echo ""
			echo "ERROR : Missing executable!"
			echo ""
			echo "HELP  : Input examples"
			echo ""
			echo "    gcc all"
			echo "    visual all"
			echo "    intel all"
			echo "    mingw all"
			echo "    cuda all"
			echo ""
			echo "    gcc clean"
			echo "    gcc uninstall"
			echo "    gcc uninstallcxx"
			echo ""	
			echo "    gcc installInc installSrc"
			echo "    gcc doc installDoc"
			echo ""	
			echo "    gcc arm jetson all"
			echo ""	
	
			exit
		fi
		

#-----------------------------------------------
#		end
#-----------------------------------------------


