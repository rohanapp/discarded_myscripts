@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildproj_release.bat Core All_Core vs2008

cd ..
if errorlevel 1 goto error

call buildsln_release.bat CircuitEditors vs2008
call buildsln_release.bat SerenadeSymphony vs2008
call buildsln_release.bat Nextgen_NoHfss vs2008

cd ..

goto finish

:error
echo Unable to cd to nextgen

:finish
