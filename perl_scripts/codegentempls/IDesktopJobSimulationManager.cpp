#include "headers.h"
#include "IDesktopJobSimulationManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "wbintegutils/PrepareForLargeScaleDSOParams.h"


void IDesktopJobSimulationManager::InitializeDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms) = 0
{
}


void IDesktopJobSimulationManager::NotifyOnStartReadingOfInputFiles() = 0
{
}


void IDesktopJobSimulationManager::NotifyOnEndReadingOfInputFiles() = 0
{
}


void IDesktopJobSimulationManager::ForceAbortJob() = 0
{
}


void IDesktopJobSimulationManager::NotifyOnSimulationStart(int numTargetTasks, int startTaskIndex, int endTaskIndex) = 0
{
}


bool IDesktopJobSimulationManager::IsTaskHijackedByAnotherEngine(int taskIndex) const = 0
{
}


void IDesktopJobSimulationManager::NotifyOnTaskStart(int taskIndex) = 0
{
}


void IDesktopJobSimulationManager::NotifyOnTaskCompletion(int taskIndex, bool taskSucceeded) = 0
{
}


void IDesktopJobSimulationManager::NotifyOnAllTasksCompletion() = 0
{
}


void IDesktopJobSimulationManager::WaitForExitEvent() = 0
{
}


void IDesktopJobSimulationManager::NotifyOnStartExtractionOfResultFiles() = 0
{
}


void IDesktopJobSimulationManager::NotifyOnEndExtractionOfResultFiles() = 0
{
}
