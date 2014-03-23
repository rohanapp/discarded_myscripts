simplore /regserver

echo errorlevel= %errorlevel%

SimplorerServer -regserver

echo errorlevel= %errorlevel%

regsvr32 sim2000.dll

regsvr32 SimplorerCompEngine.dll

regsvr32 sdbctrl.dll

regsvr32 MathMod.dll

pause

