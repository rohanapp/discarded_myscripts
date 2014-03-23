#include "headers.h"
#include "NgAppAnsoftCommand.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "wbintegutils/ProgressMessageDef.h"
#include "NgAnsoftCOMApp/NgAppCommandProgress.h"
#include "NgAnsoftCOMApp/NgAppCommandResult.h"
#include "NgAnsoftCOMApp/NgAppProgramOptions.h"


 NgAppAnsoftCommand::NgAppAnsoftCommand(const NgAppCommandDef& cmdDef, CommandState state) 
{
}


 NgAppAnsoftCommand::~NgAppAnsoftCommand() 
{
}


void NgAppAnsoftCommand::OnNgAppCommandMessage(const ProgressMessageDef& msg) 
{
}


void NgAppAnsoftCommand::OnNgAppCommandProgress(bool& isAborted, const NgAppCommandProgress& prog) 
{
}


void NgAppAnsoftCommand::OnNgAppCommandResult(const NgAppCommandResult& res) 
{
}


const NgAppCommandDef& NgAppAnsoftCommand::GetNgAppCommandDef() const
{
}


const NgAppProgramOptions& NgAppAnsoftCommand::GetNgAppProgramGeneralOptions() 
{
}


const io::CBlock& NgAppAnsoftCommand::GetNgAppCommandParameters() 
{
}


bool NgAppAnsoftCommand::IsCommandAbortedByUser() const
{
  return false;
}


CommandState NgAppAnsoftCommand::GetCommandCurrentState() const
{
}


void NgAppAnsoftCommand::SetIsCommandAbortedByUser() 
{
}


void NgAppAnsoftCommand::SetCommandCurrentState(CommandState state) 
{
}
