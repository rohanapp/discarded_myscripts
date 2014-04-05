@echo off

REM !!!!!!!!!!!SCRIPT CONFIGURATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
REM This script requires a file with the name config.cmd in
REM its directory. Use templateconfig.cmd as a basis for your config.cmd
REM This file should contains Windows batch commands
REM to set values for following variables: 
REM 1) gitproj (Git project name),
REM 2) repodrive1/repodir1 (first drive/folder that contains repositories),
REM 3) repodrive2/repodir2 (second drive/folder that contains repositories)
REM NOTE: gitproj is the name of folder (repo) that contains nextgen. 
REM So gitproj should not include nextgen folder, but be one level above it.

set currwd=%CD%

set thisfiledir=%~dp0%
echo call %thisfiledir%config.cmd
call %thisfiledir%config.cmd
if errorlevel 1 (
  echo Error occured during invocation of config.cmd. Make sure this file exists/runs
  goto error
)

REM call buildview %gitproj% core
REM call buildview %gitproj% statespacefitter

REM Comment out reporter as regserver of test comengine throws up a dialog, stopping
REM the full build process!
REM call buildview %gitproj% reporter

REM call buildview %gitproj% djob
call buildview %gitproj% hfss
call buildview %gitproj% designer
call buildview %gitproj% maxwell

goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
goto finish

:finish
echo cd %currwd%
cd %currwd%

