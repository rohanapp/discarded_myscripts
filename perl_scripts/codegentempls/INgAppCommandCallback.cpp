#include "headers.h"
#include "INgAppCommandCallback.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "wbintegutils/ProgressMessageDef.h"
#include "NgAnsoftCOMApp/NgAppCommandProgress.h"
#include "NgAnsoftCOMApp/NgAppCommandResult.h"
#include "NgAnsoftCOMApp/NgAppCommandDef.h"
#include "NgAnsoftCOMApp/NgAppProgramOptions.h"
#include "ngcore/streamio/block.h"


void INgAppCommandCallback::OnNgAppCommandMessage(bool& isAborted, const ProgressMessageDef& msg) = 0
{
}


void INgAppCommandCallback::OnNgAppCommandProgress(bool& isAborted, const NgAppCommandProgress& prog) = 0
{
}


void INgAppCommandCallback::OnNgAppCommandResult(const NgAppCommandResult& res) = 0
{
}


const NgAppCommandDef& INgAppCommandCallback::GetNgAppCommandDef() const = 0
{
}


const NgAppProgramOptions& INgAppCommandCallback::GetNgAppProgramGeneralOptions() = 0
{
}


const io::CBlock& INgAppCommandCallback::GetNgAppCommandParameters() = 0
{
}


CommandState INgAppCommandCallback::GetCommandCurrentState() const = 0
{
}


bool INgAppCommandCallback::IsCommandAbortedByUser() const = 0
{
  return false;
}
