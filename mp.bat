@echo off

if %1 == "" goto usage

call ct co -unr -c "merge parametrics branch changes" %1
if errorlevel 1 goto error

call ct merge -graphical -to %1 -version /main/parametrics/LATEST
if errorlevel 1 goto error

call ct ci -nc %1
if errorlevel 1 goto error

goto finished

:error
echo Error occured in mergeparam.bat

:usage
echo Usage: mergeparam filename

:finished

