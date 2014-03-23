@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildsln_debug64.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildsln_debug64.bat SerenadeSymphony All_SerSym

cd ..

goto finish

:error
echo Unable to cd to nextgen

:finish
