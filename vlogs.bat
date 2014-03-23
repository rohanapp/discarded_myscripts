@echo off

FOR /R %%i IN (*.log) DO call perl c:\users\naresh\software\perl_scripts\showbuildlogerrors.pl %1 --file "%%i"

goto finish

:error
echo Error occured

:finish
