@echo off

SETLOCAL

set hfss="c:\Program Files\Ansoft\hfss12\hfss.exe"
set cmdline=%1
set use_mt=%2
set mt_file_name=%3

echo call rundesktop.bat %hfss% %cmdline% %use_mt% %mt_file_name%
call rundesktop.bat %hfss% %cmdline% %use_mt% %mt_file_name%
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
cd %cwd%

