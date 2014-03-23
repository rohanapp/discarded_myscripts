@echo off

set cwd=%CD%

set mt_log_dir="C:\public\mt_logs"

cd "C:\projs\hfssprojs"
if errorlevel 1 goto error

FOR /L %%i IN (1,1,2) DO call hfss12.bat -help
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
cd %cwd%

