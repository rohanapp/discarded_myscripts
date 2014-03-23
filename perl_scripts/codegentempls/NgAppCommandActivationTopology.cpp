#include "headers.h"
#include "NgAppCommandActivationTopology.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "NgAnsoftCOMApp/DistributedMachineTreeTwoLevel.h"
#include "NgAnsoftCOMApp/NgAppCommandDef.h"


int NgAppCommandActivationTopology::GetDistributedMachineListForChildActivation(DistributedMachineTreeTwoLevel& macList, const NgAppCommandDef& cmdDef) const = 0
{
}


bool NgAppCommandActivationTopology::IsWorkLoadDistributionNeededAtThisLevel(const NgAppCommandDef& cmdDef) const = 0
{
}
