@echo off

cd \users\naresh\%1\vobs\ansoft\ver6
if errorlevel 1 goto error
call cleanderived

call releasebuild %1 hfss

call releasebuild %1 post3

call releasebuild %1 maxparam

call releasebuild %1 m3dfs

if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Usage: rb_v6 view_name

:finish

