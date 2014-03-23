@echo off

call cd6 parametric
call copy parametric.doc n:\optimize
call copy *.h n:\optimize
call copy *.cxx n:\optimize
if errorlevel 1 goto error

echo Copying errmgrappl
call copyoptilib errmgrappl
if errorlevel 1 goto error

echo Copying errmgrkern
call copyoptilib errmgrkern
if errorlevel 1 goto error

echo Copying paramappl
call copyoptilib paramappl
if errorlevel 1 goto error

echo Copying paramkern
call copyoptilib paramkern
if errorlevel 1 goto error

echo Copying projappl
call copyoptilib projappl
if errorlevel 1 goto error

echo Copying projkern
call copyoptilib projkern
if errorlevel 1 goto error

goto finish

:error
echo Error occured in copyoptisource

:finish
