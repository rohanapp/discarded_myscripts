@echo off

cd \views\naresh_ansoftcore_latest_view
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_core_latest_view2
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_corev2_view2
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_dcom2ipc_view
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_designer4_view
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_nextgen_latest_view
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_product_main_latest_view
if errorlevel 1 goto error
call cleanderived

cd \views\naresh_core_minor_release_view2
if errorlevel 1 goto error
call cleanderived

goto finish

:error
echo Error occured during cd to view

:finish
