#include "headers.h"
#include "MCADModelsManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "string"


 MCADModelsManager::MCADModelsManager(const std::string& systemLibPath, const std::string& userLibPath) 
{
}


 MCADModelsManager::~MCADModelsManager() 
{
}


MCADModel* MCADModelsManager::OnNewMCADModel() 
{
}


bool MCADModelsManager::OnRemoveMCADModel(MCADModel* modelOfProj) 
{
}
