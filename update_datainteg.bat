@echo off

set VIEW_DIR=\views\naresh_datainteg_view\nextgen
echo cd %VIEW_DIR%\ansoftcore
cd %VIEW_DIR%\ansoftcore
call cleartool.exe update -log updateansoftcorelib.log lib
call cleartool.exe update -log updateansoftcoreproducts.log products

