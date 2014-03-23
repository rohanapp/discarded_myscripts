@echo off

echo call del release\%1.log
call del release\%1.log
echo call "C:\Program Files\Microsoft Visual Studio 8\Common7\IDE\devenv.exe" /build Release /project "%2" /out release\%1.log %1.sln 
call "C:\Program Files\Microsoft Visual Studio 8\Common7\IDE\devenv.exe" /build Release /project "%2" /out release\%1.log %1.sln 
