@echo off

SETLOCAL

set cwd=%CD%
set casestring=%1
if errorlevel 1 goto error

set proj1=BMW6
set proj2=BMW6_singledesign
set numprojs=2

cd "C:\projs\hfssprojs"
if errorlevel 1 goto error

FOR /L %%i IN (1,1,%numprojs%) DO call hfss12.bat "-RunScriptAndExit donothing.vbs -LogFile %%proj%%i%%.log %%proj%%i%%.hfss" 2 %%proj%%i%%_mt_scriptrun_%casestring%.log
if errorlevel 1 goto error

goto finish

:error
echo Error occured
echo Usage: batchrunprojs casestring

:finish
cd %cwd%

