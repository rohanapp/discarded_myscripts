@echo off

cd \views\%1\ansoft\ver6
if errorlevel 1 goto error

call debugbuild %1 hfss

call debugbuild %1 post3

call debugbuild %1 maxparam

call debugbuild %1 m3dfs

if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Usage: db_v6 view_name

:finish

