@echo off

call cd6 parametric
if errorlevel 1 goto error
call copy n:\optimize\optimize.doc
call copy n:\optimize\parametric.doc
call copy n:\optimize\*.h
call copy n:\optimize\*.cxx
if errorlevel 1 goto error

echo Loading errmgrappl
call loadoptilib errmgrappl
if errorlevel 1 goto error

echo Loading errmgrkern
call loadoptilib errmgrkern
if errorlevel 1 goto error

echo Loading paramappl
call loadoptilib paramappl
if errorlevel 1 goto error

echo Loading paramkern
call loadoptilib paramkern
if errorlevel 1 goto error

echo Loading projappl
call loadoptilib projappl
if errorlevel 1 goto error

echo Loading projkern
call loadoptilib projkern
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
