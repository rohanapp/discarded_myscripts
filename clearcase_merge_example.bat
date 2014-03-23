@echo off

set cwd=%CD%

cd "C:\views\naresh_core5_view"
if errorlevel 1 goto error

call ct merge -to nextgen\products\aciskern\AcisGeometryKernel.h  -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\geometrycore\source\GeomOperationsManager.cpp -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\geometrycore\source\GeometryManagerInstance.cpp -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\geometrycore\GeometryManagerInstance.h -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\interfaces\geomkernel\INativeKernel.h -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\GeomInterrogationManager\GeomInterrogationManager.h -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\GeomInterrogationManager\source\GeomInterrogationManager.cpp -version /main/core5/LATEST
if errorlevel 1 goto error

call ct merge -to nextgen\lib\geometrycore\source\RegionOperation.cpp -version /main/core5/LATEST
if errorlevel 1 goto error

goto finish

:error
echo Error occured

:finish
cd %cwd%

