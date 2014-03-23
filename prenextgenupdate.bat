@echo off

cd products
if errorlevel 1 goto error
FOR /R %%i IN (*.h) DO call forcerename %%i %%i.copy
cd..

cd lib
if errorlevel 1 goto error
FOR /R %%i IN (*.h) DO call forcerename %%i %%i.copy
cd..

cd desktop
if errorlevel 1 goto error
FOR /R %%i IN (*.h) DO call forcerename %%i %%i.copy
cd..

goto finish

:error
echo Error occured

:finish
