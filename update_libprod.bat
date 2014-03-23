@echo off

set cwd=%CD%
echo cd nextgen\ansoftcore
cd nextgen\ansoftcore
if errorlevel 1 goto error
call cleartool.exe update -rename -log updateansoftcorelibsummary.log lib > updateansoftcorelib.log
call cleartool.exe update -rename -log updateansoftcoreproductssummary.log products > updateansoftcoreproducts.log

echo cd %cwd%
cd %cwd%
echo cd nextgen
cd nextgen
if errorlevel 1 goto error
call cleartool.exe update -rename -log updatenextgenlibsummary.log lib > updatenextgenlib.log 
call cleartool.exe update -rename -log updatenextgenproductssummary.log products > updatenextgenproducts.log 

goto finish

:error
echo Error occured

:finish
cd %cwd%
