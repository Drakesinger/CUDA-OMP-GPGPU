
@echo off

REM 0.0.5
REM Cedric.bilat@he-arc.ch



echo.
echo ----------------------------------------------------------------------------------
echo sh runtime : init
echo ----------------------------------------------------------------------------------
echo.

REM -----------------------
REM - 	    config	      -
REM -----------------------

set PATH_INIT=G:\CBI\HEARC\SoftLocal\ScriptLaucher

REM -----------------------
REM - 	    main	      -
REM -----------------------

REM Version1
REM set PATH_CURRENT=%cd%
REM cd %PATH_INIT%
REM @call cbict.cmd
REM cd %PATH_CURRENT%

REM Version2 (http://ss64.com/nt/pushd.html)
pushd %PATH_INIT%
@call cbict.cmd
popd

echo.
echo ----------------------------------------------------------------------------------
echo sh runtime : ready
echo ----------------------------------------------------------------------------------
echo.

REM -----------------------
REM - 	    END	          -
REM -----------------------





