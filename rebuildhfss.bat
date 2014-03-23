@echo off

set cwd=%CD%
call cleanderived
if errorlevel 1 goto error
call buildhfss
if errorlevel 1 goto error

goto finish

:error
echo Unable to cd to nextgen

:finish
cd %cwd%
