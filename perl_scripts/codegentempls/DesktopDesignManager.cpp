#include "headers.h"
#include "DesktopDesignManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "string"


 DesktopDesignManager::DesktopDesignManager(const std::string& systemLibPath, const std::string& userLibPath) 
{
}


 DesktopDesignManager::~DesktopDesignManager() 
{
}


DesktopDesign* DesktopDesignManager::OnNewMCADModel() 
{
}


ComponentInstance* DesktopDesignManager::OnPlaceModel(DesktopDesignInstance* subDesignBeingPlaced, DesktopDesignInstance* parentDesignInstance) 
{
}


bool DesktopDesignManager::OnRemoveModel(DesktopDesign* modelOfProj) 
{
}
