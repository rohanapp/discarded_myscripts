@echo off

cd \nar*\ansoft
if errorlevel 1 cd \clearviews\nar*\ansoft
if errorlevel 1 goto error

cleartool update ver6
if errorlevel 1 goto error
cleartool update config
if errorlevel 1 goto error

cd three\lib\source
if errorlevel 1 goto error
cleartool update error
if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Must be on the drive whose srcs u want to update

:finish
