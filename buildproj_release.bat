@echo off

set vspath="C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"
if "%3" equ "vs2008" set vspath="C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\IDE\devenv.exe"

echo call del release\%1.log
call del release\%1.log

echo call %vspath% /build "Release|Win32" /project "%2" /out release\%1.log %1.sln 
call %vspath% /build "Release|Win32" /project "%2" /out release\%1.log %1.sln 
