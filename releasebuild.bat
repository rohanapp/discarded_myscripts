@echo off

cd \users\naresh\%1\vobs\ansoft\ver6\%2
if errorlevel 1 goto error

echo msdev.exe %2.dsw /out Release\make.log /make 
call msdev.exe %2.dsw /out Release\make.log /make 
if errorlevel 1 goto error
copy Release\%2.exe e:\bin
if errorlevel 1 echo Error occured in copy

goto finish

:error
echo Error occured in debugbuild of %2 in %1 view
echo Check Release\make.log
echo Usage: debugbuild view_name ver6_directory_name

:finish
