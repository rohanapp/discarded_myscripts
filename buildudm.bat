@echo off

set cwd=%CD%
cd nextgen\lib\geometrycore\UserDefinedModels
if errorlevel 1 goto error

:startbuild
call buildsln_debug64.bat UserDefinedModels

call buildsln_release64.bat UserDefinedModels

cd ..\..\..\..

goto finish

:error
echo Unable to cd to nextgen\lib\geometrycore\UserDefinedModels


:finish

cd %cwd%
