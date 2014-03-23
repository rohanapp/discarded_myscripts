@echo off

SETLOCAL

set cwd=%CD%

echo cd %1
cd %1
if errorlevel 1 goto error

call cleanderived.bat

goto finish

:error
echo Unable to cd to %1

:finish
cd %cwd%
