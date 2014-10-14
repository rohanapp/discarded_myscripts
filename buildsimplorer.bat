@echo off

cd build\OfficialSln
call buildsln_debug Core

cd lib\ZipUtilities
if errorlevel 1 goto error
call buildsln_debug ZipUtilities


call buildsln_debug CircuitEditors
call buildsln_debug Simplorer

call buildsln_release Core

cd lib\ZipUtilities
if errorlevel 1 goto error
call buildsln_release ZipUtilities


call buildsln_release CircuitEditors
call buildsln_release Simplorer


cd ..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
