@echo off

cd \users\naresh\%1\vobs\nextgen
if errorlevel 1 cd \%\vobs\nextgen
if errorlevel 1 goto error

call cleanderived

cd \users\naresh\%1\vobs\nextgen\desktop
if errorlevel 1 goto error

echo msdev.exe nextgen.dsw /out ..\debug\make.log /make "all - Win32 Debug"
call msdev.exe nextgen.dsw /out ..\debug\make.log /make "all - Win32 Debug"
if errorlevel 1 goto error

goto finish

:error
echo Error occured in debug build of nextgen in %1 view
echo Check ..\debug\make.log
echo Usage: db_nextgen view_name

:finish
