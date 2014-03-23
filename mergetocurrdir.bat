@echo off

:: REVISIT: 'merge-from' branch is hardedcoded to products_core5.0 in the below script

:: This script is used to find version from a latest branch to merge to a view as determined
:: by the current working directory
:: Below are useful options to findmerge command
:: cleartool findmerge /vobs/nextgen/ansoftcore/lib/wbintegutils 
:: -unr -nc -nmaster -follow -nzero -fversion .../products_core5.0/LATEST [-print -gmerge -merge] [-abort -gmerge]

:: Do automatic merge. If that is not possible, start a graphical merge
cleartool findmerge . -unr -nc -nmaster -follow -nzero -fversion .../products_core5.0/LATEST -merge -gmerge
