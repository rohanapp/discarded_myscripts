@echo off

del /s headers.obj
del /s stdafx.obj

goto finish

:error
echo Error occured

:finish
