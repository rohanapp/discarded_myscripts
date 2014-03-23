@echo off

cd nextgen\ansoftcore\products\reportsetup\reportsetuptest
if errorlevel 1 goto tryasansoftcoreview
goto startbuild

:tryasansoftcoreview
echo here2
SETLOCAL
echo here1
cd ansoftcore\core_files\products\reportsetup\reportsetuptest
if errorlevel 1 goto error

:startbuild
call buildsln_debug64.bat ReportSetupTest

call buildsln_release64.bat ReportSetupTest

cd ..\..\..\..\..

goto finish

:error
echo Unable to cd to reportsetuptest

:finish
