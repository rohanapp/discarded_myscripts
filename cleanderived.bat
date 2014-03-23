@echo off

set cwd=%CD%

del /s *.bsc
del /s *.obj
del /s *.sbr
del /s *.pdb
del /s *.pch
del /s *.ilk
del /s *.opt
del /s *.ncb
del /s *.suo
del /s *.plg
del /s *.tmp
del /s *.idb

del d:\temp\ansdebug.log

goto finish

:error
echo Error occured

:finish
cd %cwd%
