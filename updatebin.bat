@echo off

echo Copying maxwell.exe
call copy %1:\hfss6\bin\maxwell.exe f:\bin
if errorlevel 1 goto error

echo Copying qp3d.exe
call copy %1:\main\bin\qp3d.exe f:\bin
if errorlevel 1 goto error

echo Copying multipol.exe
call copy %1:\main\bin\multipol.exe f:\bin
if errorlevel 1 goto error

echo Copying cn*.exe
call copy %1:\main\bin\cn*.exe f:\bin
if errorlevel 1 goto error

echo Copying abc3d.exe
call copy %1:\hfss6\bin\abc3d.exe f:\bin
if errorlevel 1 goto error

echo Copying mr.exe
call copy %1:\hfss6\bin\mr.exe f:\bin
if errorlevel 1 goto error

echo Copying solver.exe
call copy %1:\hfss6\bin\solver.exe f:\bin
if errorlevel 1 goto error

echo Copying wave.exe
call copy %1:\hfss6\bin\wave.exe f:\bin
if errorlevel 1 goto error

echo Copying mesh3d.exe
call copy %1:\hfss6\bin\mesh3d.exe f:\bin
if errorlevel 1 goto error

echo Copying hfss.exe
call copy %1:\hfss6\bin\hfss.exe f:\bin
if errorlevel 1 goto error

echo Copying modeler3.exe
call copy %1:\hfss6\bin\modeler3.exe f:\bin
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
