@echo off

set cwd=%CD%

:: Verify that destination directory for sources to be copied to laptop is valid
set destdir=%1
echo cd %destdir%
cd %destdir%
if errorlevel 1 goto error

IF NOT EXIST lib mkdir lib
if errorlevel 1 goto error
IF NOT EXIST products mkdir products
if errorlevel 1 goto error

cd %cwd%
if errorlevel 1 goto error

echo cd nextgen\ansoftcore
cd nextgen\ansoftcore
if errorlevel 1 goto error

FOR %%A IN (lib products) DO call cleanderiveddir.bat %%A
if errorlevel 1 goto error

:: S - copy dirs/subdirs
:: R - overwrite readonly
:: H - copies hidden and system files
:: K - copies attributes
:: F - display full source and dest names
FOR %%A IN (lib products) DO call xcopy /EXCLUDE:c:\users\nappann\bin\skipfilesforldsoarchive.txt /S/R/H/K/F %%A %destdir%\%%A\
if errorlevel 1 goto error

goto finish

:error
echo Unable to cd to nextgen

:finish
cd %cwd%
