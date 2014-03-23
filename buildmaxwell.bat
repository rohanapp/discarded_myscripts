@echo off

set cwd=%CD%
echo cd nextgen\ansoftcore
cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildsln_debug64.bat Core All_Core

echo cd ..
cd ..
if errorlevel 1 goto error

call buildsln_debug64.bat maxwelllight

echo cd ansoftcore
cd ansoftcore
if errorlevel 1 goto error
call buildsln_release64.bat Core All_Core

echo cd ..
cd ..
if errorlevel 1 goto error

call buildsln_release64.bat maxwelllight


goto finish

:error
echo Unable to cd to nextgen

:finish
cd %cwd%
