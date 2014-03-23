#include "headers.h"
#include "DesktopJobSimulationManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "wbintegutils/PrepareForLargeScaleDSOParams.h"


bool DesktopJobSimulationManager::IsTaskUnitStolen(int taskNum) const
{
}


bool DesktopJobSimulationManager::IsNewTaskAvailable(SimAction& nextAction) const
{
}


bool DesktopJobSimulationManager::FetchNewTaskAssigned(PrepareForLargeScaleDSOParams& prms, int& newTaskUnit) 
{
}


void DesktopJobSimulationManager::NotifyOnStartReadingOfInputFiles() 
{
}


void DesktopJobSimulationManager::NotifyOnEndReadingOfInputFiles() 
{
}


void DesktopJobSimulationManager::NotifyOnStartOfSimulation() 
{
}


void DesktopJobSimulationManager::NotifyOnCompletionOfSimulation() 
{
}


void DesktopJobSimulationManager::NotifyOnStartExtractionOfResultFiles() 
{
}


void DesktopJobSimulationManager::NotifyOnEndExtractionOfResultFiles() 
{
}
