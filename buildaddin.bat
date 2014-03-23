@echo off

set cwd=%CD%
echo cd nextgen\ansoftcore
cd nextgen\ansoftcore
if errorlevel 1 goto tryasansoftcoreview
goto startbuild

:tryasansoftcoreview
SETLOCAL
cd ansoftcore\core_files
if errorlevel 1 goto error

:startbuild
call buildsln_debug64.bat Addins
call buildsln_release64.bat Addins

if errorlevel 1 goto error

goto finish

:error
echo Error occured!

:finish
cd %cwd%
