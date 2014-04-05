@echo off

REM See buildexecs.bat for comments about "SCRIPT CONFIGURATION"

set thisfiledir=%~dp0%
echo call %thisfiledir%config.cmd
call %thisfiledir%config.cmd
if errorlevel 1 (
  echo Error occured during invocation of config.cmd. Make sure this file exists/runs
  goto error
)

%repodrive1%:
if errorlevel 1 (
  echo Invalid drive letter in repodrive1: %repodrive1%
  goto error
)

set reponame=%gitproj%
set viewdir=%repodir1%\%reponame%\nextgen

REM Ensure log files are created by devenv
set acprodsdir=%viewdir%\ansoftcore\products
set reptestdir=%acprodsdir%\reportsetup\reportsetuptest
set modtestdir=%acprodsdir%\geometry3d\ModelerTestProduct
FOR %%d in (%reptestdir%\64Release %reptestdir%\64Debug %modtestdir%\64Debug %modtestdir%\64Release) DO (
  if NOT EXIST %%d (
    echo mkdir %%d
    call mkdir %%d
  )
)

call cleansln %viewdir%\ansoftcore\Core.sln release
REM call cleansln %viewdir%\ansoftcore\products\reportsetup\reportsetuptest\ReportSetupTest.sln release
REM call cleansln %viewdir%\products\geometry3d\ModelerTestProduct\ModelerTestProduct.sln release
REM call cleansln %viewdir%\MaxCirDesktop.sln release
REM call cleansln %viewdir%\Simplorer.sln release
call cleansln %viewdir%\HFSS.sln release
call cleansln %viewdir%\Nextgen_NoHfss.sln release
REM call cleansln %viewdir%\MaxwellLight.sln release

call buildview_release %reponame% core
call buildview_release %reponame% statespacefitter
REM call buildview_release %reponame% reporter
REM call buildview_release %reponame% modeler
REM call buildview_release %reponame% maxcirc nocore
REM call buildview_release %reponame% simplorer nocore
call buildview_release %reponame% hfss nocore
call buildview_release %reponame% designer nocore
REM call buildview_release %reponame% maxwell nocore

call cleansln %viewdir%\ansoftcore\Core.sln Debug
REM call cleansln %viewdir%\ansoftcore\products\reportsetup\reportsetuptest\ReportSetupTest.sln debug
REM call cleansln %viewdir%\products\geometry3d\ModelerTestProduct\ModelerTestProduct.sln debug
REM call cleansln %viewdir%\MaxCirDesktop.sln debug
REM call cleansln %viewdir%\Simplorer.sln debug
call cleansln %viewdir%\HFSS.sln debug
call cleansln %viewdir%\Nextgen_NoHfss.sln debug
REM call cleansln %viewdir%\MaxwellLight.sln debug

call buildview_debug %reponame% core
call buildview_debug %reponame% statespacefitter
REM call buildview_debug %reponame% reporter
REM call buildview_debug %reponame% modeler
REM call buildview_debug %reponame% maxcirc nocore
REM call buildview_debug %reponame% simplorer nocore
call buildview_debug %reponame% hfss nocore
call buildview_debug %reponame% designer nocore
REM call buildview_debug %reponame% maxwell nocore

