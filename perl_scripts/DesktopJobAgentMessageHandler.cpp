#include "DesktopJobAgentMessageHandler.h"

void DesktopJobAgentMessageHandler::AddAnsoftMessage(const AnsoftMessage& msg)
{
  CLoggingHelper logHelp(ACHAR("AddAnsoftMessage"));
  logHelp.LogParam(ACHAR("msg"), msg);
}

