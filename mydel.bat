@echo off

echo del %1.%2
del %1.%2

goto finish

:error
echo Error occured

:finish
