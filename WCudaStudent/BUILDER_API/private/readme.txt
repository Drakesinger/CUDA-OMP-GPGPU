
readme

--------------------------------------------------
Definitions
--------------------------------------------------

api: 	list de projets
pack :	list api
all:	all compilateur

--------------------------------------------------
cycle global
--------------------------------------------------

	apibuilder_all.sh -> apibuilderPack.sh ->apibuilder.sh

ou

	apibuilderPack.sh ->apibuilderPack.sh -> ->apibuilder.sh

Notes:
------

	(N1) apibuilderPack requiert en input:
	
			- compilateur
			- target makefile

--------------------------------------------------
cycle linux
--------------------------------------------------

	apibuilder_all.sh ->apibuilder_all.sh -> apibuilderPack.sh ->apibuilder.sh

ou 

	apibuilderPack.sh ->apibuilderPack.sh -> ->apibuilder.sh

Notes : 
-------

	(N1) les deux premières couches sont presque les même à l'exception du lancement de 
		
			- cbirt 
		 
		 necessaire pour obtenir les variables home de destination finale dans la première couche
	

	
--------------------------------------------------
cycle windows
--------------------------------------------------

	apibuilder_all.cmd ->apibuilder_all.sh -> apibuilderPack.sh ->apibuilder.sh

ou 

	apibuilderPack.cmd -> apibuilderPack.sh -> apibuilder.sh

Notes : 
-------

	(N1) les deux premières couches sont presque les même à l'exception du lancement de 
		
			- api64.cmd
			- api64.cmd 
		 
		 necessaire pour obtenir les variables home de destination finale. La première couche passe de windows à linux

--------------------------------------------------
end
--------------------------------------------------