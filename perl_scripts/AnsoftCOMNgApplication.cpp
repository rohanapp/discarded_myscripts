#include "ngcore/ngutils/ans_debug.h"
#include "boost/program_options.hpp"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/stringutils/astring.h"
#include "CoreInterfaces/IMessageHandler.h"
#include "CoreInterfaces/IMessageManager.h"


 AnsoftCOMNgApplication::AnsoftCOMNgApplication() 
{
  IMessageManager* msgMgr= ::GetMessageManager();
  AnsoftMessageam;
  am.SetMessageText(ACHAR(""));
  msgMgr->AddAnsoftMessage(am);
}


bool AnsoftCOMNgApplication::InitializeApplication(int argc, char** argv) 
{
  CLoggingHelper logHelp(ACHAR("AnsoftCOMNgApplication::InitializeApplication"));
  logHelp.LogParam(ACHAR("argc"), argc);
  logHelp.LogParam(ACHAR("argv"), argv);
  LongFileNamelfn(f1);
  boolexists = (LFN_Exists(lfn) && !LFN_IsExistingDirectory(lfn));
  IMessageManager* msgMgr= ::GetMessageManager();
  AnsoftMessageam;
  am.SetMessageText(ACHAR(""));
  msgMgr->AddAnsoftMessage(am);
}


virtual bool AnsoftCOMNgApplication::GetCustomCommandLineOptions(BoostProgramOptionsDesc& genericOptions, BoostProgramOptionsDesc& configFileOptions, BoostProgramOptionsDesc& hiddenOptions) const
{
}


virtual bool AnsoftCOMNgApplication::ClearQMessages(const int remainingMsg) 
{
}


virtual AnsoftMessage* AnsoftCOMNgApplication::GetNextMessage() 
{
}


virtual int AnsoftCOMNgApplication::GetNumMessages() const
{
}


virtual int AnsoftCOMNgApplication::GetNumMessages(MessageSeverity severity) const
{
}


virtual bool AnsoftCOMNgApplication::HandleMessages(const AnsoftCommandContext* context) 
{
}


virtual int AnsoftCOMNgApplication::ShowQueuedMessages(UINT type, bool flushToMsgWnd, const AnsoftCommandContext* context, const AString& sQuestion) 
{
}


virtual int AnsoftCOMNgApplication::AnsoftMessageBox(const AString& message, UINT type, UINT nHelpID, bool bExitIfLogging) 
{
}


virtual int AnsoftCOMNgApplication::AnsoftMessageBox(const AnsoftMessage& message, UINT type, UINT nHelpID, bool bExitIfLogging) 
{
}


IMessageHandler* AnsoftCOMNgApplication::GetIMessageHandler() 
{
}


IMessageManager* AnsoftCOMNgApplication::GetIMessageManager() 
{
}
