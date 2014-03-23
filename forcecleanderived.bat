@echo off

set cwd=%CD%

del /f/s *.bsc
del /f/s *.sbr
del /f/s *.pch
del /f/s *.ilk
del /f/s *.opt
del /f/s *.ncb
del /f/s *.suo
del /f/s *.plg
del /f/s *.idb

del /f d:\temp\ansdebug.log

goto finish

:error
echo Error occured

:finish
cd %cwd%
