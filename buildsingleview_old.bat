@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildproj_old.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildproj_old.bat CircuitEditors All_Circuit_Editors
call buildproj_old.bat DesignerDesktop All_Desktop
call buildproj_old.bat SerenadeSymphony All_SerSym
call buildproj_old.bat Ensemble All_Ensemble
call buildproj_old.bat geometry3d all_geometry3d
call buildproj_old.bat hfsslight all_hfss
call buildproj_old.bat hfss all_hfss
goto finish

:error
echo Unable to cd to nextgen

:finish
