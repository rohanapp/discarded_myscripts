#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

class PrepareForLargeScaleDSOParams;


class NGANSOFTCOMAPP_API IDesktopJobSimulationManager
{
public:

  enum SimAction { kWaitForTaskSimAction, kStopWaitForTaskSimAction, kRunTaskSimAction, kInvalidSimAction };

  virtual void InitializeDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms) = 0;
  // Analysis code invokes below before taking up a task
  virtual bool IsTaskUnitStolen(int taskNum) const = 0;
  // Anaysis code waiting for a new task invokes below to fetch new task or start exiting
  virtual bool IsNewTaskAvailable(SimAction& nextAction, 
    PrepareForLargeScaleDSOParams& prms, int& newTaskUnit) const = 0;

  // Notification regarding progress/status
  virtual void NotifyOnStartReadingOfInputFiles() = 0;
  virtual void NotifyOnEndReadingOfInputFiles() = 0;

  virtual void NotifyOnStartOfSimulation() = 0;
  virtual void NotifyOnCompletionOfSimulation() = 0;

  virtual void NotifyOnStartExtractionOfResultFiles() = 0;
  virtual void NotifyOnEndExtractionOfResultFiles() = 0;

};

class IDesktopForLargeScaleDSO
{
public:
  virtual void ResetLargeScaleDSOParams(const PrepareForLargeScaleDSOParams& ldsoPrms) = 0;
};

class NGANSOFTCOMAPP_API DesktopJobSimulationManager : public IDesktopJobSimulationManager 
{
public:

  virtual void InitializeDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms);
  virtual bool DesktopJobSimulationManager::IsTaskHijackedByAnotherEngine(int taskIndex) const;

  // Notification regarding progress/status
  virtual void NotifyOnStartReadingOfInputFiles() ;
  virtual void NotifyOnEndReadingOfInputFiles() ;

  virtual void NotifyOnStartOfSimulation(int numTargetTasks, int startTaskIndex, int endTaskIndex) ;
  virtual void NotifyOnTaskStart(int taskIndex);
  virtual void NotifyOnTaskCompletion(int taskIndex, bool taskSucceeded);
  virtual void NotifyOnAllTasksCompletion() ;

  virtual void NotifyOnStartExtractionOfResultFiles() ;
  virtual void NotifyOnEndExtractionOfResultFiles() ;
  virtual void WaitForExitEvent();

private:

  void CreateEmptyFileInLargeDSOResultsFolder(const AString& fileName);
  bool DoesFileExistInLargeDSOResultsFolder(const AString& fileName);
  bool DoesFileExistInLargeDSOSessionResultsFolder(const AString& fileName);

  PrepareForLargeScaleDSOParams m_dsoPrms;
  DesktopJobSimulationProfile m_djobSimProfile;
  int m_currRunningTask;
  LongFileName m_jobOutputFolderLfn;
  LongFileName m_jobStatusFolderLfn;
};

// !!!! NgAnsoftCOMAppDLLInterface BEGIN !!!!!!!

#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"
#include "ngcore/stringutils/astring.h"

class ILargeDSOOneDResultsObject;


// Goal: ReportSetupModule reuses functions defined in NgAnsoftCOMApp dll
// Approach:
// - Use loadlibrary to load ngansoftcomapp and invokes below two functions in it
// - InitialiazeNgAnsoftCOMAppForDesktopClient: ngcore, etc. is already initialized by Desktop.
//   So above function won't have to do much.
// - ILargeDSOOneDResultsObject* CreateLargeDSOOneDResultsObject(): Create oneD results objects
// - Define ILargeDSOOneDResultsObject interface NgAnsoftCOMApp\ResultsExtractorDefs.h for now
class NgAnsoftCOMAppDLLInterface
{

public:

  static bool InitializeNgAnsoftCOMAppDLL() ;
  static bool ReleaseNgAnsoftCOMAppDLL();

  static IDesktopJobSimulationManager* CreateDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms);
  static void ReleaseDesktopJobSimulationManager(IDesktopJobSimulationManager* resObj);

};
