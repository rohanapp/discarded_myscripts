bool GenerateCSVFileForAllOneDResultFiles(const LongFileName& oneDResFolderLfn, const AString& csvOutFolderStr)
{
  CLoggingHelper logHelp(ACHAR("GenerateCSVFilesFromOneDResults"));

  AString onedResFileExtn = ILargeDSOOneDResultsObject::GetFileTypeFor1DResults();

  bool bRet = true;
  try
  {
    bool exists = (LFN_Exists(oneDResFolderLfn) && LFN_IsExistingDirectory(oneDResFolderLfn));
    if (!exists)
      throw AStringException("Folder does not exist!");

    // Foreach oneDRes file
    CFileUtilities fileUtil;
    std::vector<LongFileName> oneDResFileLfnVec;
    size_t numResFilesFound = fileUtil.SimpleFind(&oneDResFileLfnVec, oneDResFolderLfn.FilePath(), onedResFileExtn);
    for (size_t ff = 0; ff < numResFilesFound; ++ff)
    {
      const LongFileName& lfn = oneDResFileLfnVec[ff];
      DesktopDesignExtractedResultsObject desResObj;

      io::CReadError err = desResObj.ReadExtractedResultsObject(lfn);
      if (err != io::kNoError) 
      {
        ngapp::WarningMessage(FStr("Failed to read file '%s'. Error code = %d. Ignoring this file", 
          lfn.FilePath().c_str(), static_cast<int>(err)));
        bRet = false;
        continue;
      }

      std::vector<SingleQuantityCSVFileGenerator*> csvGeneratorsVec;
      DeleteVectorElementsContext<SingleQuantityCSVFileGenerator> vecElemOwnerCntxt(csvGeneratorsVec);

      const OneDimensionSimulationResults& oneDResObj = desResObj.GetOneDResults();
      if (SingleQuantityCSVFileGenerator::InitializeCSVGenerators(csvGeneratorsVec, oneDResObj, csvOutFolderStr) == false)
      {
        ngapp::ErrorMessage(ngapp::kNgAppFailed, "Unable to generate CSV file for results file '%s'", lfn.FilePath());
        continue;
      }

      std::vector<SingleQuantityCSVFileGenerator*>::iterator miter;
      for(miter = csvGeneratorsVec.begin(); miter != csvGeneratorsVec.end(); ++miter)
      {
        SingleQuantityCSVFileGenerator* csvGen = *miter;
        csvGen->ProcessOneDimensionSimulationResults(oneDResObj);
        csvGen->OnDoneProcessSimulationResults();
      }

    }
  }
  catch(AStringException& msg)
  {
    ngapp::ErrorMessage(ngapp::kNgAppFailed, "Error occurred while creating CSV files in folder '%s': %s",
      csvOutFolderStr, AString(msg.what()));
    bRet = false;
  }
  return bRet;

}

void GenerateCSVFilesForAllTasks(const DJobTaskStatusBlockObject& taskStatusObj, const LongFileName& rootJobWorkDir,
                                 const LongFileName& thisJobLocalStorageResultsDir)
{
  CLoggingHelper logHelp(ACHAR("GenerateCSVFilesForAllTasks"));

  int startGlobIndex = taskStatusObj.GetStartTaskGlobalIndexProp();
  int endGlobIndexExcl = taskStatusObj.GetEndTaskGlobalExclIndexProp();
  logHelp.LogParam(ACHAR("startGlobIndex"), startGlobIndex);
  logHelp.LogParam(ACHAR("endGlobIndexExcl"), endGlobIndexExcl);

  int currLocalIndex = 0;
  for (int tt = startGlobIndex; tt < endGlobIndexExcl; ++tt, ++currLocalIndex)
  {
    AString localIndexStr;
    localIndexStr.Format(ACHAR("%d"), currLocalIndex);
    AString globalIndexStr;
    globalIndexStr.Format(ACHAR("%d"), tt);

    LongFileName srcOneDFolderLfn(localIndexStr, thisJobLocalStorageResultsDir.FilePath());
    srcOneDFolderLfn.MakeItDirectory();
    bool srcExists = (LFN_Exists(srcOneDFolderLfn) && LFN_IsExistingDirectory(srcOneDFolderLfn));
    logHelp.LogParam(ACHAR("srcExists"), srcExists);
    if (srcExists == false)
      continue;

    LongFileName destCSvFolderLfn(globalIndexStr, rootJobWorkDir.FilePath());
    destCSvFolderLfn.MakeItDirectory();
    bool destExists = (LFN_Exists(destCSvFolderLfn) && LFN_IsExistingDirectory(destCSvFolderLfn));
    logHelp.LogParam(ACHAR("destExists"), destExists);
    if (destExists == false)
    {
      bool csvFolderCreated = LFN_CreateDirectoryAndParents(destCSvFolderLfn);
      SS_ASSERT(csvFolderCreated);
      logHelp.LogParam(ACHAR("csvFolderCreated"), csvFolderCreated);
    }

    // Now invoke the code that created
    GenerateCSVFileForAllOneDResultFiles(srcOneDFolderLfn, destCSvFolderLfn.FilePath());

  }

}