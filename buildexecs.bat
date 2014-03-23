@echo off

set currwd=%CD%

REM call buildview Repo1 core
REM call buildview Repo1 statespacefitter

REM Comment out reporter as regserver of test comengine throws up a dialog, stopping
REM the full build process!
REM call buildview Repo1 reporter

REM call buildview Repo1 djob
call buildview Repo1 hfss
call buildview Repo1 designer
call buildview Repo1 maxwell

goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
goto finish

:finish
echo cd %currwd%
cd %currwd%

