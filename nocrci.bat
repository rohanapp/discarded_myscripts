@echo off

if %1 == "" goto usage

echo nocr %1
call nocr %1
if errorlevel 1 goto error

echo cleartool ci %1
call cleartool ci %1
if errorlevel 1 goto error

goto finish

:error
echo Error occured
goto finish

:usage
echo blabla

:finish
