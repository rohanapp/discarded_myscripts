@echo off
rem Usage: copytolk drive_name_for_target_srcs drive_name_for_target_docs laptop_source_drive laptop_doc_drive 
rem Procedure: first copy this file to lionking\c\bin\checkoutlk.bat.
rem Replace copyv6,i,s with corresponding checkoutv6,i,s -> this is
rem to first checkout files before copying.
rem Also get rid of the copy of todo.doc line from checkoutlk.bat

rem call copyv6filetolk %1 %3 parametric parametric.doc
rem if errorlevel 1 goto error

rem call copyifiletolk %1 %3 ytools utilfunc.h
rem if errorlevel 1 goto error

rem call copysfiletolk %1 %3 ytools utilfunc.cxx
rem if errorlevel 1 goto error

call copyifiletolk %1 %3 paramkern paramkernstrings.h
if errorlevel 1 goto error

goto finish

:error
echo Error occured
Usage: copytolk drive_name_for_target_srcs drive_name_for_target_docs laptop_source_drive laptop_doc_drive 

:finish


