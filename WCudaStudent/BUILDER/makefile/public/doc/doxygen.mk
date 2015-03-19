# Version :	0.0.1 
# Date : 	20.01.2014
#
# Installation (Linux):
#
#		sudo apt-get install doxygen
#		sudo apt-get install graphviz
#

ifndef __CUDA_DOXYGEN_MK__
__CUDA_DOXYGEN_MK__=true

#################################################
#					SRC							#
#################################################

#recursif
DOX_SRC:=$(SRC_ROOT) $(SRC_AUX)
#DOX_SRC:=$(SRC_ROOT)

#recursif
DOX_SRC_EXCLUDE:= $(SRC_AUX)

#################################################
#		General Doxygen configuration			#
#################################################

DOX_CREATE_SUBDIRS:=YES

#Other supported language: French, German, look the Doxyfile document for more
DOX_OUTPUT_LANGUAGE:=English

#Generate the latex files for the documentation. Need to compile to create the pdf
DOX_GENERATE_LATEX:=NO

#Look recursively into directories
DOX_RECURSIVE:=YES

DOX_EXTRACT_PRIVATE:=NO

#########################################
#		Configuration of Dot (graph)	#
#########################################

#Define if you have the software 'dot' 
DOX_HAVE_DOT:=YES

#Display the class diagram
DOX_CLASS_DIAGRAMS:=YES

#Required to display the class diagram in UML
DOX_EXTRACT_ALL:=YES

#UML look for the diagram
DOX_UML_LOOK:=YES

#For a methode, generate a  graph for every sub methode used. TAKE A LOT OF TIME
DOX_CALL_GRAPH:=NO

#For a methode, generate a graph which contain the methode using the current methode. TAKE A LOT OF TIME
DOX_CALLER_GRAPH:=NO

#########################################
#		End 							#
#########################################

endif#__CUDA_DOXYGEN_MK__