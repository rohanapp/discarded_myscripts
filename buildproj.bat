@echo off

#Seems like we want to build debug config in the end. If not, idl
#compilation for release-config will end up requiring a rebuild of
#debug-config

echo call buildsln_debug64.bat %1 %2
call buildsln_debug64.bat %1 %2

echo call buildsln_release64.bat %1 %2
call buildsln_release64.bat %1 %2

