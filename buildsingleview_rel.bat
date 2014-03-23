@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildsln_release64.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildsln_release64.bat Nextgen_NoHfss
call buildsln_release64.bat geometry3d all_geometry3d
call buildsln_release64.bat hfsslight all_hfss
call buildsln_release64.bat hfss all_hfss
goto finish

:error
echo Unable to cd to nextgen

:finish
