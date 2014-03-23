@echo off

call cdi %1
call copy n:\optimize\include\%1\*.h
if errorlevel 1 goto error

call cds %1
call copy n:\optimize\source\%1\*.h
call copy n:\optimize\source\%1\*.cxx
if errorlevel 1 goto error

goto finish

:error
echo Error occured in copying to n drive
exit 1

:finish
