
@echo off

REM 0.0.5
REM Cedric.bilat@he-arc.ch

REM -----------------------
REM - 	    path	      -
REM -----------------------

set PATH_API_EXT=C:\Soft_API\ext
set PATH_API_CBI=C:\Soft_API\cbi

set PATH=%PATH%;%PATH_API_EXT%;%PATH_API_CBI%

REM -----------------------
REM - 	    api	      -
REM -----------------------

REM bidon sert a rien, mais script aime pas si va vide
set COMPILATEUR=visual
set GPU=on

@call API64.cmd
@call API64_CBI.cmd

REM -----------------------
REM - 	    END	          -
REM -----------------------





