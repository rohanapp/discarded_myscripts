@echo off

REM Use below if you need drive of current directory
REM set currdrive=%CD:~0,2%
set currdir=%CD%

REM See buildexecs.bat for comments about "SCRIPT CONFIGURATION"

set thisfiledir=%~dp0%
set configcmd=%thisfiledir%config.cmd
REM !!!!REVISIT!!!!!
call %configcmd%
if errorlevel 1 (
  echo Error occured during invocation of config.cmd. Make sure this file exists/runs
  goto error
)

set downloaddir=%artifact_download_dir%

REM *** Specify the directory where you have enough disk space to store the installer
REM *** This directory may need to be manually cleaned out periodically
c:
cd %downloaddir%
if errorlevel 1 (
  echo '%artifact_download_dir%' does not exist
  goto error
)

set wgetlog=wget_output.txt
IF EXIST %wgetlog% (
  call del %wgetlog%
  if errorlevel 1 (
    echo Unable to delete %wgetlog%
    goto error
  )
)

echo Starting all package downloads...

REM set cut-dirs to be at least 2 to avoid artifactory/simple download-folder-structure

FOR %%P in (v160_Certified/winx64 v160_EBU_Certified/%ebucertbuilddate% v160_Development/Framework_Dev_Certified_Pkgs/winx64) DO (
  echo Start downloading package %%P
  call %wgetdir%\wget.exe -m -np -nH --cut-dirs=2 --http-user=%username% --http-password=%userpasswd% %artifactorysite%/%%P/ 2>> %wgetlog%
  if errorlevel 1 echo Error occurred during download. Continuing with other packages
  echo Done downloading package %%P
)

echo Done with all package downloads

goto finish

:error
echo Error occurred!

:finish
cd %currdir%
