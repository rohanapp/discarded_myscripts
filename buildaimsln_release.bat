@echo off

if NOT exist 64Release (
   echo mkdir 64Release
   mkdir 64Release
)

echo call del 64Release\%1.log
call del 64Release\%1.log

echo "C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /property:Configuration=Release;Platform=Win64 /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /distributedFileLogger /l:FileLogger,Microsoft.Build.Engine;logfile=64Release\%1.log %1.sln
"C:\Windows\Microsoft.NET\Framework\v4.0.30319\MsBuild.exe" /property:Configuration=Release;Platform=Win64 /consoleloggerparameters:PerformanceSummary;ErrorsOnly /maxcpucount:4 /distributedFileLogger /l:FileLogger,Microsoft.Build.Engine;logfile=64Release\%1.log %1.sln

