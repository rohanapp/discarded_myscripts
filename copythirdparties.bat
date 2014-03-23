@echo off

REM Run this command with parameters: view-folder (that has nextgen in it)

set currdir=%CD%

set numargs=0
FOR %%A in (%*) DO set /A numargs+=1

IF NOT %numargs% == 2 (
  echo Incorrect number of arguments: %numargs%. 
  echo Usage: "<command> <view-folder-that-has-nextgen> <Debug|Release>"
  goto error
)

set viewdir=%1
IF NOT EXIST %viewdir% (
  echo Specified view does not exist: %viewdir%
  goto error
)

set config=Debug
set dirname=64Debug
set acisdirname=bin_win64_vc10_dbg
IF /I NOT %2 EQU Debug (
  set dirname=64Release
  set config=Release
  set acisdirname=bin_win64_vc10
  IF /I NOT %2 EQU Release (
    echo Config has to be one of: debug, release
    goto error
  )
)

set nextgenoutputdir=%viewdir%\nextgen\%dirname%
IF NOT EXIST %nextgenoutputdir% (
  mkdir %nextgenoutputdir%
  if errorlevel 1 (
    echo Unable to create directory %nextgenoutputdir%
    goto error
  )
)

set coreoutputdir=%viewdir%\nextgen\ansoftcore\INTEL\%dirname%
IF NOT EXIST %coreoutputdir% (
  mkdir %coreoutputdir%
  if errorlevel 1 (
    echo Unable to create directory %coreoutputdir%
    goto error
  )
)

set boostdir=%viewdir%\nextgen\ansoftcore\thirdparty\boost\bin\INTEL\%dirname%
echo.
echo.
echo Copying boost DLLs: %boostdir% to %nextgenoutputdir% and %coreoutputdir%
echo.
echo.
call xcopy /V /Y %boostdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Y %boostdir%\*.dll %coreoutputdir%\

set acisdir=%viewdir%\nextgen\ansoftcore\thirdparty\acis\%acisdirname%
echo.
echo.
echo Copying ACIS DLLs: %acisdir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Y %acisdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Y %acisdir%\*.dll %coreoutputdir%\

set rwdir=%viewdir%\nextgen\ansoftcore\thirdparty\RogueWave\RWToolKit\INTEL\Lib\vc10\x64
echo.
echo.
echo Copying Roguewave DLLs: %rwdir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Y %rwdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Y %rwdir%\*.dll %coreoutputdir%\

goto finish

:error
echo Error occurred

:finish
cd %currdir%

