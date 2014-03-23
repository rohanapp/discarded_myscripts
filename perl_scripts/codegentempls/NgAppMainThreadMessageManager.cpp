#include "headers.h"
#include "NgAppMainThreadMessageManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/stringutils/astring.h"
#include "wbintegutils/LoggingHelper.h"
#include "ngcore/ngutils/LongFilenameOperations.h"
#include "ngcore/ipcutils/GeneralFunctions.h"


 NgAppMainThreadMessageManager::NgAppMainThreadMessageManager() 
{
  CLoggingHelper logHelp(ACHAR("NgAppMainThreadMessageManager::NgAppMainThreadMessageManager"));
  LongFileName lfn(f1);
  bool exists = (LFN_Exists(lfn) && !LFN_IsExistingDirectory(lfn));
}


bool NgAppMainThreadMessageManager::SetMessageDestinationFile(const AString& pathToLogFile) 
{
  CLoggingHelper logHelp(ACHAR("NgAppMainThreadMessageManager::SetMessageDestinationFile"));
  logHelp.LogParam(ACHAR("pathToLogFile"), pathToLogFile);
  LongFileName lfn(f1);
  bool exists = (LFN_Exists(lfn) && LFN_IsExistingDirectory(lfn));
  bool ret = AnstIsDirectoryWriteable(dirPath);
}
