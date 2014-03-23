@echo off

echo Copying hnl3d.exe
call copy %1:\main\bin\hnl3d.exe f:\bin
if errorlevel 1 goto error

echo Copying efs3d.exe
call copy %1:\main\bin\efs3d.exe f:\bin
if errorlevel 1 goto error

echo Copying cnq3d.exe
call copy %1:\main\bin\cnq3d.exe f:\bin
if errorlevel 1 goto error

echo Copying cnh3d.exe
call copy %1:\main\bin\cnh3d.exe f:\bin
if errorlevel 1 goto error

echo Copying ed3d.exe
call copy %1:\main\bin\ed3d.exe f:\bin
if errorlevel 1 goto error

echo Copying m3dfs.exe
call copy %1:\main\bin\m3dfs.exe f:\bin
if errorlevel 1 goto error

echo Copying post3.exe
call copy %1:\main\bin\post3.exe f:\bin
if errorlevel 1 goto error

echo Copying solver.exe
call copy %1:\main\bin\solver.exe f:\bin
if errorlevel 1 goto error

echo Copying mesh3d.exe
call copy %1:\main\bin\mesh3d.exe f:\bin
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
