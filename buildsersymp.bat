@echo off

set VIEW_DIR=\views\%1
echo cd %VIEW_DIR%
cd %VIEW_DIR%
cd %VIEW_DIR%\nextgen

call buildproj.bat CircuitEditors All_Circuit_Editors
call buildproj.bat DesignerDesktop All_Desktop
call buildproj.bat SerenadeSymphony All_SerSym
