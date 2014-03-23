#include "headers.h"
#include "NgAnsoftCOMApplication.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "wbintegutils/LoggingHelper.h"
#include "CoreInterfaces/IMessageHandler.h"


bool NgAnsoftCOMApplication::HandleClientCallbackFromService(const io::CBlock& msgAsBlock) 
{
  CLoggingHelper logHelp(ACHAR("NgAnsoftCOMApplication::HandleClientCallbackFromService"));
  logHelp.LogParam(ACHAR("msgAsBlock"), msgAsBlock);
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
}


bool NgAnsoftCOMApplication::HandleServiceRequestFromClient(const io::CBlock& cmdAsBlock) 
{
  CLoggingHelper logHelp(ACHAR("NgAnsoftCOMApplication::HandleServiceRequestFromClient"));
  logHelp.LogParam(ACHAR("cmdAsBlock"), cmdAsBlock);
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
}
