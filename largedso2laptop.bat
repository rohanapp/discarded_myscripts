@echo off

set cwd=%CD%

:: Verify that destination directory for sources to be copied to laptop is valid
set destdir=%1
echo cd %destdir%
cd %destdir%
if errorlevel 1 goto error

IF NOT EXIST lib mkdir lib
if errorlevel 1 goto error
IF NOT EXIST lib\CoreInterfaces mkdir lib\CoreInterfaces
if errorlevel 1 goto error
IF NOT EXIST products mkdir products
if errorlevel 1 goto error

cd %cwd%
if errorlevel 1 goto error

echo cd nextgen\ansoftcore\lib
cd nextgen\ansoftcore\lib
if errorlevel 1 goto error

FOR %%A IN (NgAnsoftCOMApp Desktop wbintegutils) DO call cleanderiveddir.bat %%A
if errorlevel 1 goto error

:: S - copy dirs/subdirs
:: R - overwrite readonly
:: H - copies hidden and system files
:: K - copies attributes
:: F - display full source and dest names
FOR %%A IN (NgAnsoftCOMApp Desktop wbintegutils) DO call xcopy /EXCLUDE:c:\users\nappann\bin\skipfilesforldsoarchive.txt /S/R/H/K/F %%A %destdir%\lib\%%A\
if errorlevel 1 goto error

echo cd CoreInterfaces
cd CoreInterfaces
if errorlevel 1 goto error

FOR %%A IN (desktop desktopjob optimetrics) DO call xcopy /EXCLUDE:c:\users\nappann\bin\skipfilesforldsoarchive.txt /S/R/H/K/F %%A %destdir%\lib\CoreInterfaces\%%A\
if errorlevel 1 goto error

echo cd ..\..\products
cd ..\..\products
if errorlevel 1 goto error

FOR %%A IN (desktopjob reportsetup djobextractor optimetrics) DO call cleanderiveddir.bat %%A
if errorlevel 1 goto error

FOR %%A IN (desktopjob reportsetup djobextractor optimetrics) DO call xcopy /EXCLUDE:c:\users\nappann\bin\skipfilesforldsoarchive.txt /S/R/H/K/F %%A %destdir%\products\%%A\
if errorlevel 1 goto error

goto finish

:error
echo Unable to cd to nextgen

:finish
cd %cwd%
