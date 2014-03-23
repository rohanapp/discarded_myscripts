@echo off

if NOT EXIST ansoftcore (
   echo mkdir ansoftcore
   mkdir ansoftcore
)

if NOT EXIST bouldervob (
   echo mkdir bouldervob
   mkdir bouldervob
)

if NOT EXIST bostonvob (
   echo mkdir bostonvob
   mkdir bostonvob
)

if NOT EXIST examples (
   echo mkdir examples
   mkdir examples
)

if NOT EXIST pgh_docs (
   echo mkdir pgh_docs
   mkdir pgh_docs
)

if NOT EXIST thirdparty (
   echo mkdir thirdparty
   mkdir thirdparty
)

if NOT EXIST thirdparty_vob2 (
   echo mkdir thirdparty_vob2
   mkdir thirdparty_vob2
)

:: Boost DLLs
copy /V /Y nextgen\ansoftcore\thirdparty\boost\bin\INTEL\Debug\*.dll nextgen\ansoftcore\INTEL\Debug
copy /V /Y nextgen\ansoftcore\thirdparty\boost\bin\INTEL\Debug\*.dll nextgen\debug
copy /V /Y nextgen\ansoftcore\thirdparty\boost\bin\INTEL\Release\*.dll nextgen\ansoftcore\INTEL\Release
copy /V /Y nextgen\ansoftcore\thirdparty\boost\bin\INTEL\Release\*.dll nextgen\release

:: Xerces DLLs
copy /V /Y nextgen\ansoftcore\thirdparty\xerces\bin\VC9\*.dll nextgen\ansoftcore\INTEL\Debug
copy /V /Y nextgen\ansoftcore\thirdparty\xerces\bin\VC9\*.dll nextgen\debug
copy /V /Y nextgen\ansoftcore\thirdparty\xerces\bin\VC9\*.dll nextgen\ansoftcore\INTEL\Release
copy /V /Y nextgen\ansoftcore\thirdparty\xerces\bin\VC9\*.dll nextgen\release

:: ACIS DLLs
copy /V /Y nextgen\ansoftcore\thirdparty\acis\bin_win_vc9\*.dll nextgen\ansoftcore\INTEL\Release
copy /V /Y nextgen\ansoftcore\thirdparty\acis\bin_win_vc9\*.dll nextgen\release
copy /V /Y nextgen\ansoftcore\thirdparty\acis\bin_win_vc9_dbg nextgen\ansoftcore\INTEL\Debug
copy /V /Y nextgen\ansoftcore\thirdparty\acis\bin_win_vc9_dbg nextgen\debug
