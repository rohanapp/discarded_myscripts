@echo off

set currdir=%CD%
set downloaddir=C:\Users\nappann\ANSYSDownloads

REM *** Specify the directory where you have enough disk space to store the installer
REM *** This directory may need to be manually cleaned out periodically
c:
cd %downloaddir%
if errorlevel 1 goto error

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
set artifactorysite=http://canartifactory:8080/artifactory/simple

FOR %%P in (v160_Certified/winx64 v160_EBU_Certified/20140317 v160_Development/Framework_Dev_Certified_Pkgs/winx64) DO (
  echo Start downloading package %%P
  call wget.exe -m -np -nH --cut-dirs=2 --http-user=nappann --http-password=\{DESede\}8jwH8iChqx+Kud7qnvie1A== %artifactorysite%/%%P/ 2>> %wgetlog%
  if errorlevel 1 echo Error occurred during download. Continuing with other packages
  echo Done downloading package %%P
)

echo Done with all package downloads

goto finish

:error
echo Error occurred!

:finish
cd %currdir%
