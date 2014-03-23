@echo off

cd base
if errorlevel 1 goto error

call nmake /f Makefile.win32 buildopt
if errorlevel 1 goto error
call nmake /f Makefile.win32 buildCC
if errorlevel 1 goto error

cd ..
cd vgl
if errorlevel 1 goto error

call nmake /f Makefile.win32 buildopt
if errorlevel 1 goto error
call nmake /f Makefile.win32 buildCC
if errorlevel 1 goto error

cd ..
cd vis
if errorlevel 1 goto error

call nmake /f Makefile.win32 buildopt
if errorlevel 1 goto error
call nmake /f Makefile.win32 buildCC
if errorlevel 1 goto error

cd ..
cd vfe
if errorlevel 1 goto error

call nmake /f Makefile.win32 buildopt
if errorlevel 1 goto error
call nmake /f Makefile.win32 buildCC
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
