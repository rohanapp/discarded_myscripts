@echo off

cd \users\naresh\%1\vobs\nextgen\desktop
if errorlevel 1 goto error

echo msdev.exe nextgen.dsw /out ..\release\make.log /make "all - Win32 Release"
call msdev.exe nextgen.dsw /out ..\release\make.log /make "all - Win32 Release"
if errorlevel 1 goto error

goto finish

:error
echo Error occured in release build of nextgen in %1 view
echo Check ..\release\make.log
echo Usage: rb_nextgen view_name

:finish
