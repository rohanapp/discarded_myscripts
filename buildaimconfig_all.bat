@echo off

set blddebug=1
if NOT "%1"=="debug" (
  if NOT "%1"=="release" (
    echo "Usage: buildaimconfig_all debug|release"
    goto error
  )
  set blddebug=0
)

cd ASim
if errorlevel 1 (
  echo "Unable to cd to ASim directory"
  goto error
)

set bldcmd=buildaimsln_debug.bat
if %blddebug%==0 set bldcmd=buildaimsln_release.bat

call %bldcmd% Core
call %bldcmd% Addin
call %bldcmd% Proxies
call %bldcmd% ProxyApplicationLayer


goto finish

:error
echo Error occurred!

:finish
