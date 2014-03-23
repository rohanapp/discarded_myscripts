#include "headers.h"
#include "ICallbacksForDesktopApp.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "CoreInterfaces/IDesktop.h"
#include "CoreInterfaces/IProject.h"
#include "ngcore/ngutils/LongFileName.h"
#include "CoreInterfaces/IMessageHandler.h"


IDesktop* ICallbacksForDesktopApp::GetIDesktop() = 0
{
}


IProject* ICallbacksForDesktopApp::GetActiveIProject() const = 0
{
}


bool ICallbacksForDesktopApp::IsProjectLocked(const LongFileName& projectFile) = 0
{
}


void ICallbacksForDesktopApp::UnlockProject(const LongFileName& projectFileName) = 0
{
}


IMessageHandler* ICallbacksForDesktopApp::GetIMessageHandler() = 0
{
}
