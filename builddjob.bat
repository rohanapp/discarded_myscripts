@echo off

set cwd=%CD%
cd nextgen\ansoftcore\products\desktopjob
if errorlevel 1 goto tryasansoftcoreview
goto startbuild

:tryasansoftcoreview
SETLOCAL
cd ansoftcore\core_files\products\desktopjob
if errorlevel 1 goto error

:startbuild
echo call buildsln_debug64.bat desktopjob
call buildsln_debug64.bat desktopjob

echo call buildsln_release64.bat desktopjob
call buildsln_release64.bat desktopjob

goto finish

:error
echo Unable to cd to desktopjob

:finish
echo cd %cwd%
cd %cwd%

