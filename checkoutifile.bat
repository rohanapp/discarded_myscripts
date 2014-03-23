@echo off

%1:
cd \nar*\ansoft\ver6\lib\include\%2
if errorlevel 1 goto error
ct co -unr -nc %3

goto finish

:error
echo Error occured in checkoutifile
echo Usage checkoutifile src_file_drive lib_name file_name

:finish
