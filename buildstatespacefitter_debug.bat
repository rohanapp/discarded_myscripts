@echo off

set cwd=%CD%
echo cd bostonvob\altra\models\sp_files\standalone_fitter
cd bostonvob\altra\models\sp_files\standalone_fitter
if errorlevel 1 goto error


echo call buildsln_debug64.bat standalone_fitter
call buildsln_debug64.bat standalone_fitter

cd ..\..

goto finish

:error
echo Unable to cd to bostonvob\altra\models\sp_files\standalone_fitter

:finish
echo cd %cwd%
cd %cwd%
