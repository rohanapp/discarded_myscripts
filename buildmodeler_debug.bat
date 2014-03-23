@echo off

cd nextgen\products\geometry3d\ModelerTestProduct
if errorlevel 1 goto error

call buildsln_debug64.bat ModelerTestProduct

cd ..\..\..\..\..

goto finish

:error
echo Unable to cd to nextgen

:finish
