#include "headers.h"
#include "WindowsAppCrashLogger.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/LongFilenameOperations.h"
#include "ngcore/ipcutils/GeneralFunctions.h"
#include "ngcore/streamio/token_ostream.h"
#include "ngcore/streamio/token_iostream.h"


 WindowsAppCrashLogger::WindowsAppCrashLogger(const AString& logFileDirPath) 
{
  SS_ASSERT(!ACHAR(""));
}


 WindowsAppCrashLogger::~WindowsAppCrashLogger() 
{
}


void WindowsAppCrashLogger::DumpCrashLog() 
{
  static const AChar* envVar = i18n::ACharGetEnv(ACHAR("YOUR_ENV"));
  LongFileName lfn(f1); //Note: lfn.Exists returns 1 if exists as a file or something else (could even be a positive number! So must check for 1)
  bool exists = (LFN_Exists(lfn) && !LFN_IsExistingDirectory(lfn));
  int procID = static_cast<int>GetCurrentProcessId();
  // very useful example code: ngcore\streamio\source\test_streamio.cpp
  LongFileName outFileLfn(filePath);
  io::CToken_ostream outStream(outFileLfn);
  outStream << blk;
  outStream.Close();
  if (outStream.fail())
  //{
  ngapp::ErrorMessage(ngapp::kNgAppFailed, "Failed to write block '%s' to file '%s'", blk.Name(), filePath);
  return false;
  //}
  // outStream.Format(false);
  // outStream << io::NewLine;
  LongFileName lfn(logFilePath);
  mBatchLogStream = new io::CToken_iostream(lfn, io_base::kModeText);
  *mBatchLogStream << io::NoFormat(ACHAR(" "));
  *mBatchLogStream << io::Eol;
  
  // sample format is:
  // Ansoft HFSS Version 11.1, Build: Apr 11 2008 02:05:20
  // Batch Solve/Save: IF_Filter_Opt_Example_mark.hfss
  AString sDate, sTime;
  GetBuildDateAndTime(sDate, sTime);
  
  AString str;
  str.Format(ACHAR("%s Version %s, Build: %s %s"),
  GetFullProductName().c_str(),
  GetVersionString().c_str(),
  sDate.c_str(),
  sTime.c_str());
  
  *mBatchLogStream << io::NoFormat(str);
  *mBatchLogStream << io::Eol;
  
  // display exe location
  *mBatchLogStream << io::NoFormat(ACHAR("Location: "));
  AChar filePath[MAX_PATH];
  ::GetModuleFileName(NULL, filePath, MAX_PATH);
  *mBatchLogStream << io::NoFormat(AString(filePath));
  *mBatchLogStream << io::Eol;
  
  *mBatchLogStream << io::NoFormat(batchInfo);
  *mBatchLogStream << io::Eol;
  *mBatchLogStream << io::NoFormat(ACHAR("Starting Batch Run: "));
  
  AString timeDateStamp = i18n::GetTimeDateStamp();
  *mBatchLogStream << io::NoFormat(timeDateStamp);
  *mBatchLogStream << io::Eol;
  mBatchLogStream->Stream().flush();
  SS_ASSERT(!ACHAR(""));
}
