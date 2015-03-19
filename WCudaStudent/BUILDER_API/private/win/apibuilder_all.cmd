@echo off

REM 0.0.5
REM Cedric.bilat@he-arc.ch

REM -----------------------
REM - 	example Input     -
REM -----------------------

REM visual uninstall
REM visual all doc

REM -----------------------
REM - 	    main	      -
REM -----------------------

@call shRuntime.cmd
@call path.cmd

pushd ..\common

bash apibuilder_all.sh

echo.

popd

REM -----------------------
REM - 	    END	          -
REM -----------------------


pause
