#include "headers.h"
#include "INgAppDistributedApplication.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"


int INgAppDistributedApplication::GetDistributionLevelOfThisApp() const = 0
{
}


AString INgAppDistributedApplication::GetHostMachineName() const = 0
{
}


AString INgAppDistributedApplication::GetSiblingRelativeRank() const = 0
{
}
