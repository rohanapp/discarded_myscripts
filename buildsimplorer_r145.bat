@echo off

set currwd=%CD%

d:

cd \Views\nappann_r145_view\nextgen
if errorlevel 1 goto error
call mksimpDebug.bat

cd \Views\nappann_r145_view\simplorer
if errorlevel 1 goto error
call mksimpDebug.bat
if errorlevel 1 goto error
echo Copy engine to UI ..\nextgen\debug
call SimplorerEngineToNextgen_dbg.bat ..

cd \Views\nappann_r145_view\nextgen
if errorlevel 1 goto error
call mksimpRelease.bat

cd \Views\nappann_r145_view\simplorer
if errorlevel 1 goto error
call mksimpRelease.bat
if errorlevel 1 goto error
echo Copy engine to UI ..\nextgen\release
call SimplorerEngineToNextgen_rls.bat ..



goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
goto finish

:finish
echo cd %currwd%
cd %currwd%

