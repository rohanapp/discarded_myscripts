@echo off

set buildcore=1
if "%1"=="nocore" set buildcore=0

cd build\OfficialSln
if %buildcore%==1 (
  call buildsln_release64.bat Core All_Core

)

call buildhfss_release.bat nocore
call buildsln_release64.bat Designer-UI


cd ..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
