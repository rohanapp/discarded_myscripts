@echo off

SETLOCAL
 
set cwd=%CD%
set ansoftprod=%1
set ansoftprodcmdline=%~2
set mt_level=%3
set mt_file_name=%4


set ANSOFT_MT_PROFILE=%mt_level%
if %mt_level%==0 set ANSOFT_MT_PROFILE=
echo ANSOFT_MT_PROFILE value is %ANSOFT_MT_PROFILE%

set mt_file_path=C:\public\mt_logs\%mt_file_name%
set ANSOFT_MT_PROFILE_LOG=%mt_file_path%
echo ANSOFT_MT_PROFILE_LOG value is %ANSOFT_MT_PROFILE_LOG%

echo call %ansoftprod% %ansoftprodcmdline%
call %ansoftprod% %ansoftprodcmdline%

goto finish

:error
echo Error occured

:finish
cd %cwd%

