@echo off

cd simplorer
if errorlevel 1 goto error

call make_simp_engine.bat DEBUG NOCLEAN NOUPDATE

call make_simp_engine.bat RELEASE NOCLEAN NOUPDATE

goto finish

:error
echo Unable to cd to nextgen

:finish
