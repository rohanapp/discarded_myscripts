@echo off

#echo call msdev.exe /Y3 %1.dsw /out debug\all_%1.log /make "ALL - Win32 Debug" /NORECURSE
#call msdev.exe /Y3 %1.dsw /out debug\all_%1.log /make "ALL - Win32 Debug" /NORECURSE

echo call msdev.exe /Y3 %1.dsw /out debug\%1.log /make "%2 - Win32 Debug"
call msdev.exe /Y3 %1.dsw /out debug\%1.log /make "%2 - Win32 Debug"

#echo call msdev.exe /Y3 %1.dsw /out release\all_%1.log /make "ALL - Win32 Release" /NORECURSE
#call msdev.exe /Y3 %1.dsw /out release\all_%1.log /make "ALL - Win32 Release" /NORECURSE

echo call msdev.exe /Y3 %1.dsw /out release\%1.log /make "%2 - Win32 Release"
call msdev.exe /Y3 %1.dsw /out release\%1.log /make "%2 - Win32 Release"
