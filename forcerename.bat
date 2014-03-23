@echo off

copy %1 %2
if errorlevel 1 goto error
del /f %1
if errorlevel 1 goto error
goto finish

:error
echo Error occured in forcerename

:finish
