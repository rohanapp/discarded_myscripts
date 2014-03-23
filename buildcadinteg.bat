@echo off

echo call buildhfss 
call buildhfss 

echo call buildaddin
call buildaddin

echo call buildudm
call buildudm

echo call perl c:\users\naresh\software\perl_scripts\vlog_full.pl
call perl c:\users\naresh\software\perl_scripts\vlog_full.pl
