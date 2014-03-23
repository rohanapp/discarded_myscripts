@echo off

set VIEW_DIR=\views\naresh_search_view2
echo cd %VIEW_DIR%
cd %VIEW_DIR%
call cleartool.exe update -log updatenextgen.log nextgen
call cleartool.exe update -log updateansoft.log ansoft

