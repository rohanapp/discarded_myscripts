#include "headers.h"
#include "Level2CommandAtUniqueNodeActivationTopology.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "NgAnsoftCOMApp/DistributedMachineTreeTwoLevel.h"
#include "NgAnsoftCOMApp/NgAppCommandDef.h"


int Level2CommandAtUniqueNodeActivationTopology::GetDistributedMachineListForChildActivation(DistributedMachineTreeTwoLevel& childMacList, const NgAppCommandDef& cmdDef) const
{
}


bool Level2CommandAtUniqueNodeActivationTopology::IsWorkLoadDistributionNeededAtThisLevel(const NgAppCommandDef& cmdDef) const
{
}
