@echo off

set VIEW_DIR=\views\%1
echo cd %VIEW_DIR%
cd %VIEW_DIR%
cd %VIEW_DIR%\nextgen

release\hfss.log
debug\hfss.log

release\CircuitEditors.log
debug\CircuitEditors.log

release\SerenadeSymphony.log
debug\SerenadeSymphony.log
