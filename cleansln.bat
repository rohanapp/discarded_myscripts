@echo off
setlocal enableextensions
REM setlocal enabledelayedexpansion

set currdir=%CD%

set numargs=0
FOR %%A in (%*) DO set /A numargs+=1

IF NOT %numargs% == 2 (
  echo Incorrect number of arguments: %numargs%. 
  echo Usage: "cleansln.bat <sln-path> <Debug|Release>"
  goto error
)

set slnpath=%1
IF NOT EXIST %slnpath% (
  echo Sln does not exist: %slnpath%
  goto error
)
set slnpathstr="%1"
FOR /F "delims==" %%A IN (%slnpathstr%) DO (
  set slndir=%%~dpA
  set slnfilewext=%%~nxA
  set slnfile=%%~nA
)

set config=Debug
set outputdirname=64Debug
IF /I NOT %2 EQU Debug (
  set outputdirname=64Release
  set config=Release
  IF /I NOT %2 EQU Release (
    echo Config has to be one of: debug, release
    goto error
  )
)

REM Platform harcoded to x64
set platform=x64

set logfile=%slndir%%outputdirname%\%slnfile%_clean.log

echo "C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /t:Clean /property:Configuration=%config%;Platform=%platform% /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /l:FileLogger,Microsoft.Build.Engine;logfile=%logfile% %slnpath%
echo.
call "C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /t:Clean /property:Configuration=%config%;Platform=%platform% /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /l:FileLogger,Microsoft.Build.Engine;logfile=%logfile% %slnpath%
echo.

goto finish

:error
echo Error occurred

:finish
cd %currdir%

