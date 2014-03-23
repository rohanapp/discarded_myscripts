@echo off

echo Copying maxwell.exe
call copy %1:\hfss7\bin\maxwell.exe f:\bin
if errorlevel 1 goto error

echo Copying maxparam.exe
call copy %1:\hfss7\bin\maxparam.exe f:\bin
if errorlevel 1 echo Error occured copying maxparam

echo Copying macedit.exe
call copy %1:\hfss7\bin\macedit.exe f:\bin
if errorlevel 1 echo Error occured copying macedit

echo Copying abc3d.exe
call copy %1:\hfss7\bin\abc3d.exe f:\bin
if errorlevel 1 goto error

echo Copying eigen.exe
call copy %1:\hfss7\bin\eigen.exe f:\bin
if errorlevel 1 goto error

echo Copying mr.exe
call copy %1:\hfss7\bin\mr.exe f:\bin
if errorlevel 1 goto error

echo Copying solver.exe
call copy %1:\hfss7\bin\solver.exe f:\bin
if errorlevel 1 goto error

echo Copying wave.exe
call copy %1:\hfss7\bin\wave.exe f:\bin
if errorlevel 1 goto error

echo Copying mesh3d.exe
call copy %1:\hfss7\bin\mesh3d.exe f:\bin
if errorlevel 1 goto error

echo Copying post3.exe
call copy %1:\hfss7\bin\post3.exe f:\bin
if errorlevel 1 goto error

echo Copying hfss.exe
call copy %1:\hfss7\bin\hfss.exe f:\bin
if errorlevel 1 goto error

echo Copying modeler3.exe
call copy %1:\hfss7\bin\modeler3.exe f:\bin
if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Usage: updatehfss source_virtual_drive_name_for_narnia_f

:finish
