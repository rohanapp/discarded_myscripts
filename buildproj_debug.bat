@echo off

echo call del debug\%1.log
call del debug\%1.log
echo call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" /build "Debug|Win32" /project "%2" /out debug\%1.log %1.sln 
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" /build "Debug|Win32" /project "%2" /out debug\%1.log %1.sln 

