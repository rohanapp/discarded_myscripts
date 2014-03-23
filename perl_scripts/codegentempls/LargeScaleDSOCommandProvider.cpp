#include "headers.h"
#include "LargeScaleDSOCommandProvider.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "NgAnsoftCOMApp/NgAppProgramOptions.h"
#include "NgAnsoftCOMApp/INgAppCommandCallback.h"
#include "wbintegutils/LoggingHelper.h"
#include "CoreInterfaces/IMessageHandler.h"


void LargeScaleDSOCommandProvider::GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const
{
  CLoggingHelper logHelp(ACHAR("LargeScaleDSOCommandProvider::GetSupportedNgCommands"));
  logHelp.LogParam(ACHAR("cmdUniqueNames"), cmdUniqueNames);
}


bool LargeScaleDSOCommandProvider::ParseCommandLineOptions(io::CBlock& cmdParams, IGeneralOptionSetter* setGenOptions, const AString& cmdName, int argc, char** argv, const NgAppProgramOptions& generalOptions) 
{
}


bool LargeScaleDSOCommandProvider::PrepareCommandExecutionEnv(const AString& cmdName, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions) 
{
  ::AnsDebug(ACHAR(""), 1, ACHAR("\n"));
  // debug logging is ON for level "1" and file context
  if(my_ans_debug_data.Debug(1) == true)
  CLoggingHelper logHelp(ACHAR("LargeScaleDSOCommandProvider::PrepareCommandExecutionEnv"));
  logHelp.LogParam(ACHAR("cmdName"), cmdName);
  logHelp.LogParam(ACHAR("cmdParams"), cmdParams);
  logHelp.LogParam(ACHAR("generalOptions"), generalOptions);
  IMessageManager* msgMgr = ::GetMessageManager();
  AnsoftMessage am;
  AString msgstr;
  msgstr.Format(ACHAR(""))
  am.SetMessageText(msgstr);
  // Possible values of MessageSeverity: kErrorMessage, kWarningMessage, kInfoMessage, kFatalMessage
  MessageSeverity severity = kErrorMessage;
  am.ChangeSeverity(severity);
  msgMgr->AddAnsoftMessage(am);
  
  IMessageHandlerBase* hdlrBase = msgMgr->GetIMessageHandlerBase();
  MessageQueueRestorer mqueueRestorer(hdlrBase);
  mqueueRestorer.Disable();
  
  IMessageHandler* hndlr = dynamic_cast<IMessageHandler*>(hdlrBase);
  SS_ASSERT(hndlr);
  hndlr->HandleMessages(0/*context*/);
  SS_ASSERT(!ACHAR(""));
  return true;
}


bool LargeScaleDSOCommandProvider::RunNgCommand(INgAppCommandCallback* icmdCB) 
{
  ::AnsDebug(ACHAR(""), 1, ACHAR("\n"));
  // debug logging is ON for level "1" and file context
  if(my_ans_debug_data.Debug(1) == true)
  CLoggingHelper logHelp(ACHAR("LargeScaleDSOCommandProvider::RunNgCommand"));
  logHelp.LogParam(ACHAR("icmdCB"), icmdCB);
  IMessageManager* msgMgr = ::GetMessageManager();
  AnsoftMessage am;
  AString msgstr;
  msgstr.Format(ACHAR(""))
  am.SetMessageText(msgstr);
  // Possible values of MessageSeverity: kErrorMessage, kWarningMessage, kInfoMessage, kFatalMessage
  MessageSeverity severity = kErrorMessage;
  am.ChangeSeverity(severity);
  msgMgr->AddAnsoftMessage(am);
  
  IMessageHandlerBase* hdlrBase = msgMgr->GetIMessageHandlerBase();
  MessageQueueRestorer mqueueRestorer(hdlrBase);
  mqueueRestorer.Disable();
  
  IMessageHandler* hndlr = dynamic_cast<IMessageHandler*>(hdlrBase);
  SS_ASSERT(hndlr);
  hndlr->HandleMessages(0/*context*/);
  SS_ASSERT(!ACHAR(""));
  return true;
}
