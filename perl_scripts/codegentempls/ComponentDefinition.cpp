#include "headers.h"
#include "ComponentDefinition.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "string"


 ComponentDefinition::ComponentDefinition() 
{
}


 ComponentDefinition::~ComponentDefinition() 
{
}


void ComponentDefinition::SetComponentName(const std::string& name) 
{
}


bool ComponentDefinition::AddParameter(const std::string& paramName, double paramValue) 
{
}


bool ComponentDefinition::RemoveParameter(const std::string& paramName) 
{
}


const ParameterList& ComponentDefinition::GetParameterDefaults() const
{
}
