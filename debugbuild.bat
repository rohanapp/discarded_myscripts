@echo off

cd \views\%1\ansoft\ver6\%2
if errorlevel 1 goto error

echo msdev.exe %2.dsw /out Debug\make.log /make 
call msdev.exe %2.dsw /out Debug\make.log /make 
if errorlevel 1 goto error

goto finish

:error
echo Error occured in debugbuild of %2 in %1 view
echo Check Debug\make.log
echo Usage: debugbuild view_name ver6_directory_name

:finish
