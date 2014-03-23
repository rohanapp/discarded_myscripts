#include "headers.h"
#include "NgAppDistributedCommMgr.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "NgAnsoftCOMApp/NgAppAnsoftCOMApplication.h"
#include "wbintegutils/LoggingHelper.h"


 NgAppDistributedCommMgr::NgAppDistributedCommMgr(NgAppAnsoftCOMApplication* owner) 
{
  SS_ASSERT(!ACHAR(""));
}


 NgAppDistributedCommMgr::~NgAppDistributedCommMgr() 
{
}


bool NgAppDistributedCommMgr::InitializeCommunicationObjects() 
{
  CLoggingHelper logHelp(ACHAR("NgAppDistributedCommMgr::InitializeCommunicationObjects"));
}
