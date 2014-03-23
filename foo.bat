@echo off

set reponame=Repo1
set viewdir=c:\ANSYSDev\%reponame%\nextgen

call cleansln %viewdir%\ansoftcore\Core.sln Debug
call cleansln %viewdir%\ansoftcore\Core.sln Release

