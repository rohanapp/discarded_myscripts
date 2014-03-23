@echo off

@echo Deleting derived data
cd e:\naresh\software
if errorlevel 1 goto error
call cleanderived

cd c:\
mkdir %1\flexlm
if errorlevel 1 goto error
xcopy /S/R/C/H/K/F flexlm %1\flexlm
if errorlevel 1 goto error

cd c:\users
mkdir %1\naresh
if errorlevel 1 goto error
xcopy /S/R/C/H/K/F naresh %1\naresh
if errorlevel 1 goto error

cd C:\Documents and Settings\naresh.SANTACLARA\Local Settings\Application Data\Microsoft\Outlook
mkdir %1\mail
if errorlevel 1 goto error
xcopy /S/R/C/H/K/F * %1\mail
if errorlevel 1 goto error

cd C:\Documents and Settings\naresh.SANTACLARA
mkdir %1\Favorites
if errorlevel 1 goto error
xcopy /S/R/C/H/K/F Favorites %1\Favorites
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
