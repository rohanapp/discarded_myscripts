@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildproj_debug.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildproj_debug.bat geometry3d all_geometry3d
call buildproj_debug.bat hfss all_hfss

cd ansoftcore
if errorlevel 1 goto error
call buildproj_release.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildproj_release.bat geometry3d all_geometry3d
call buildproj_release.bat hfss all_hfss


goto finish

:error
echo Unable to cd to nextgen

:finish
