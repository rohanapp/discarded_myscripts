@echo off

call debugbuild %1 hfss

call debugbuild %1 post3

call debugbuild %1 maxparam

call debugbuild %1 m3dfs

call db_nextgen %1

if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Usage: db_all view_name

:finish

