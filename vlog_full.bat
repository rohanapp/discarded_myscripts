@echo off

set cwd=%CD%

echo call perl c:\users\naresh\software\perl_scripts\vlog_full.pl
call perl c:\users\naresh\software\perl_scripts\vlog_full.pl

goto finish

:error
echo Error occured

:finish
cd %cwd%
