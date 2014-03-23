d:

echo cd \views\naresh_core_latest_view\nextgen\lib\%1\source
cd \views\naresh_core_latest_view\nextgen\lib\%1\source

echo call perl D:\public\VCProjUtilities\ensureIncludes_copy.pl -vcproj %1.vcproj
call perl D:\public\VCProjUtilities\ensureIncludes_copy.pl -vcproj %1.vcproj
