@echo off

cd nextgen\products\geometry3d\ModelerTestProduct
if errorlevel 1 goto error

call buildsln_release64.bat ModelerTestProduct

cd ..\..\..\..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
