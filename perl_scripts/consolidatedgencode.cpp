#include "headers.h"
#include "IDesktopJobSimulationManager.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "wbintegutils/PrepareForLargeScaleDSOParams.h"

// Desktopjob to create largedso folder
void CreateLargeDSOFolderUpfrontBeforeLaunchingDesktop()
{

}

// Owner client of IDesktopJobSimulationManager
#include "NgAnsoftCOMApp/IDesktopJobSimulationManager.h"
void ParseLargeScaleDSOParamsRightAtBeginningAndInitializeDJobSimMgr(const PrepareForLargeScaleDSOParams& prms)
{
  IDesktopJobSimulationManager* m_djobSimMgr = NgAnsoftCOMAppDLLInterface::CreateDesktopJobSimulationManager(prms);
  SS_ASSERT(m_djobSimMgr);
}

void ReadProjectStart(IDesktopJobSimulationManager* m_djobSimMgr)
{
  m_djobSimMgr->NotifyOnStartReadingOfInputFiles();
}

void ReadProjectDone(IDesktopJobSimulationManager* m_djobSimMgr)
{
  m_djobSimMgr->NotifyOnEndReadingOfInputFiles();
}

// Client of IDesktopJobSimulationManager: Optimetrics code
void OptiStartSimulation(const PrepareForLargeScaleDSOParams& prms)
{

}


// Implementation of IDesktopJobSimulationManager: ngapp code
#include "NgAnsoftCOMApp/IDesktopJobSimulationManager.h"
void DesktopJobSimulationManager::InitializeDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms)
{
  m_dsoPrms = prms;
}

// Below should go into ngapp utils

namespace ngapp
{
  bool TouchNewFile(const LongFileName& newFileLfn)
  {
    SS_ASSERT(!LFN_Exists(newFileLfn));
    io::CToken_ostream outStream(newFileLfn); // Create empty file
    outStream..Close();
  }
  bool DoesFileExist(const LongFileName& lfn)
  {
    bool exists = (LFN_Exists(lfn) && !LFN_IsExistingDirectory(lfn));
    return exists;
  }
  bool DoesFileExist(const AString& fileName, const AString& fileFolder, const AChar* fileExt = 0)
  {
    LongFileName lfn(fileName, fileFolder);
    if (fileExt)
      lfn.ChangeExt(fileExt);
    return DoesFileExist(lfn);
  }
  bool DoesFileExist(const AString& filePath)
  {
    LongFileName lfn(fileName, fileFolder);
    return DoesFileExist(lfn);
  }
}

static const AChar* kReadInputFilesStartNotificationFile = ACHAR("readinputbegin");
static const AChar* kReadInputFilesDoneNotificationFile = ACHAR("readinputdone");
static const AChar* kTaskBeginNotificationFile = ACHAR("taskbegin");
static const AChar* kTaskDoneSuccessNotificationFile = ACHAR("taskdonesuccess");
static const AChar* kTaskDoneErrorNotificationFile = ACHAR("taskdoneerror");
static const AChar* kSimulationBeginNotificationFile = ACHAR("simulationbegin");
static const AChar* kSimulationDoneNotificationFile = ACHAR("simulationdone");
static const AChar* kAllTasksDoneNotificationFile = ACHAR("alltasksdone");
static const AChar* kWaitForTaskNotificationFile = ACHAR("waitfortask");
static const AChar* kExtractResultsStartNotificationFile = ACHAR("extractbegin");
static const AChar* kExtractResultsDoneSuccessNotificationFile = ACHAR("extractdonesuccess");
static const AChar* kExtractResultsDoneErrorNotificationFile = ACHAR("extractdoneerror");
static const AChar* kNewTaskInformationFile = ACHAR("newtaskinfo");
//static const AChar* kNotificationFile = ACHAR("");

void DesktopJobSimulationManager::CreateEmptyFileInLargeDSOFolder(const AString& fileName)
{
  LongFileName resFolderLfn;
  m_dsoPrms.GetLargeScaleDSOResultsFolder(resFolderLfn);

  LongFileName notificationMarkerFileLfn(fileName, resFolderLfn);
  bool bRet = ngapp::TouchNewFile(notificationMarkerFileLfn);
  SS_ASSERT(bRet);
}

bool DesktopJobSimulationManager::DoesFileExistInLargeDSOResultsFolder(const AString& fileName)
{
  LongFileName resFolderLfn;
  m_dsoPrms.GetLargeScaleDSOResultsFolder(resFolderLfn);
  return ngapp::DoesFileExist(fileName, resFolderLfn.FilePath());
}

bool DesktopJobSimulationManager::DoesFileExistInLargeDSOSessionResultsFolder(const AString& fileName)
{
  LongFileName resFolderLfn;
  m_dsoPrms.DoesFileExistInLargeDSOSessionResultsFolder(resFolderLfn);
  return ngapp::DoesFileExist(fileName, resFolderLfn.FilePath());
}

void DesktopJobSimulationManager::NotifyOnStartReadingOfInputFiles() 
{
  CreateEmptyFileInLargeDSOResultsFolder(kReadInputFilesStartNotificationFile);
}


void DesktopJobSimulationManager::NotifyOnEndReadingOfInputFiles() 
{
  CreateEmptyFileInLargeDSOResultsFolder(kReadInputFilesDoneNotificationFile);
}

class DesktopJobTaskDefinition
{
public:
  DesktopJobTaskDefinition(int numTargetTasks, int startTaskIndex, int endTaskIndex);
  io::ReadError DoDataExchange(io::CBlock& blk, bool doRead);
private:
  int m_numTargetTasks;
  int m_startTaskIndex;
  int m_endTaskIndex;
};

void DesktopJobSimulationManager::NotifyOnStartOfSimulation(int numTargetTasks, int startTaskIndex, int endTaskIndex) 
{
  // Write task definition file 'taskdef'
  //DesktopJobTaskDefinition tskDefn(numTargetTasks, startTaskIndex, endTaskIndex);
  //io::CBlock blk;
  //tskDefn.DoDataExchange(blk);
  //ngapp::WriteBlockToFile(LongFileName(ACHAR("somefile")));
  //// When below marker file is written, it is an indication that the task-definiton file can be read
  //CreateEmptyFileInLargeDSOFolder(kSimulationBeginNotificationFile);
}

bool DesktopJobSimulationManager::IsTaskHijackedByAnotherEngine(int taskIndex) const
{
  // Check the 'hijacked' folder for a file with the name of taskIndex
  return false;
}

void DesktopJobSimulationManager::NotifyOnTaskStart(int taskIndex)
{
  // Touch a file with same name as taskIndex. Folder: dso-status-folder/Running
  //LongFileName folderLfn; // REVISIT: cache this as a member rather than computing each time
  //m_dsoPrms.GetLargeScaleDSOStatusFolder(folderLfn);
  //AString taskIndexStr;
  //taskIndexStr.Format(ACHAR("%d"), taskIndex);
  // CreateEmptyFileInLargeDSOFolder(kStatusFolder, taskIndexStr, ACHAR("Running"))
  //taskOutputFolderLfn.Reset(taskIndexStr, taskOutputFolderLfn.FilePath());

  //// Create the sub folder for outputs of this task
  //LongFileName taskOutputFolderLfn;
  //m_dsoPrms.GetLargeScaleDSOResultsFolder(taskOutputFolderLfn);
  //AString taskIndexStr;
  //taskIndexStr.Format(ACHAR("%d"), taskIndex);
  //taskOutputFolderLfn.Reset(taskIndexStr, taskOutputFolderLfn.FilePath());

  //bool bRet = LFN_CreateDirectoryAndParents(taskOutputFolderLfn);
  //SS_ASSERT(bRet);

  // Note the start time and end time and update task statistics
  // m_djobSimProfile.NotifyOnTaskStart(taskIndex);

  // Save the file to disk
  // Note: save to temp and move the file
}

// Optimetrics code
void TakeupNextTask(IDesktopJobSimulationManager* m_simMgr, int taskIndex)
{
  int taskToRun = taskIndex;
  if (m_simMgr->IsTaskHijackedByAnotherEngine(taskIndex) == true)
  {
    // Skip to next task
  }
  m_simMgr->NotifyOnTaskStart(taskToRun);
}

void DesktopJobSimulationManager::NotifyOnTaskCompletion(int taskIndex, bool taskSucceeded)
{
  // Move the taskIndex file from Running folder to Success or Failed folder
  // LongFileName runningFolderFileLfn = ...
  // LongFileName successFolderFileLfn = ...
  // LongFileName failedFolderFileLfn = ...
  // LFN_Move(runningFolderFileLfn, successFolderFileLfn);
  // LFN_Move(runningFolderFileLfn, failedFolderFileLfn)

  // m_djobSimProfile.NotifyOnTaskCompletion(taskIndex, bool taskSucceeded);

}

void DesktopJobSimulationManager::NotifyOnAllTasksCompletion() 
{
  // Check if other jobs have tasks that can be stolen by this job
  //CreateEmptyFileInLargeDSOFolder(kAllTasksDoneNotificationFile);
}

void DesktopJobSimulationManager::WaitForExitEvent()
{
  if (m_dsoPrms.GetDesktopType() == PrepareForLargeScaleDSOParams::kDesktopTypeJobMaster)
  {
    // Wait until 'shutdown' (or some such named) file is written
  }
}

void DesktopJobSimulationManager::NotifyOnStartExtractionOfResultFiles() 
{
  //CreateEmptyFileInLargeDSOFolder(kExtractResultsStartNotificationFile);
}


void DesktopJobSimulationManager::NotifyOnEndExtractionOfResultFiles() 
{
  //CreateEmptyFileInLargeDSOFolder(kExtractResultsStartNotificationFile);
}


//
// !!!! NgAnsoftCOMAppDLLInterface BEGIN !!!!!!!
//

#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/stringutils/astring.h"
#include "ngcore/streamio/block.h"
#include "CoreInterfaces/IMessageHandler.h"
#include "NgAnsoftCOMApp/NgAnsoftCOMApplicationUtils.h"
#include "ngcore/ngutils/LongFilenameOperations.h"
#include "ngcore/ipcutils/GeneralFunctions.h"
#include "ngcore/registry/RegistryAccessNg.h"
#include "AnsoftCOM/AnsoftCOMDefinitions.h"

static ANSOFTHINSTANCE gNgAnsoftCOMAppDLLHandle = 0;

template <class TFuncSig>
static ANSOFTFARPROC GetNgAnsoftCOMAppProcAddr(TFuncSig& funcSig, const AString& procStr)
{
  SS_ASSERT(gNgAnsoftCOMAppDLLHandle);
  ANSOFTFARPROC procAddr = gNgAnsoftCOMAppDLLHandle ? ::AnstGetProc(gNgAnsoftCOMAppDLLHandle, procStr) : 0;
  funcSig = reinterpret_cast<TFuncSig>(procAddr);
  return procAddr;
}

// REVISIT: remove this function and replace callers with same named function from
// NgAnsoftCOMApp DLL
static AString GetPlatformSpecificDLLName(const AChar* windowsDLLName)
{
  AString libname = windowsDLLName;

  // Unix systems follow a different naming convention for shared libraries and
  // hence more attributes to the name for Unix alone. - Leena

#if defined(SUN_ANSOFT) || defined(LINUX_ANSOFT)
#ifdef BUILD64
  libname = AString("lib") + libname + AString("_64.so");
#else
  libname = AString("lib") + libname + AString(".so");
#endif
#endif

  return libname;
}

static bool LoadNgAnsoftCOMAppDLL()
{
  SS_ASSERT(!gNgAnsoftCOMAppDLLHandle);

  AString dllName = GetPlatformSpecificDLLName(ACHAR("NgAnsoftCOMApp"));
  ANSOFTHINSTANCE ngAppDLL = ::AnstLoadDll(dllName);
  if (!ngAppDLL)
  {
    ::AnsDebug(ACHAR("NgAnsoftCOMAppDLLInterface"), 1, ACHAR("Error occurred in LoadNgAnsoftCOMAppDLL: Load of '%s' failed!\n"),
      dllName.c_str());

    IMessageManager* msgMgr = ::GetGlobalIDesktop()->GetIMessageManager();
    AnsoftMessage am;
    AString msgStr;
    msgStr.Format(ACHAR("Load of '%s' failed\n"), dllName.c_str());
    am.SetMessageText(msgStr);
    msgMgr->AddAnsoftMessage(am);
    return false;
  }
  gNgAnsoftCOMAppDLLHandle = ngAppDLL;
  return true;
}

static void UnloadNgAnsoftCOMAppDLL()
{
  if (gNgAnsoftCOMAppDLLHandle)
    AnstCloseDll(gNgAnsoftCOMAppDLLHandle);
  gNgAnsoftCOMAppDLLHandle = 0;
}

bool NgAnsoftCOMAppDLLInterface::InitializeNgAnsoftCOMAppDLL() 
{
  if (gNgAnsoftCOMAppDLLHandle)
    return true;

  if (LoadNgAnsoftCOMAppDLL() == false)
    return false;
  SS_ASSERT(gNgAnsoftCOMAppDLLHandle);

  // YYY: Make sure ansoft-messages added in ngansoftcomapp go to the desktop's message mananger
  // instead of getting lost in some local message manager
  typedef bool (*InitialiazeNgAnsoftCOMAppFuncPtr)();
  InitialiazeNgAnsoftCOMAppFuncPtr initNgAppFunc = 0;
  GetNgAnsoftCOMAppProcAddr(initNgAppFunc, ACHAR("InitialiazeNgAnsoftCOMAppForDesktopClient"));
  if (!initNgAppFunc)
  {
    SS_ASSERT(!ACHAR("NULL InitialiazeNgAnsoftCOMAppForDesktopClient function!"));
    return false;
  }
  bool proxyInit = initNgAppFunc();
  SS_ASSERT(proxyInit == true);

  return proxyInit;
}

bool NgAnsoftCOMAppDLLInterface::ReleaseNgAnsoftCOMAppDLL() 
{
  UnloadNgAnsoftCOMAppDLL();
  return true;
}

IDesktopJobSimulationManager* NgAnsoftCOMAppDLLInterface::CreateDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms)
{
  bool bRet = NgAnsoftCOMAppDLLInterface::InitializeNgAnsoftCOMAppDLL();
  SS_ASSERT(bRet == true);

  typedef IDesktopJobSimulationManager* (*CreateDesktopJobSimulationManagerFuncPtr)(const PrepareForLargeScaleDSOParams& prms);
  CreateDesktopJobSimulationManagerFuncPtr createSimMgrFunc = 0;
  GetNgAnsoftCOMAppProcAddr(createSimMgrFunc, ACHAR("CreateDesktopJobSimulationManager"));
  if (!createSimMgrFunc)
  {
    SS_ASSERT(!ACHAR("NULL CreateDesktopJobSimulationManager function!"));
    return 0;
  }
  return createSimMgrFunc(prms);
}

void NgAnsoftCOMAppDLLInterface::ReleaseDesktopJobSimulationManager(IDesktopJobSimulationManager* simMgr)
{
  // If needed, invoke ngansoftcom dll to do the release. For now, a simple delete should be fine even
  // if this is not symmetric with respect to create function
  delete simMgr;
}

// !!!! NgAnsoftCOMAppDLLInterface END !!!!!!!
