#!/bin/bash
#
# version	: 0.0.1
# author	: cedric.bilat@he-arc.ch


# ---------------------------------------
#		Init
#----------------------------------------

set -e

# ---------------------------------------
#		Projets
#----------------------------------------

projet1=BilatTools_CPP
projet2=BilatTools_Cuda
projet3=BilatTools_Cuda_Image
projet4=BilatTools_Cuda_smart_switch
projet5=BilatTools_Image
projet6=BilatTools_intel_MKL
projet7=BilatTools_OMP
projet8=BilatTools_OpenCV
projet9=BilatUtil_CPP

# ---------------------------------------
#		List Projets (export)
#----------------------------------------

export listProjet="    $projet1                            $projet5 $projet6 $projet7 $projet8 $projet9"
export listProjetCuda="$projet1 $projet2 $projet3 $projet4          $projet6 $projet7 $projet8 $projet9"

# listProjet     : inc pour projet non cuda
# listProjetCuda : inc pour projet cuda
# Attention : exclusif! Raison pour laquelle un meme projet peut apparaitre dans les deux listes!

# ---------------------------------------
#		end
#----------------------------------------
