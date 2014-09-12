@echo off

set buildcore=1
if "%1"=="nocore" set buildcore=0

cd ASim
if errorlevel 1 goto error

set build
call buildaimsln_debug64.bat Core



goto finish

:error
echo Unable to cd to ASim directory

:finish
