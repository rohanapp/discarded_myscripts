@echo off

set currdir=%CD%

call config.cmd
if errorlevel 1 (
  echo Error occured during invocation of config.cmd. Make sure this file exists/runs
  goto error
)

%tempdirdrive%:
if errorlevel 1 goto error

cd %tempdir%
if errorlevel 1 goto error

set glewfile=glew-1.10.0-win32.zip
call wget.exe --no-check-certificate -np -nd https://sourceforge.net/projects/glew/files/glew/1.10.0/%glewfile%/download

if errorlevel 1 (
  echo wget failed
  goto error
)

REM !!!Extract to %tempdir%\glewextract folder!!!
call "%progpath1%\WINZIP64.exe" -e .\%glewfile% glewextract
if errorlevel 1 (
  echo Extraction using winzip failed
  goto error
)

goto finish

:error echo Error occured

:finish
cd %currdir%
