#include "headers.h"
#include "INgAppDistributedServiceProxy.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"


void INgAppDistributedServiceProxy::OnDoneUsingService() = 0
{
}


int INgAppDistributedServiceProxy::DistributeNgAppCommandToAllNodes() = 0
{
}
