@echo off

call cleartool findmerge . -graphical -unr -fversion
echo call buildproj_debug.bat %1 %2
call buildproj_debug.bat %1 %2

echo call buildproj_release.bat %1 %2
call buildproj_release.bat %1 %2
