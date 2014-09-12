@echo off

if NOT exist 64Debug (
   echo mkdir 64Debug
   mkdir 64Debug
)

echo call del 64Debug\%1.log
call del 64Debug\%1.log

echo "C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /property:Configuration=Debug;Platform=x64 /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /distributedFileLogger /l:FileLogger,Microsoft.Build.Engine;logfile=64Debug\%1.log %1.sln
"C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /property:Configuration=Debug;Platform=x64 /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /distributedFileLogger /l:FileLogger,Microsoft.Build.Engine;logfile=64Debug\%1.log %1.sln

