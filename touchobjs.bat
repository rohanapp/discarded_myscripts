@echo off

FOR /R %%i IN (*.obj) DO call touch %%i
FOR /R %%i IN (*.lib) DO call touch %%i
FOR /R %%i IN (*.dll) DO call touch %%i
FOR /R %%i IN (*.exe) DO call touch %%i
