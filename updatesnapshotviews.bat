@echo off

set VIEW_DIR=\views\naresh_nextgen_latest_view
echo cd %VIEW_DIR%
cd %VIEW_DIR%
call cleartool.exe update -log updatenextgen.log nextgen

set VIEW_DIR=\views\naresh_core_minor_release_view2
echo cd %VIEW_DIR%
cd %VIEW_DIR%
call cleartool.exe update -log updatenextgen.log nextgen
