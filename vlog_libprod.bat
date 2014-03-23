@echo off

set cwd=%CD%
echo cd nextgen\ansoftcore
cd nextgen\ansoftcore
if errorlevel 1 goto error
updateansoftcorelib.log
if errorlevel 1 goto error
updateansoftcoreproducts.log
if errorlevel 1 goto error

echo cd %cwd%
cd %cwd%
echo cd nextgen
cd nextgen
if errorlevel 1 goto error
updatenextgenlib.log
if errorlevel 1 goto error
updatenextgenproducts.log

goto finish

:error
echo Error occured

:finish
cd %cwd%
