@echo off

echo Viewing %1
%1
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
