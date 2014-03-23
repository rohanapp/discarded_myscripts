@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildproj_debug_vs2005.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildproj_debug_vs2005.bat hfss all_hfss

cd ansoftcore
if errorlevel 1 goto error
call buildproj_release_vs2005.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildproj_release_vs2005.bat hfss all_hfss


goto finish

:error
echo Unable to cd to nextgen

:finish
