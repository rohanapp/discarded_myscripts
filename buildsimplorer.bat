@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildsln_debug Core

cd lib\ZipUtilities
if errorlevel 1 goto error
call buildsln_debug ZipUtilities

cd ..\..\..
if errorlevel 1 goto error

call buildsln_debug CircuitEditors
call buildsln_debug Simplorer

cd ansoftcore
if errorlevel 1 goto error
call buildsln_release Core

cd lib\ZipUtilities
if errorlevel 1 goto error
call buildsln_release ZipUtilities

cd ..\..\..
if errorlevel 1 goto error

call buildsln_release CircuitEditors
call buildsln_release Simplorer


goto finish

:error
echo Unable to cd to nextgen

:finish
