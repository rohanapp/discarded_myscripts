@echo off

REM Run this command with parameters: view-folder (that has nextgen in it)

set currdir=%CD%
set errorexitcode=1

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
set teighadirname=vc10_amd64dlldbg
IF /I NOT %2 EQU Debug (
  set dirname=64Release
  set config=Release
  set acisdirname=bin_win64_vc10
  set teighadirname=vc10_amd64dll
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
call xcopy /V /Q /Y %boostdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %boostdir%\*.dll %coreoutputdir%\

set acisdir=%viewdir%\nextgen\ansoftcore\thirdparty\acis\%acisdirname%
echo.
echo.
echo Copying ACIS DLLs: %acisdir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Q /Y %acisdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %acisdir%\*.dll %coreoutputdir%\

set rwdir=%viewdir%\nextgen\ansoftcore\thirdparty\RogueWave\RWToolKit\INTEL\Lib\vc10\x64
echo.
echo.
echo Copying Roguewave DLLs: %rwdir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Q /Y %rwdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %rwdir%\*.dll %coreoutputdir%\


REM !!!!GLEW DLL!!!!
set glewdir=%viewdir%\thirdparty\core_files\glew\glew-1.10.0\bin\%config%\x64
IF NOT EXIST %glewdir%\NUL (
  echo %glewdir% does not exist
  goto error
)

echo.
echo.
echo Copying GLEW DLLs from %glewdir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.

call xcopy /V /Q /Y %glewdir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %glewdir%\*.dll %coreoutputdir%\

REM !!TEIGHA!!!
set teighadir=%viewdir%\nextgen\thirdparty\teigha\Win64\exe\%teighadirname%
echo.
echo.
echo Copying TEIGHA DLLs: %teighadir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Q /Y %teighadir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %teighadir%\*.dll %coreoutputdir%\

REM !!INTEL MKL!!!!
set mkldir=%viewdir%\nextgen\ansoftcore\thirdparty\intel\MKL\Windows\em64t
echo.
echo.
echo Copying INTEL MKL DLLs: %mkldir% to %nextgenoutputdir% and %coreoutputdir% 
echo.
echo.
call xcopy /V /Q /Y %mkldir%\*.dll %nextgenoutputdir%\
call xcopy /V /Q /Y %mkldir%\*.dll %coreoutputdir%\



goto finish

:error
echo Error occurred
EXIT /B %errorexitcode%

:finish
cd %currdir%
EXIT /B 0


