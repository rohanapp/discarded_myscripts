@echo off

del /s *.sbr
del /s *.ilk
del /s *.opt
del /s *.ncb
del /s *.suo
del /s *.plg
del /s *.tmp
del /s *.idb

goto finish

:error
echo Error occured

:finish
