@echo off

%1:
cd \nar*\ansoft\ver6\lib\source\%2
if errorlevel 1 goto error
ct co -unr -nc %3
if errorlevel 1 echo Already checkout!

goto finish

:error
echo Error occured in checkoutsfile
echo Usage checkoutsfile src_file_drive lib_name file_name

:finish
