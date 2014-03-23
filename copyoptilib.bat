@echo off

call cdi %1
call copy *.h n:\optimize\include\%1\
if errorlevel 1 goto error

call cds %1
call copy *.h n:\optimize\source\%1\
call copy *.cxx n:\optimize\source\%1\
if errorlevel 1 goto error

goto finish

:error
echo Error occured in copying to n drive

:finish
