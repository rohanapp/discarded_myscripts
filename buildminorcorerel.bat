@echo off

f:

echo cd \views\naresh_core_minor_release_view
cd \views\naresh_core_minor_release_view
if errorlevel 1 goto error
call builddesigner.bat

echo cd \views\naresh_core_minor_release_view
cd \views\naresh_core_minor_release_view
if errorlevel 1 goto error
call buildhfss_prods.bat

goto finish

:error
echo Error occured during cd to view

:finish
