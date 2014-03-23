@echo off

echo call del debug\%1.log
call del debug\%1.log
echo call "C:\Program Files\Microsoft Visual Studio 8\Common7\IDE\devenv.exe" /build Debug /project "%2" /out debug\%1.log %1.sln 
call "C:\Program Files\Microsoft Visual Studio 8\Common7\IDE\devenv.exe" /build Debug /project "%2" /out debug\%1.log %1.sln 

