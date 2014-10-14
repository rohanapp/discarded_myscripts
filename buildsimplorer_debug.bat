@echo off

set buildcore=1
if "%1"=="nocore" set buildcore=0

cd build\OfficialSln
if errorlevel 1 goto error
if %buildcore%==1 (
  call buildsln_debug64.bat Core All_Core

)

call buildsln_debug64.bat Simplorer


cd ..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
