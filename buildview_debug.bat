@echo off

set currwd=%CD%

e:

echo Trying to cd to git views
echo cd \ANSYSDev\repos\%1
cd \ANSYSDev\repos\%1
if errorlevel 1 goto tryc
echo This is a git view
goto founddir

:tryc
echo Trying git views on c drive
c:
echo cd \ANSYSDev\%1
cd \ANSYSDev\%1
if errorlevel 1 goto trye
goto founddir

:trye
echo Trying clearcse views on e drive
e:
echo cd \views\%1
cd \views\%1
if errorlevel 1 goto error
goto founddir

:founddir
set validProj=0
if %2 == designer set validProj=1
if %2 == hfss set validProj=1
if %2 == addin set validProj=1
if %2 == reporter set validProj=1 
if %2 == modeler set validProj=1 
if %2 == maxwell set validProj=1 
if %2 == udm set validProj=1 
if %2 == djob set validProj=1 
if %2 == statespacefitter set validProj=1 
if %2 == core set validProj=1 
if %2 == maxcirc set validProj=1 
if %2 == simplorer set validProj=1 

if %validProj% EQU 0 goto error_proj

if %2 == designer call builddesigner_debug.bat %3
if %2 == hfss call buildhfss_debug.bat %3
if %2 == addin call buildaddin_debug.bat
if %2 == reporter call buildreporter_debug.bat
if %2 == modeler call buildmodeler_debug.bat
if %2 == maxwell call buildmaxwell_debug.bat %3
if %2 == udm call buildudm_debug.bat
if %2 == djob call builddjob_debug.bat
if %2 == statespacefitter call buildstatespacefitter_debug.bat
if %2 == core call buildcore_debug.bat
if %2 == maxcirc call buildmaxcirc_debug.bat %3
if %2 == simplorer call buildsimplorer_debug.bat %3

goto finish

:error
echo Error occured during cd to view
set ERRORLEVEL=1
goto finish

:error_proj
echo Project name is incorrect
set ERRORLEVEL=2
goto finish

:finish
echo cd %currwd%
cd %currwd%

