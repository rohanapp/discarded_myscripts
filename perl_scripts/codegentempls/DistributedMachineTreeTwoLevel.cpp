#include "headers.h"
#include "DistributedMachineTreeTwoLevel.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"


bool DistributedMachineTreeTwoLevel::InitializeMachinesToTwoLevel(const std::vector<AString>& uniqueNodesAtFirstLevel, const std::vector<int>& uniqueNodeCoresAtSecondLevel) 
{
}


bool DistributedMachineTreeTwoLevel::InitializeMachinesToSingleLevel(const std::vector<AString>& nodeVec) 
{
}


int DistributedMachineTreeTwoLevel::GetFlatMachineListForImmediateChildren(std::vector<AString>& macNamesVec, std::vector<int>& vecMacCores) const
{
}


int DistributedMachineTreeTwoLevel::GetFlatMachineListForGrandChildren(std::vector<AString>& macNamesVec, std::vector<int>& vecMacCores, int childIndex) const
{
}
