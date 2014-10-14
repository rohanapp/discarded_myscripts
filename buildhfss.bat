@echo off

set cwd=%CD%
echo cd build\OfficialSln
cd build\OfficialSln
if errorlevel 1 goto error
call buildsln_debug64.bat Core All_Core


call buildsln_debug64.bat MCAD
call buildsln_debug64.bat 3D-UI

call buildsln_release64.bat Core All_Core


call buildsln_debug64.bat MCAD
call buildsln_release64.bat 3D-UI

cd ..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
