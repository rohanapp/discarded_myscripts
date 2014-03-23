@echo off

set cwd=%CD%

set logFiles=

echo Viewing debug logs...
echo cd nextgen\debug
cd nextgen\debug
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=\"%logFiles%  %%i\""
echo cd %cwd%
cd %cwd%

echo cd nextgen\ansoftcore\debug
cd nextgen\ansoftcore\debug
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=%logFiles%  %%i"
cd %cwd%

echo cd nextgen\lib\geometrycore\UserDefinedModels\Debug
cd nextgen\lib\geometrycore\UserDefinedModels\Debug
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=%logFiles%  %%i"
cd %cwd%

echo Viewing release logs...
echo cd nextgen\release
cd nextgen\release
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=%logFiles%  %%i"
cd %cwd%

echo cd nextgen\ansoftcore\release
cd nextgen\ansoftcore\release
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=%logFiles%  %%i"
cd %cwd%

echo cd nextgen\lib\geometrycore\UserDefinedModels\Release
cd nextgen\lib\geometrycore\UserDefinedModels\Release
if errorlevel 1 goto error
FOR /R %%i IN (*.log) do set "logFiles=%logFiles%  %%i"
cd %cwd%

echo %logFiles%
call perl c:\users\naresh\software\perl_scripts\showbuildlogerrors.pl %1 --files "%logFiles%

goto finish

:error
echo Error occured

:finish
cd %cwd%
