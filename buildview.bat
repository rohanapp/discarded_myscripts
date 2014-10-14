@echo off

set currwd=%CD%

call buildview_debug %1 %2
call buildview_release %1 %2

cd ..\..

goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
cd ..\..

goto finish

:error_proj
echo Project name is incorrect
set ERRORLEVEL=2
cd ..\..

goto finish

:finish
echo cd %currwd%
cd %currwd%

