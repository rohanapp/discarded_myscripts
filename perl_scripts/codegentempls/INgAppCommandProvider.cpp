#include "headers.h"
#include "INgAppCommandProvider.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "NgAnsoftCOMApp/NgAppProgramOptions.h"
#include "NgAnsoftCOMApp/NgAppCommandDef.h"
#include "NgAnsoftCOMApp/INgAppCommandCallback.h"


void INgAppCommandProvider::GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const = 0
{
}


bool INgAppCommandProvider::ParseCommandLineOptions(io::CBlock& cmdParams, IGeneralOptionSetter* setGenOptions, const AString& cmdName, int argc, char** argv, const NgAppProgramOptions& generalOptions) = 0
{
}


bool INgAppCommandProvider::PrepareCommandExecutionEnv(const NgAppCommandDef& cmdDef, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions) = 0
{
}


bool INgAppCommandProvider::RunNgCommand(INgAppCommandCallback* icmdCB) = 0
{
}
