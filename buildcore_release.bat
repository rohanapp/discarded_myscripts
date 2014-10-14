@echo off

cd build\OfficialSln
if errorlevel 1 goto error

call buildsln_release64.bat Core


cd ..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
