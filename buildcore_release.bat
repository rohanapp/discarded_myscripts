@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error

call buildsln_release64.bat Core

cd ..\..
if errorlevel 1 goto error

goto finish

:error
echo Unable to cd to nextgen

:finish
