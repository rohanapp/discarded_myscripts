@echo off

cd nextgen\ansoftcore\products\reportsetup\reportsetuptest
if errorlevel 1 goto error

call buildsln_release64.bat ReportSetupTest

cd ..\..\..\..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
