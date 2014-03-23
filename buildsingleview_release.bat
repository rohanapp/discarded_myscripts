@echo off

cd nextgen\ansoftcore
if errorlevel 1 goto error
call buildsln_release64.bat Core All_Core

cd ..
if errorlevel 1 goto error

call buildsln_release64.bat SerenadeSymphony All_SerSym
call buildsln_release64.bat CircuitEditors All_Circuit_Editors
call buildsln_release64.bat DesignerDesktop All_Desktop
call buildsln_release64.bat Ensemble All_Ensemble
call buildsln_release64.bat geometry3d all_geometry3d
call buildsln_release64.bat hfsslight all_hfss
call buildsln_release64.bat hfss all_hfss

cd ..

goto finish

:error
echo Unable to cd to nextgen

:finish
