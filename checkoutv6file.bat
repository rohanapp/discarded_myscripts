@echo off

%1:
cd \nar*\ansoft\ver6\%2
if errorlevel 1 goto error
ct co -unr -nc %3

goto finish

:error
echo Error occured in checkoutv6file
echo Usage checkoutv6file src_file_drive ver6_name file_name

:finish
