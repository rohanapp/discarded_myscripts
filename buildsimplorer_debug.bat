@echo off

set buildcore=1
if "%1"=="nocore" set buildcore=0

cd nextgen
if errorlevel 1 goto error
if %buildcore%==1 (
  cd ansoftcore
  if errorlevel 1 goto error
  call buildsln_debug64.bat Core All_Core

  cd ..
  if errorlevel 1 goto error
)

call buildsln_debug64.bat Simplorer


goto finish

:error
echo Unable to cd to nextgen

:finish
