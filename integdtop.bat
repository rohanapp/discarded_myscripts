@echo off

set currdir=%CD%

E:
set configdir=\Program Files\AnsysEM\AnsysEM16.0\Win64\config

cd %configdir%
if errorlevel 1 goto error

set numargs=0
FOR %%A in (%*) DO set /A numargs+=1

if NOT %numargs% == 1 (
  echo Incorrect number of arguments: %numargs%.
  echo Usage: "integdtop.bat 1|0"
  goto error
)

if %1 == 1 (
  set srcadmin="admin - integrated dtop.xml"
) else (
  if %1 == 0 (
    set srcadmin="admin - Orig.xml"
  ) else (
    echo Unknown argument: %1
    goto error
  )
)

echo call del admin.xml
call del admin.xml
if errorlevel 1 (
  echo Unable to delete admin.xml
  goto error
)

echo call copy %srcadmin% admin.xml
call copy %srcadmin% admin.xml
if errorlevel 1 goto error

goto finish

:error
echo Error occurred

:finish

cd %currdir%
