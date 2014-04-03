@echo off

set currwd=%CD%

REM See buildexecs.bat for comments about "SCRIPT CONFIGURATION"

call config.cmd
if errorlevel 1 (
  echo Error occured during invocation of config.cmd. Make sure this file exists/runs
  goto error
)

%repodrive1%:
if errorlevel 1 (
  echo Invalid drive letter in repodrive1: %repodrive1%
  goto error
)

echo Trying to cd to git views
echo cd %repodir1%\%1
cd %repodir1%\%1
if errorlevel 1 goto tryc
echo This is a git view
goto founddir

:tryc
echo Trying git views on %repodrive2% drive
%repodrive2%:
echo cd %repodir2%\%1
cd %repodir2%\%1
if errorlevel 1 goto error
goto founddir

:founddir
set validProj=0
if %2 == designer set validProj=1
if %2 == hfss set validProj=1
if %2 == addin set validProj=1
if %2 == reporter set validProj=1 
if %2 == modeler set validProj=1 
if %2 == maxwell set validProj=1 
if %2 == udm set validProj=1 
if %2 == djob set validProj=1 
if %2 == statespacefitter set validProj=1 
if %2 == core set validProj=1 
if %2 == maxcirc set validProj=1 
if %2 == simplorer set validProj=1 

if %validProj% EQU 0 goto error_proj

if %2 == designer call builddesigner_release.bat %3
if %2 == hfss call buildhfss_release.bat %3
if %2 == addin call buildaddin_release.bat
if %2 == reporter call buildreporter_release.bat
if %2 == modeler call buildmodeler_release.bat
if %2 == maxwell call buildmaxwell_release.bat %3
if %2 == udm call buildudm_release.bat
if %2 == djob call builddjob_release.bat
if %2 == statespacefitter call buildstatespacefitter_release.bat
if %2 == core call buildcore_release.bat
if %2 == maxcirc call buildmaxcirc_release.bat %3
if %2 == simplorer call buildsimplorer_release.bat %3

goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
goto finish

:error_proj
echo Project name is incorrect
set ERRORLEVEL=2
goto finish

:finish
echo cd %currwd%
cd %currwd%

