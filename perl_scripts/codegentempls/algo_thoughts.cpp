
// NgAppJobStatus -> 
// NgAppEngineRunProfile -> Number of task units, NgAppTaskProfile per task 
// NgAppTaskProfile -> start/end time, info/warning/error messages
class NgAppEngineRunProfile
{
public:

  enum EngineRunStatus {kRunningStatus, kDoneStatus, kHungStatus, kUnknownStatus};
  int GetNumTaskUnitsToComplete() const;
  int GetCompletedTasks() const;
  void GetTaskProfile(NgAppTaskProfile& taskProfile, int taskIndex) const;
  EngineRunStatus GetEngineRunStatus() const;

};

// NgApp runs engines through this class
class NgAppAnalysisProxy
{
  int RunEngine(...);
  void GetEngineRunProfile(NgAppEngineRunProfile& engineProfile);
};

// Has all parameters needed by the engine-run
class NgAppAnalysisParameters
{
};

// Product dll implements below interface
INgAppEngineRun* CreateEngineRun(const 
class INgAppEngineRun
{
  virtual void GetEngineRunProfile(NgAppEngineRunProfile& prof) = 0;
}


// Algorithm: check if a solve is hanging
// NgAppEngineManager
// Returns status as: runstatus -> running, completed, hung; statusofcompletedtasks-> errors exist
void NgAppAnalysisProxy::GetEngineRunProfile(NgAppEngineRunProfile& engineProfile, int runID)
{
  m_productDLLInterface->GetEngineRunProfile(engineProfile);
}

int NgAppApplication::RunSupportingCommand()
{
  //


// Algorithm: extract results after every variation solve is done

// Note: if you make it inline, there will be adverse sideffects
#define CharPtr(astr) astr.ASCII().c_str()

bool NgAnsoftCOMApplication::ClientAppMainFunction(int argc, char** argv) 
{
  // YYY: include NgAnsoftCOMApplicationDefs.h
  // REVISIT: move custom options to desktopjob
  namespace po = boost::program_options;
  po::options_description generalOptions("General options");
  generalOptions.add_options()
    ("help", "list the available command-line options")
    (CharPtr(kMonitorOptionName)",mon", po::value<string>()->zero_tokens(), "Monitor the job using it's standard output. "
     "You can pipe the standard output and standard error streams to files located on a network drive.")
    (CharPtr(kLogFileOptionName)",log", po::value<string>(), "Specify the file to log the analysis progress and status")
    (CharPtr(kBatchOptionsOptionName)",bo", po::value<string>(), "Specify options to configure this analysis. Any option "
     "available in Tools/Options can be configured: multi-processing, temp directory, "
     "library location, license options, etc.")
    (CharPtr(kEnvOptionName), po::value<std::vector<std::string> >()->multitoken(), "Specify any number of environment "
     "variable values in 'name=value' format")
    // Any program requires an input file and so having below in base class makes sense
    (CharPtr(kProjectOptionName), po::value<string>(), "Specify path to the input file")
    ;

  po::options_description hiddenOptions("Hidden options");
  hiddenOptions.add_options()
    (CharPtr(kProjectOptionName), po::po::value< vector<string> >(), "Specify path to the input file")
    ;

  po::options_description configOptions("Configuration options");
  configOptions.add_options()
    (CharPtr(kProductNameOptionName), po::value<string>(), "Name should match the folder name that contains this "
     "product's registry files. E.g. Maxwell")
    (CharPtr(kProductVersionOptionName), po::value<string>(), "Version should match the folder name that contains "
     "this product's registry files. E.g. 14.0")
    (CharPtr(kBatchOptionsOptionName), po::value<string>(), "Specify options to configure this analysis. Any option "
     "available in Tools/Options can be configured: "
     "multi-processing, temp directory, library location, license options, etc.")
     ;

  po::positional_options_description pOpts;
  pOpts.add(CharPtr(kProjectOptionName), -1);

  GetCommandLineOptionsSpec(generalOptions, hiddenOptions, configOptions, pOpts);

  po::options_description cmdline_options;
  cmdline_options.add(generalOptions).add(customOptions).add(hiddenOptions);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
	    options(cmdline_options).positional(p).run(), vm);

  // Now check for options specified in the config file. For e.g. desktopjob.cfg
  //
  // Format of cfg file:
  // BEGIN FILE (note: these BEGIN/END delimiters shouldn't be in the file)
  //
  // #
  // # Comment out this line to use hard-coded default value of 10
  // # 
  // optimization = 1
  // include-path = /opt
  //
  // END FILE

  // YYY need to include below
  //#include <iostream>
  //#include <fstream>
  //#include <iterator>

  LongFileName cfgFile(m_appStartupParams.GetAppDir(), m_appStartupParams.GetAppNameNoExtn(), ACHAR("cfg"));
  AString cfgPath = cfgFile.FilePath();
  po::options_description config_file_options;
  config_file_options.add(config).add(hidden);
  std::ifstream ifs(CharPtr(cfgPath));
  po::store(po::parse_config_file(ifs, config_file_options), vm);
  po::notify(vm);

  // Copy command-line parameters to named-values
  bool errorOccurred = false;
  std::map<std::string, po::variable_value>::iterator vmiter;
  for (vmiter = vm.begin(); vmiter != vm.end(); ++vmiter) 
  {
    const std::string& vname = vmiter->first;
    const po::variable_value& vval = vmiter->second;
    if (vval.defaulted())
      continue;
    // YYY AnsoftTypeInfo, ngcore/ngutils/AnsoftTypeInfo.h
    AnsoftTypeInfo atypInf(vval.any.type());
    if (atypInf == std::typeid(std::string))
    {
      std::string sv;
      vval.as<std::string>(sv);
      // No need to set value as it is same as default value
      m_commandLineParams.InitializeObjectPropertiesSchema(AString(vname.c_str), AString(sv.c_str()));
    }
    else if (atypInf == std::typeid(int))
    {
      int iv = 0;
      vval.as<int>(iv);
      m_commandLineParams.InitializeObjectPropertiesSchema(AString(vname.c_str), iv);
    }
    else if (atypInf == std::typeid(std::vector<std::string> >))
    {
      std::vector<std::string> vsv;
      vval.as<std::vector<std::string> >(vsv);
      std::vector<AString> astrVec;
      for (std::vector<std::string>::iterator sviter = vsv.begin(); sviter != vsv.end(); ++vsv)
	astrVec.push_back(sviter->c_str());
      m_commandLineParams.InitializeObjectPropertiesSchema(AString(vname.c_str), astrVec);
    }
    else 
    {
      SS_ASSERT(0);
      errorOccurred = true;
    }

  return errorOccurred;
}

 namespace po = boost::program_options;
 void DesktopJobApplication::GetCommandLineOptionsSpec(po::options_description& generalOptions, 
						       po::options_description& hiddenOpts,
						       po::options_description& configOptions,
						       po::positional_options_description& pOpts) const
{

  generalOptions.add_options()
    (CharPtr(kDistributedOptionName)",distrib", po::value<string>(), "Perform dso using the machines assigned to the job. If this is a "
     "scheduler job, machine list "
     "is obtained directly from scheduler. For non-scheduler jobs, machine list is specified "
     "as \"list='m1,m2,m3'\" or as \"file='filepath'\"")
    (CharPtr(kNgOptionName), po::value<string>()->zero_tokens(), "Run the job in non-graphical mode")
    (CharPtr(kWaitForLicenseOptionName), po::value<string>()->zero_tokens(), "With this option, job will not fail if licenses are not "
     "available. Job will be queued until the availability of licenses.")
    (CharPtr(kMPOptionName), po::value<int>()->default_value(1), "Specify the multi-processing value as number of cores reserved "
     "for multi-processing. The cores available to the job are shared between distributed engines and "
     "multi-processing within each engine. The number of DSO engines x MP should be equal or less than the "
     "number of cores available to the job")
    (CharPtr(kJobCoresOptionName), po::value<int>()->default_value(0), "Specify the number of cores assigned to the job. The number "
     "of cores available to the engines is reduced by the same amount.")
    (CharPtr(kBatchSolveOptionName)",bs", po::value<string>(), 
     "Run batchsolve of given parametric setup. Name of the setup is specified as "
     "<design>:Optimetrics:<parametric_setup_name>")
    (CharPtr(kPreserveSolverFilesOptionName)",psf", po::value<string>()->zero_tokens(), 
     "Preserve distributed database at the end of the job for the purpose of deep investigation into the completed or failed "
     "analysis")
    (CharPtr(kAbortOptionName), po::value<string>()->zero_tokens(), 
     "Abort a running job specified using the path to the analyzed project")
    ;

  hiddenOptions.add_options()
    (CharPtr(kProjectOptionName), po::value< vector<string> >(), "Specify path to the input file")
    ;
  configOptions.add_options()
    (CharPtr(kWaitForLicenseOptionName), po::value<string>()->zero_tokens(), "With this option, job will not fail if licenses are not "
     "available. Job will be queued until the availability of licenses.")
    (CharPtr(kJobCoresOptionName), po::value<int>()->default_value(0), "Specify the number of cores assigned to the job. "
     "The number of cores available to the engines is reduced by the same amount.")
     ;

}

// Allows adapting all kinds of datastructures to below format
class NgAppGenericData
{

public:

  NgAppGenericDataBuffer();

  NgAppAddGeneGenericDataBuffer(const AnsoftMessage& msg);
  NgAppGenericDataBuffer(const AString& ansMessage, MessageSeverity severity);
  NgAppGenericDataBuffer(const AnsoftMessagesForWB& msgs);
  NgAppGenericDataBuffer(const ProgressMessageDef& obj);
  NgAppGenericDataBuffer(const NgAppAnsoftCommand& obj);
  NgAppGenericDataBuffer(const NgAppAnsoftCommandResultFile& obj);

  // Retrieve data as a generic string
  AString GetDataAsAString() const;
  // Retrieve data in the format it was pushed 
  // Returns true if the requested type is the same type that was pushed in
  template <class DataType>
  bool GetDataAs(DataType& buf) const;

  // 
  io::ReadError Write(io::CBlock& blk) const;
  io::ReadError Read(const io::CBlock& blk);

private:
  // Used named props. Name represents the type of data
};

// Queue of AnsoftMessages. Provides synchronized access across threads
// Main thread message manager is the message target for message managers of
// other threads
class NgAppGenericDataVector
{

public:

  NgAppGenericDataVector();

  void AddGenericData(const AnsoftMessage& msg);
  void AddGenericData(const AString& strBuf, MessageSeverity severity);
  void AddGenericData(const io::CBlock& blk);

  void ClearAllData();
  size_t GetNumDataItems() const;

  // copies generic data from 'fromVec'. Clears all data from 'fromVec'
  void CopyFrom(const NgAppGenericDataVector& fromVec);

  // 
  io::ReadError Write(io::CBlock& blk) const;
  // To restore persisted data as streamio_block_object, factory is needed.
  // If factory is not supplied, the persisted streamio data will be restored as a CBlock
  io::ReadError Read(const io::CBlock& blk, IBlockObjectFactory* factory = 0);

private:

  std::vector<NgAppGenericDataBuffer> m_dataQueue;

};

class INgAppResultsMessageManager
{
  AddResultFile;
};
// Global
INgAppResultsMessageManager* GetINgAppResultsMessageManager();

class INgAppCommandMessageManager
{
  AddCommandMessage; // command also come in as messages
};
// Globals
INgAppCommandMessageManager* GetINgAppCommandMessageManager();

class INgAppMessageManager : public IMessageManager
{
  // Allow additional message formats as below
  Add(const AnsoftMessagesForWB& msgs);
  Add(const ProgressMessageDef& obj);
};

// YYYY: what is the diff betn various msg mgrs and where do below proxy/stub fit in
class NgAppMessageManager : public INgAppMessageManager, public IMessageHandler, 
  public INgAppResultsMessageManager, public INgAppCommandMessageManager
{
  static bool InitializeMessageManagerForThisThread(NgAppMessageManager*);
  static bool DestroyMessageManagerForThisThread();

  NgAppGenericDataVector m_msgQueue;
};

// Below is used to keep around all various data types apart from AnsoftMessages
class NgAppMainThreadMessageManager : NgAppMessageManager
{

public:

  NgAppMainThreadMessageManager(const AString& logFile);

  // Provide a throttle mechanism on *service* side.
  // All messages will be throttled. If client needs to send a message, they must
  // explicitly invoke message handler as/when needed. 
  // When comand is done, all msgs flushed
  // Throttle mechanism: handle messages every time-period (in seconds)
  // Default time period (in seconds) computed as: Total work units/number of units assigned to command
  // The messages are also staggered. Message time period starts from: start work unit
  // At different distribution levels this is a different value
  // Handling: flush accumulated messages to NFS log file. 
  // Create a standard message-manager message. Invoke commandcallback->OnNgAppCommandMessage
private:
  // Stub has the unprocessed messages coming from other threads
  NgAppAnsoftCOMMessageTargetStub<NgAppMainThreadMessageManager>;
  LogFilePath;

};
  
class NgAppThreadMessageManager : NgAppMessageManager
{
public:
  class MessageBufferContext {DiscardAccumulatedBuffer(); /* default behavior*/ HandleAccumulatedBuffer();};
  NgAppThreadMessageManager(NgAppAnsoftCOMMessageTargetProxy<NgAppMainThreadMessageManager>* msgMgr);

private:
  NgAppAnsoftCOMMessageTargetProxy* p;
};

bool NgAppThreadMessageManager::HandleMessages(const AnsoftCommandContext* context) 
{
  m_mainThreadMsgMgr->SignalMessageToTarget;
}


// Note: this won't be executed in the case of desktopjob as the job will set the msgmgr pointer itself!!
IMessageManager* ThreadMessageManager::GetMessageManager()
{
  // To allow clients to Access per-thread specific storage, use below implementation lines
  ThreadMessageManager *threadMsgMgr = reinterpret_cast<ThreadMessageManager*>(pthread_getspecific(gThreadSpecificKey));
  if(threadMsgMgr)
    return threadMsgMgr;

  SS_ASSERT(!threadMsgMgr);
  if (gInitLogFilePath.empty() == false) 
    threadMsgMgr = new ThreadMessageManager(gInitLogFilePath);
  else
    threadMsgMgr = new ThreadMessageManager;

  pthread_setspecific(gThreadSpecificKey, threadMsgMgr);
  return threadMsgMgr;
}



#include "ngcore/ipcutils/GeneralFunctions.h"

NgAppAnsoftCOMMessageTarget::NgAppAnsoftCOMMessageTarget()
: m_targetSignalingEvent(INVALID_HANDLE)
{
  // Create event that is in non-signalled state. And requires a manual_reset
  m_targetSignalingEvent = AnstCreateEvent(true, false);
}

class NgAppThreadMessageTargetProxy
{
  // Other threads signal using one of the below functions
  // Returns true when the target thread is waiting for signal.
  // False otherwise (e.g. target thread is busy)
  bool SignalMessageToTarget(const AString& msg);
  bool SignalMessageToTarget(const io::CBlock& blk);
  bool SignalMessageToTarget(const NgAppGenericDataVector& data);

private:

  ANSOFTHANDLE m_targetSignalingEvent;
  // INFO: Constructor of AnsoftMutex invokes pthread_mutex_init. Destructor pthread_mutex_destroy
  // Lock method locks using pthread_mutex_lock and also sets m_OwnerThread member to pthread_self
  AnsoftMutex m_mutexForMsgBuffer;
  NgAppGenericDataVector m_queuedMessages;

  bool m_IsWaitingState;

  NgAppAnsoftCOMMessageTargetStub* m_owner;

  friend class NgAppAnsoftCOMMessageTargetStub;
  
};

bool NgAppThreadMessageTargetProxy::SignalMessageToTarget(const AString& msg)
{
  // INFO: Constructor/Destructor of context object lock/unlock mutex.
  // When "allowRecursive" is true (typically the case), the same thread
  // the usage of second/third/all-subsequent-to-first AnsoftMutexContext are
  // affectively no-op. This way, pseudo-multi-threading becomes possible
  // When "allowRecursive" is false, there is a risk of deadlock
  if (!m_IsWaitingState)
  {
    // When will such a case happen?
    // - Abort command coming through while the main thread is processing algorithm
    // - New service request coming while in the middle of processing a service request
    // So main thread's logic: wheneven it does a wait, it should first process 
    // already queued messages, rather than wait for a signal again
    AnsDebug("message is queued for later processing\n");
  }

  AnsoftMutextContext cntxt(m_mutexForMsgBuffer);
  m_queuedMessages.AddGenericData(msg);
  AnstSetSignal(m_targetSignalingEvent);
  return m_IsWaitingState;
}

NgAppAnsoftCOMMessageTarget::~NgAppAnsoftCOMMessageTarget()
{
  // Close the handle to the events
  AnstCloseHandle(m_targetSignalingEvent);
  m_targetSignalingEvent = INVALID_HANDLE;
}

// Runs on main thread. So it is important that the pointer to below object is protected
// so multiple threads won't end up calling any function
bool NgAppAnsoftCOMMessageTarget::MessageTargetWaitOnEvent(IMessageTargetSignalHandler* msgTargetHndlr)
{
  CLoggingHelper logHelp(ACHAR("NgAppAnsoftCOMMessageTarget::MessageTargetWaitOnEvent"));

  int numSignalsToTarget = 0;
  while (1)
  {
    SS_ASSERT(m_targetSignalingEvent != INVALID_HANDLE);
    // Wait until target is signalled
    int waitStatus = AnstWaitForSingleObject(m_targetSignalingEvent, ANST_INFINITE);
    SS_ASSERT(waitStatus != ANST_WAIT_FAILED);
    if (waitStatus == ANST_WAIT_FAILED)
    {
      AString msgstr;
      msgstr.Format(ACHAR("Failure in multi-threaded communication. Waiting on an event failed. Waitstatus is %d\n"), waitStatus);

      AnsoftMessage am;
      am.SetMessageText(msgstr);
      am.ChangeSeverity(kErrorMessage);
      IMessageManager* msgMgr = ::GetMessageManager();
      msgMgr->AddAnsoftMessage(am);
      return false;
    }
    numSignalsToTarget++;
    SS_ASSERT(waitStatus == ANST_WAIT_OBJECT_0);
    bool continueToWait = msgTargetHndlr->OnTargetSignalled(this);
    if (continueToWait == false)
    {
      ::AnsDebug(ACHAR("NgAppAnsoftCOMMessageTarget"), 1, ACHAR("Target '%s' received %d signals so far. Continuing to wait...\n"));
      break;
    }
    ::AnsDebug(ACHAR("NgAppAnsoftCOMMessageTarget"), 1, ACHAR("Target '%s' received %d signals so far. Continuing to wait...\n"));

    // Once signalled, any waits will be unblocked until the event is 'reset' using below
    AnstResetEvent(m_targetSignalingEvent);
  }
  
  bool retValue = true;
  logHelp.LogParam(ACHAR("RetValue"), retValue);
  
  return retValue;
}

// Scenario supported: only one thread (main thread) waits. Any number of threads (that need to send messages to
// main thread) can signal. Owner should protect access to below object and provide access to only
// Signal functions to other threads
// The parent thread creates below object. Passes proxy pointer to children threads so they can send
// synchronized messages to parent
class NgAppThreadMessageTargetStub
{

public:

  // Main thread waits using below function
  void WaitOnMessagesFromOtherThreads(IMessageTargetSignalHandler* msgTargetHndlr);
  
private:

  NgAppThreadMessageTargetProxy m_msgRelayFromOtherThreads;
  
};
void NgAppThreadMessageTargetStub::WaitOnMessagesFromOtherThreads(IMessageTargetSignalHandler* msgTargetHndlr)
{
  // First check if messages already exist to be processed
  NgAppGenericDataVector queuedMessages;
  {
    // Use mutex in the smallest possible context
    AnsoftMutexContext cntxt(m_msgRelayFromOtherThreads.m_mutexForMsgBuffer);
    if (m_msgRelayFromOtherThreads.m_queuedMessages.GetNumDataItems())
      queuedMessages.CopyFrom(m_msgRelayFromOtherThreads.m_queuedMessages);
    m_msgRelayFromOtherThreads.m_queuedMessages.ClearAllData();
  }
  if (queuedMessages.GetNumDataItems())
  {
    bool ret = msgTargetHndlr->HandleSignalledMessages(queuedMessages);
    if (ret == false)
    {
      // dont wait any more
      return;
    }
  }

  AnstWaitOnEvent(); // see above for algorithm

}

ThreadMessageManager::AddAnsoftMessage(msg)
{
  // Default: no need to buffer. Main message manager buffers
  messageTarget->SignalMessage(msg);

  // If we need below and when we allow caching context
  AddToOwnBuffer; //Discard or flush at a later time

}

/*
 *
 * Use case: Client makes a service request
 *
 *
 */

/*
 *
 * Client-side handling
 *
 */
#include "wbintegutils/LoggingHelper.h"



// !!PURPOSE!!
// Below exception class is used for convenient error handling, rather than
// exceptional situations such as out-of-memory conditions.
// So use the class in such a context.
// For true exceptions such as resource exceptions, simpler classes are 
// better suited
// !Inefficient!
class AStringException : public std::exception
{
public:
  AStringException(const AString& msg)
    : m_asciiStr(msg.ASCII())
  {
  }
  AStringException(const AChar* format, ...)
  {
    AString astr;
    va_list args;
    va_start(args, format);
    astr.FormatV(format, args);
    va_end(args);
    m_asciiStr = astr.ASCII();
  }

  virtual const char* what() const {
    return m_asciiStr.Str();
  }
private:
  AString_const<char> m_asciiStr;
};

#include "ngcore/value/VariationKeyVariableServer.h"
#include "ngcore/value/VariableNameSpace.h"
#include "ngcore/value/VariableValues.h"
// 1. Variables are created using the first key
// 2. And then VariationKeyVariableServer is set to parse the remaining keys
bool ReadVariationIDMapFromHeaderBlock(const io::CBlock& headerBlock)
{
  VariationKeyVariableServer* m_variableServer = 0; // ZZZZ -> need to initialize. Also keep as member.

  VariableNameSpace vns;

  bool ret = true;
  try
  {
    io::CBlock vidBlock(ACHAR("VariationIDs"));
    headerBlock >> vidBlock;
    if(!headerBlock.Found()) throw AStringException("VariationIDs block is missing");

    io::CBlock::list_iterator vidIter = vidBlock.begin();
    for ( ; vidIter != vidBlock.end(); ++vidIter)
    {
      io::CBlock_func *func =
        dynamic_cast<io::CBlock_func*>(vidIter->Item());

      AString variationKey;
      (*func) >> io::NamedValue(ACHAR("V"), variationKey);
      if (!m_variableServer)
      {
        m_variableServer = new VariationKeyVariableServer(variationKey);
        vns.AddVariableServer(m_variableServer);
      }
      VariableValues vvals;
      if (!VariableValues::ResolveVariationKey(vvals, variationKey, vns))
        throw AStringException(FStr("Error occurred: Unable to resolve '%s' variationkey", variationKey.c_str()));

      id::BasicID vid = id::invalidID;
      (*func) >> io::NamedValue(ACHAR("ID"), vid);

      // ZZZ: keep this as a member
      std::vector<VariableValuesWithID> m_variationIDs;
      m_variationIDs.push_back(VariableValuesWithID(vvals, vid));
    }
  }
  catch(AStringException& msg)
  {
    // ZZZ Add error message
    ret = false; // 
  }
  return ret;
}
// SolutionKey(SimSetup=0, Instance=\'SetupDefinition\', Solution=-1, VersionID=281)
static bool ParseSolutionVariationKey(id::BasicID& simSetupID, AString& varKey, id::BasicID& solKey,
                                      id::BasicID& verKey, const AString& solVarKey)
{
  bool ret = true;
  try
  {
    // REVISIT: share these string literals with the appropriate code
    io::CBlock_func blkFunc(ACHAR("SolutionKey"));
    if (blkFunc.Unpack(solVarKey) == false) throw AStringException(FStr("Error occurred: Unpack of '%s' failed", solVarKey.c_str()));

    blkFunc >> io::NamedValue(ACHAR("SimSetup"), simSetupID);
    blkFunc >> io::NamedValue(ACHAR("Instance"), varKey);
    blkFunc >> io::NamedValue(ACHAR("Solution"), solKey);
    blkFunc >> io::NamedValue(ACHAR("VersionID"), verKey);

    if (!blkFunc.Found()) throw AStringException(FStr("Error occurred: Parse of '%s' failed", solVarKey.c_str()));
  
  }
  catch(AStringException& msg)
  {
    ret = false;
    // ZZZ
  }
  return ret;
}

// ZZZ: need implementation
class SolutionBlockDefinition
{
public:

  SolutionBlockDefinition(const AString& solBlkName, const AString& solVarKey);
  AString GetSolBlockName() const;
  id::BasicID GetSimSetupID() const;
  AString GetInstanceKey() const;
  id::BasicID GetSolutionID() const;
  id::BasicID GetVersionID() const;
};

// ZZZ
void GetAvailableSolutionBlocks(std::vector<SolutionBlockDefinition>& solBlks, 
                                const std::map<AString, AString>& asolNameMap)
{
  // Ignore simsetup blocks or handle such blocks downstream
}
#include "ngcore/streamio/block_item.h"

bool TestCustomReporterCmd::DoIt(void)
{

  try 
  {
    LongFileName asolLfn; // ZZZ initialize
    CStreamioLibWritePrivate asolLib(asolLfn);

    // CStreamioLibrary::LibIOReturn, CStreamioLibrary::kLibNoError
    io::CBlock blkMap(ACHAR("BlockMapName"));
    CStreamioLibrary::LibIOReturn retVal = asolLib.LoadDefinition(blkMap);
    if (retVal != CStreamioLibrary::kLibNoError) throw AStringException(FStr("Load of '%s' block failed",
      blkMap.Name().c_str()));

    std::map<AString, AString> asolNameMap;
    if (ReadNameMappingFromAsol(asolNameMap, blkMap) == false)
      throw AStringException("ReadNameMappingFromAsol failed");

    std::map<AString, AString>::iterator miter = asolNameMap.find(ACHAR("FileHeader"));
    SS_ASSERT (miter != asolNameMap.end());
    AString headerBlockName = miter->first;

    io::CBlock headerBlk(headerBlockName);
    CStreamioLibrary::LibIOReturn readHeaderErr = asolLib.LoadDefinition(headerBlk);
    if (readHeaderErr != CStreamioLibrary::kLibNoError) throw AStringException(FStr("Load of '%s' block failed",
      headerBlockName.c_str()));

    // REVISIT: handle locked projects, crashed projects with asol_priv or semaphore files, etc.
    // Header block has variation IDs
    // 
    // REVISIT: should we preserve the order of variations. In which case keep vars in vector ontainer
    // rather than in map
    ReadVariationIDMapFromHeaderBlock(headerBlk);

    // TODO: Find solution blocks from the header block
    std::vector<SolutionBlockDefinition> solBlks;
    GetAvailableSolutionBlocks(solBlks, asolNameMap); // ZZZ need to implement

    std::vector<SolutionBlockDefinition>::iterator solBlkIter;
    for (solBlkIter = solBlks.begin(); solBlkIter != solBlks.end(); ++solBlkIter)
    {
      SolutionBlockDefinition& solBlkDef = *solBlkIter;
      if (solBlkDef.GetSolutionID() < 0) // Not a solution block
        continue; 
      AString solBlkName = solBlkDef.GetSolBlockName();

      io::CBlock solBlk(solBlkName);
      CStreamioLibrary::LibIOReturn loadSolBlkErr = asolLib.LoadDefinition(solBlk);
      if (loadSolBlkErr != CStreamioLibrary::kLibNoError) throw AStringException(FStr("Load of '%s' block failed",
        solBlkName.c_str()));

      AString solnName;
      solBlk >> io::NamedValue(ACHAR("SolutionName"), solnName);
      // ZZZ add some andebug statements
      id::BasicID idFromBlock;
      solBlk >> io::NamedValue(ACHAR("SolutionID"), idFromBlock);
      if (solBlk.Found() == false) throw AStringException("Item not found in block");
      if (idFromBlock != solBlkDef.GetSolutionID())
        throw AStringException(FStr("Solution ID '%d' in the block doesn't match id '%d' from file header",
        idFromBlock, solBlkDef.GetSolutionID()));

      io::CBlock perDesignSubDataMgrBlock(ACHAR("PD"));
      solBlk >> perDesignSubDataMgrBlock;
      if (solBlk.Found() == false) throw AStringException(FStr("'PD' item is missing from '%s' solution block",
        solBlkName.c_str()));

      io::CBlock::list_iterator blkIter;
      for (blkIter = perDesignSubDataMgrBlock.begin(); blkIter != perDesignSubDataMgrBlock.end(); ++blkIter)
      {
        io::TBlockItemPtr& blkItemPtr = *blkIter;
        io::CBlock_item* blkItem = blkItemPtr.Item();
        SS_ASSERT(blkItem);
        io::CBlock* subDataBlkPtr = dynamic_cast<io::CBlock*>(blkItem);
        if (!subDataBlkPtr)
        {
          ::AnsDebug(ACHAR("ZZZ"), 1, ACHAR("Skipping past item '%s' in solution block.\n"), blkItem->Name().c_str());
          continue;
        }
        ::AnsDebug(ACHAR("ZZZ"), 1, ACHAR("Found subdata '%s' in solution block.\n"), subDataBlkPtr->Name().c_str());

        io::CBlock& subDataBlk = *subDataBlkPtr;

        id::BasicID subDataID = id::invalidID;
        subDataBlk >> io::NamedValue(ACHAR("ID"), subDataID);
        if (subDataBlk.Found() == false)
          throw AStringException(FStr("'ID' item is missing from '%s' subdata block", subDataBlk.Name().c_str()));

        // TODO: Now read the files!
      } // for each subdata
    } // for each solution
  } 
  catch(AStringException& errMsg) 
  {
    //ZZZ: add a good error message here when asol load fails
  }
}

// Implement abort, etc. standard commands
int NgAppStandardCommandsProvider::RunNgAppCommand(INgAppCommandCallback* icmdCB)
{
  // YYY
}

#include "Level2CommandAtUniqueNodeActivationTopology.h"

int NgAppAnsoftCOMApplication::RunNgAppCommand()
{
  m_appState = kNgAppRunningCommand;

  // REVISIT: support activation-topology to come from ccommand-line. For now, just support two-level
  Level2CommandAtUniqueNodeActivationTopology cmdActivationTopo;
  const NgAppCommandDef& cmdDef = m_ngAppCommand.GetNgAppCommandDef();
  if (cmdActivationTopo.IsChildCommandNeededAtThisLevel(cmdDef) == true)
  {
    INgAppDistributedServiceProxy* distributedCommService = m_ngAppCommand.CreateNgAppDistributedCommService();
    SS_ASSERT(distributedCommService);
    if (!distributedCommService)
    {
      return ngapp::ErrorMessage(ngapp::kNgAppFailed, 
             "DSO command failed to obtain distributed communication services for dso nodes: '%s'",
             ngapp::VecStr(uniqueMachines));
    }
    std::vector<AString> uniqueMachines;
    cmdDef.GetUniqueDistributionMachineList(uniqueMachines);

    // Send same command to the nodes but each node doing a portion.
    // The only difference between individual portions: rank (borrowing MPI terminology), 
    // which determines the portion that piece will tackle
    ngapp::InfoMessage("Splitting DSO job into independent child DSO jobs on nodes: '%s'...", ngapp::VecStr(uniqueMachines));
    int retVal = distributedCommService->DistributeNgAppCommandToAvailResources(*cmdActivationTopo);
    ngapp::InfoMessage("Child DSO analysis is done.");
    distributedCommService->OnDoneUsingService();
    return retVal;
  }

  // REVISIT HACK: Below code assumes level2activation topology.
  // Instead of such hardcoding, switch to a virtual method that enables staggerring at
  // any level
  if (cmdDef.GetDistributionLevelProp() == NgAppCommandDef::kDistributionLevel2)
  {
    // In the current code, the desktopjobs correponding to leaf nodes all
    // run tasks at the same time, effectively ganging up on the OS.
    // Ensure a gradual ramp up of load on OS for a reliable run.
    // Each of the leaf jobs sleeps for an amount of time based on
    // their rank. The largest rank job sleeps for the longest time
    int sleepAmountInSecs = cmdDef.GetSiblingRankProp() + 1;
    ngapp::InfoMessage("Leaf command is entering a wait state of '%d' seconds...", sleepAmountInSecs);
    ANSOFT_SLEEP(sleepAmountInSecs*1000); // provide value in milliseconds
    ngapp::InfoMessage("Done with the waiting period.");
  }

  SS_ASSERT(m_cmdProvider);
  int iRet = m_cmdProvider->RunNgAppCommand(&m_ngAppCommand);

  return iRet;
}

int NgAppDistributedCommMgr::DistributeNgAppCommandToAvailResources(const NgAppCommandActivationTopology& cmdActivationTopo)
{
  CLoggingHelper logHelp(ACHAR("NgAppDistributedCommMgr::DistributeNgAppCommandToAvailResources"));
  
  const NgAppAnsoftCommand& cmd = m_ownerApp->GetCurrentRunningCommand();
  const NgAppCommandDef& parentCmdDef = cmd.GetNgAppCommandDef();

  std::vector<AString> childCmdMachines;
  std::vector<int> childCmdMachineCores;
  int totResourceUnitsAvail = parentCmdDef.GetTotalWorkUnitsForOverallCommandProp();
  // First find the machines available
  DistributedMachineTreeTwoLevel distribListTwoLvl;
  cmdActivationTopo.GetDistributedMachineListForChildActivation(distribListTwoLvl, parentCmdDef);

  {
    distribListTwoLvl.GetFlatMachineListForImmediateChildren(childCmdMachines, childCmdMachineCores);

    if (m_NgAppServiceConnections.empty() == false)
      return ngapp::ErrorMessage(ngapp::kNgAppFailed, "Fatal error occurred: Cannot handle nested service calls!");

    int reducedAmtOfResourceUnits = ActivateChildJobOnResourceUnits(childCmdMachines, childCmdMachineCores, 
      parentCmdMachines, parentCmdMachineCores);
    totResourceUnitsAvail -= reducedAmtOfResourceUnits;
    ngapp::InfoMessage("Total resource unts available for the overall job is '%d'", totResourceUnitsAvail);
  }

  int childDistributionLevel = parentCmdDef.GetDistributionLevelProp() + 1;
  AString firstSiblingFolder;
  AString parentWorkDir = cmd.GetNgAppProgramGeneralOptions().GetWorkDirProp();
  firstSiblingFolder = NgAppCommandDef::GetChildWorkDir(parentWorkDir, 0);
  bool isOverallFirst = parentCmdDef.GetIsOverallFirstTaskProp();

  int currWorkUnit = parentCmdDef.GetStartUnitProp();
  // !NOTE! childCmdsVec is used way below in this method. So ensure it's not deleted while in use
  std::vector<NgAppCommandDef*> childCmdsVec;
  DeleteVectorElementsContext<NgAppCommandDef> delVElemContext(childCmdsVec);

  int numSiblings = static_cast<int>(m_NgAppServiceConnections.size());
  logHelp.LogParam(ACHAR("numSiblings"), numSiblings);
  for(int ii = 0; ii < numSiblings; ++ii)
  {
    NgAppProgramOptions progOptions(cmd.GetNgAppProgramGeneralOptions());
    NgAppCommandDef* cmdDefPtr = new NgAppCommandDef(cmd.GetNgAppCommandDef());
    NgAppCommandDef& cmdDef = *cmdDefPtr;

    // Keep all values same as parent except for below overrides

    ngapp::InfoMessage("Starting child job on machine '%s'...", childCmdMachines[ii]);
    // Child cmd is updated with new vals for: working directory, sibling count, rank, distributed machines/cores,
    // distribution level, work unit assignment, tot units available

    // total-resource-units, start, end units is always in tems of cores
    cmdDef.SetTotalWorkUnitsPropVal(totResourceUnitsAvail);
    cmdDef.SetDistributionLevelPropVal(childDistributionLevel);
    cmdDef.SetSiblingCountPropVal(numSiblings);
    cmdDef.SetFirstSiblingFolderPropVal(firstSiblingFolder);
    cmdDef.SetSiblingRankPropVal(ii);

    // The first child of an overall-first becomes overall-first (at it's distrib level)
    bool isOverallFirstTask = (ii == 00 && isOverallFirst);
    cmdDef.SetIsOverallFirstTaskPropVal(isOverallFirstTask);

    // Dont use workdir from progoptions as it is being changed in this loop!
    AString childWorkDir = NgAppCommandDef::GetChildWorkDir(parentWorkDir, ii);
    logHelp.LogParam(ACHAR("childWorkDir"), childWorkDir);
    progOptions.SetWorkDirPropVal(childWorkDir);

    std::vector<AString> grandChildNodeNamesVec;
    std::vector<int> grandChildCoresVec;
    distribListTwoLvl.GetFlatMachineListForGrandChildren(grandChildNodeNamesVec, grandChildCoresVec, ii);
    cmdDef.SetDistributionMachineList(grandChildCoresVec, grandChildNodeNamesVec);

    int startUnit = currWorkUnit;
    cmdDef.SetStartUnitPropVal(startUnit);
    SS_ASSERT(macNumCores >= 1);
    int endUnit = startUnit + macNumCores;
    // Note: end work unit is NOT done by this child command
    cmdDef.SetEndUnitPropVal(endUnit);

    AString childCmdChangesStr;
    childCmdChangesStr.Format(ACHAR("DistribLevel=%d, NumSibilings=%d, WorkDir=%s, Machine=%s, NumCores=%d, WorkUnits=(%d,%d), IsOverallFirstTask=%d, firstSiblingFolder=%s\n"),
      childDistributionLevel, numSiblings, childWorkDir.c_str(), macName.c_str(), macNumCores, startUnit, endUnit, isOverallFirstTask, firstSiblingFolder.c_str());
    logHelp.LogString(childCmdChangesStr);
    // debug logging is ON, add more logging info to batchlog file
    if(my_ans_debug_data.Debug(1) == true)
      ngapp::InfoMessage("Command definition for child '%d': '%s'", ii, childCmdChangesStr);

    INgAppServiceInterface* ingServ = m_NgAppServiceConnections[ii].m_iNgAppService;
    SS_ASSERT(ingServ);

    NgAppServiceCommandlineParameters serviceCmdParams(cmdDef, cmd.GetNgAppCommandParameters(),
                                                       progOptions);
    io::CBlock servCmdBlk(serviceCmdParams.GetItemName());
    bool succ = serviceCmdParams.Write(servCmdBlk); SS_ASSERT(succ);
    // Below is a non-blocking call so we can move onto next node quickly
    ingServ->RunNgAppServiceRequest(servCmdBlk);

    ngapp::InfoMessage("Done with starting child job.");
    childCmdsVec.push_back(cmdDefPtr);

    currWorkUnit += macNumCores;
  }

  ngapp::InfoMessage("Done with launching of jobs on level '%d'.", childDistributionLevel);

  // Now process events until children are done
  ngapp::InfoMessage("Waiting for the jobs, numbered '%d', to complete...", numSiblings);
  
  // !!!NOTE!!!
  //CoCreate starts service using a non-blocking Run call. Below should process events
  // until all distributed cocreated services are done!
  int numRunningServices = childCmdsVec.size();
  bool ret = this->ProcessCommunicationMessages(&numRunningServices);

  ngapp::InfoMessage("Jobs completed with status '%s'.", (ret == true) ? "success" : "failed");

  return (ret == false) ? ngapp::kNgAppFailed : ngapp::kNgAppSuccess;
}

int TwoLevelDistributedMachineList::GetMachinesForImmediateChildren(std::vector<AString>& macNamesVec, std::vector<int> vecMacCores) const
{
}

int NgAppRoot2Node2AllActivationScheme::GetDistributedMachineListForChildActivation(TwoLevelDistributedMachineList& childMacList, 
                                                                                    const NgAppCommandDef& parentCmdDef)
{
  std::vector<AString> parentCmdMachines;
  std::vector<int> parentCmdMachineCores;
  parentCmdDef.GetUniqueDistributionMachineList(parentCmdMachines);
  parentCmdDef.GetUniqueMachineCores(parentCmdMachineCores);
  if (parentCmdMachines.empty() || parentCmdMachineCores.empty() ||
    parentCmdMachines.size() != parentCmdMachineCores.size())
    return ngapp::ErrorMessage(ngapp::kNgAppFailed, "Error occurred during job distribution: no consumable resources are available!");

  // For a job at 2nd distribution level, only 1 node is available (in the current dso scheme)
  if (parentCmdDef.GetDistributionLevelProp() == NgAppCommandDef::kDistributionLevel1)
  {
    SS_ASSERT(static_cast<int>(parentCmdMachines.size()) == 1);

    int numSiblings = parentCmdMachineCores[0];
    parentCmdMachines.resize(numSiblings);
    parentCmdMachines.assign(numSiblings, parentCmdMachines[0]);
    parentCmdMachineCores.resize(numSiblings);
    parentCmdMachineCores.assign(numSiblings, 1);

    ngapp::InfoMessage("Activating single core jobs on node '%s'...", parentCmdMachines[0]);
  }
  else
  {
    SS_ASSERT(parentCmdDef.GetDistributionLevelProp() == NgAppCommandDef::kDistributionLevel0);
    ngapp::InfoMessage("Activating cross-node jobs using nodes '%s'...", ngapp::VecStr(parentCmdMachines));
  }
  return ngapp::kNgAppSuccess;
}


bool NgAppAnsoftCOMApplication::ClientAppMainFunction(NgAppCommandDef& cmdDef, io::CBlock& cmdParamsBlock)
{
  CLoggingHelper logHelp(ACHAR("NgAppAnsoftCOMApplication::ClientAppMainFunction"));

  // Set some default values
  m_generalOptions.SetProdNamePropVal(ACHAR("Maxwell"));
  m_generalOptions.SetProdExePropVal(ACHAR("maxwell.exe"));
  m_generalOptions.SetProdVersionPropVal(ACHAR("14.0"));

  // Filter the first argv
  std::vector<AString> inputCmdVec;
  for (int clo = 1; clo < m_argc; ++clo)
    inputCmdVec.push_back(m_argv[clo]);

  std::vector<AString> remainingCmdVec;
  // REVISIT below const_cast
  if (m_generalOptions.SetPropertyValuesFromCommandLine(remainingCmdVec, inputCmdVec) == false)
  {
    ngapp::ErrorMessage(ngapp::kNgAppFailed, "Error encountered during parsing!");
    return false;
  }

  AString cmdName = m_generalOptions.GetCommandNameProp(); 
  m_cmdProvider = m_cmdProviderFilter->GetProviderForCommand(cmdName);
  SS_ASSERT(m_cmdProvider);
  if (!m_cmdProvider)
  {
    ngapp::ErrorMessage(kNgAppFailed, "There is no implementation provided for command \'%s\'", cmdName);
    return false;
  }

  // Command provider parses the rest
  INgAppGeneralOptionSetter* iOptionSetter = &m_generalOptions;
  std::vector<AString> unparsedCmdVec;
  // REVISIT: remove general options from argc, argv before passing them down
  int retVal = m_cmdProvider->ParseCommandLineOptions(cmdParamsBlock, iOptionSetter, cmdName, unparsedCmdVec,
    remainingCmdVec, m_generalOptions);
  if (unparsedCmdVec.empty() == false)
  {
    ngapp::ErrorMessage(retVal, "Error occurred during parsing of command \'%s\': '%s' options are unrecognized", cmdName, 
      ngapp::VecStr(unparsedCmdVec));
    return false;
  }
  if (retVal)
    return false; // Assuming that the error is already added by the downstream code

  //
  // !!!Rank and distribution level!!!
  //
  cmdDef.SetNamePropVal(cmdName);
  cmdDef.SetDistributionLevelPropVal(NgAppCommandDef::kDistributionLevel0);
  cmdDef.SetSiblingCountPropVal(1);
  cmdDef.SetSiblingRankPropVal(0);
  cmdDef.SetIsOverallFirstTaskPropVal(true); // this is false for most children commands

  //
  // !!!Job resources and work units!!!
  //
  std::vector<AString> machines;
  std::vector<int> coresOfUniqueNodes;
  std::vector<AString> uniqueNodeList;
  AString cmdLineMachineListStr = m_generalOptions.GetDistribMachinesProp();

  ngapp::GetDistributedMachineListFromSchedulerORCommandLine(coresOfUniqueNodes, uniqueNodeList, machines,
    cmdLineMachineListStr);

  size_t numDistribMachines = machines.size();
  if (numDistribMachines <= 1)
  {
    ngapp::ErrorMessage(ngapp::kNgAppFailed, "Error occurred during parsing of job resources: The number of distributed machines, "
      "available for the job, must be greater than 1. The only command supported through desktopjob is 'dso'");
    return false;
  }

  logHelp.LogParam(ACHAR("MachineListFromSchedulerORCmdLine"), machines);
  AString machineStr = ngapp::VecStr(machines);
  // REVISIT Why is below needed? If user specified the machine-list, it's already in the progoptions
  // m_generalOptions.SetDistribMachinesPropVal(machineStr);
  InfoMessage("Using the machine list: '%s'", machineStr);

  cmdDef.SetDistributionMachineList(coresOfUniqueNodes, uniqueNodeList, machines);

  cmdDef.SetTotalWorkUnitsPropVal(numDistribMachines);
  cmdDef.SetStartUnitPropVal(0);
  cmdDef.SetEndUnitPropVal(numDistribMachines);

  //
  // !!!Job ID, working directory!!!
  //
  // At this stage, workdir property value is available from the project-path.
  // Now update working dir to include job-ID
  // Note: cannot move below 'preparation' stage for 2 reasons: it doesn't apply to child command
  // as we are defining root directory for the entire job (i.e. this is not a 'distribution level' activity; 
  // not trivial enough (there are number of properties that depend on working dir and must be reset)
  // Its useful to have one run's working directory be different from another run.
  // Update working directory so it includes JobID
  AString workDirPath = m_generalOptions.GetWorkDirProp();
  // REVISIT hack. To avoid downstream errors create results folder if it doesn't exist
  {
    LongFileName workLfn(workDirPath);
    workLfn.MakeItDirectory();
    bool dirExists = (LFN_Exists(workLfn) && LFN_IsExistingDirectory(workLfn));
    if (!dirExists)
    {
      if (LFN_CreateDirectory(workLfn) == true)
        ngapp::InfoMessage("Created folder '%s' that has job's working directory", workLfn.FilePath());
      else
        ngapp::InfoMessage("Error occurred: Unable to created folder '%s' that contains job working directory", workLfn.FilePath());
    }
  }
    
  AString jobName = m_generalOptions.GetJobNameProp();

  AString jobID = ngapp::GetJobIDFromScheduler();
  bool isInSchedulerContext = false;
  if (jobID.empty() == true)
  {
    jobID = m_generalOptions.GetJobIDProp();
    // Ensure a unique jobid for every desktopjob so that the working directory is
    // contained here and avoids the risk of overwriting existing files
    if (jobID.empty())
    {
      AString dummyStr;
      if (!ngapp::GetUniqueFileInDir(jobID, dummyStr, workDirPath, ACHAR("rsm")))
      {
        ngapp::ErrorMessage(ngapp::kNgAppFailed, "Fatal error occurred during job preparation: Unable to propose unique "
                            "sub directory in directory '%s'", workDirPath);
        return false;
      }
    }
    InfoMessage("Job is assigned a unique ID of '%s'", jobID);
  }
  else
  {
    InfoMessage("Job is running in the context of scheduler with a Job ID of '%s'", jobID);
    isInSchedulerContext = true;
  }

  SS_ASSERT(!jobID.empty())

  m_generalOptions.SetJobIDPropVal(jobID);

  // Create directory within this work directory using jobID. This jobID folder
  // is the working directory for this command
  LongFileName cmdFolderLfn;
  cmdFolderLfn.Reset(jobID, workDirPath);
  cmdFolderLfn.MakeItDirectory();
  AString newFolderStr = cmdFolderLfn.FilePath();
  m_generalOptions.SetWorkDirPropVal(newFolderStr);

  // Below will not change irrespective of distribution level. So set it just once
  cmdDef.SetRootWorkDirPropVal(m_generalOptions.GetWorkDirProp());

  AString overallFirstFolder;
  // REVISIT: hardcoding that the hierarchy is limited to 3 levels. Remove such assumptions
  overallFirstFolder = NgAppCommandDef::GetChildWorkDir
    (NgAppCommandDef::GetChildWorkDir(m_generalOptions.GetWorkDirProp(), 0),0);
  cmdDef.SetOverallFirstTaskFolderPropVal(overallFirstFolder);

  ngapp::InfoMessage("Job's root working directory is: '%s'", cmdDef.GetRootWorkDirProp());
  ngapp::InfoMessage("The working directory for the first task of this job is: '%s'", cmdDef.GetOverallFirstTaskFolderProp());

  if(my_ans_debug_data.Debug(1) == true)
  {
    io::CBlock cmdDefBlock;
    cmdDef.Write(cmdDefBlock);
    logHelp.LogParam(ACHAR("CmdDefBlock"), cmdDefBlock);
  }
  return true;
}

class NgAppStandardCommandsProvider : public INgAppCommandProviderFilter
{
public:

  // Overrides for INgAppCommandProvider for standard commands such as abort
  virtual void GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const;
  virtual int ParseCommandLineOptions(io::CBlock& cmdParams, INgAppGeneralOptionSetter* setGenOptions, const AString& cmdName, 
    std::vector<AString>& unparsedCmdLine, const std::vector<AString>& cmdlineVec, const NgAppProgramOptions& generalOptions);
  virtual int PrepareCommandExecutionEnv(const NgAppCommandDef& cmdDef, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions);
  virtual int RunNgAppCommand(INgAppCommandCallback* icmdCB);

private:
  // Project on which the standard commands such as abort act
  AString m_inputProjPath;
};

class NgAppCommandsProviderMediator : public INgAppCommandProviderFilter, public INgAppCommandProvider
{
public:

  NgAppCommandsProviderMediator(INgAppCommandProviderFilter* customCommandsProvider);

  // Overrides for "INgAppCommandProviderFilter"
  virtual INgAppCommandProvider* GetProviderForCommand(const AString& uniqueCmdName);
  // return true if app is started via cocreate (for e.g. desktopjob agent and desktopproxy)
  virtual bool IsNgAppAServiceApp() const;
  virtual const GenericNamedPropertiesObject::ParsePropSpec* 
    GetPropSpecForCommandlineParsing() const;

  // Overrides for INgAppCommandProvider for standard commands such as abort
  virtual void GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const;
  virtual int ParseCommandLineOptions(io::CBlock& cmdParams, INgAppGeneralOptionSetter* setGenOptions, const AString& cmdName, 
    std::vector<AString>& unparsedCmdLine, const std::vector<AString>& cmdlineVec, const NgAppProgramOptions& generalOptions);
  virtual int PrepareCommandExecutionEnv(const NgAppCommandDef& cmdDef, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions);
  virtual int RunNgAppCommand(INgAppCommandCallback* icmdCB);

private:
  NgAppStandardCommandsProvider m_standardCmdsProvider;
  INgAppCommandProviderFilter* m_customCmdsProvider;
};

// Below should go into program options. 
GenericNamedPropertiesObject::ParsePropSpec stdCmdOptionsSpecArray[] = {
  { "-abort", kJobIDToAbortStr, false,  "Abort a running command. Syntaxt: -abort <jobid>"},
  { 0, "", true, 0 } // this should be the last entry
  //{ "-", , false },
};


int NgAppStandardCommandsProvider::ParseCommandLineOptions(io::CBlock& cmdParams, INgAppGeneralOptionSetter* setGenOptions, const AString& cmdName, 
                                                          std::vector<AString>& unparsedCmdLine,
                                                          const std::vector<AString>& cmdlineVec, const NgAppProgramOptions& generalOptions)
{
  size_t numOpts = inputCmdLineOptionsVec.size();
  SS_ASSERT(numOpts > 1);
  if (numOpts <= 1)
  {
    ngapp::ErrorMessage(ngapp::kNgAppFailed, "Error occurred during command line parsing: "
      "Project path must be specified as last argument on the command line.");
    return false;
  }

  unparsedCmdLineOptionsVec.clear();

  std::vector<AString>::reverse_iterator riter = unparsedCmdLineOptionsVec.rbegin();
  if (riter != unparsedCmdLineOptionsVec.rend())
  {
    // The last one is always the project path
    m_projPath = *riter;
    unparsedCmdLineOptionsVec.erase(--(riter.base()));
  }

  return true;

}

// REVISIT: copy argc, argv rather than have pointers. Copy code from ngapputils file
NgAppAnsoftCOMApplication::NgAppAnsoftCOMApplication(int argc, char** argv, INgAppCommandProviderFilter* filter) 
   : m_argc(argc), m_argv(argv), m_cmdProviderFilter(0), m_cmdProvider(0), m_distCommMgr(this),
   m_appState(kNgAppUninitialized), m_ngAppCommand(this)/*, m_managedFileSvc(0)*/
{
  m_cmdProviderFilter = new NgAppCommandsProviderMediator(filter);
  SS_ASSERT(filter);
}




// desktopproxy.cpp : Defines the entry point for the console application.
//
#include "headers.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/stringutils/astring.h"
#include "wbintegutils/LoggingHelper.h"
#include "NgAnsoftCOMApp/NgAnsoftCOMApplicationUtils.h"
#include "ngcore/ipcutils/GeneralFunctions.h"
#include "ngcore/ngutils/LongFilenameOperations.h"
#include "ngcore/profile/ngperformance.h"
#include "CoreInterfaces/IAnsoftApplication.h"
#include "ngcore/ngutils/LongFileName.h"

// Utility that helps write code efficiently
// What: algorithm is written in an abbreviated form. A perl script
// converts abbrev form to C++ source handling the below situations:
// - Puts ACHAR wrapper around literals
// - Adds try/catch blocks upon a directive
Format for an abbrev algorithm:
<return-type> FunctionName(arguments with names) : diagnostics={verbose,compact} const {
  debug_log;
  try_catch;

}
// Meaning of directives:
// try_catch: add try/catch block around the code. Adjust all the throw statements so 
// they throw AStringException. Automatic string is generated if throw arguments are
// empty such as "exception number "#" occurred at function "funcname". See file "fname" for details about program state
// debuglog: add debuglog context along with the log of arguments, return values
// add_msgs: at every 'return' that is an error  
// Usage: until the algo is finalized, keep updating the
// template. Afterwars, template is either discarded or
// the output generated is merged

//Issue to tackle: when an error of IRS, there is not much info on what caused it unless the programmer takes pain to add all details themselves. 
//How: provide a function that writes name-value pairs to a file.
//Provide a code generator that builds named-values using the variable names that are in the current scope and using tostring methods to generate their string representation
//Add tostring globals for standard data types
//Create a function that creates named values from a variable argument list with each variable being a different type. A format string describes the type of variable
//Provide a DumpLocalFunctionStateToTempfile that takes a format string and varargs. Returns file name.
//The abbreviated algorithm uses adderror, addwarn, addinfo, addsystemerror, addboosterror as part of the algo. The first parameter of each of these
// functions is a string literal. Remaining parameters are the variables whose values should be displayed, with optional names for vars
// e.g. adderror("file copy failed", v1, v2=UserReadableNameForv2
// Message added will be: Error occurred: file copy failed. Parameter values are: v1=value of v1, UserReadableNameForv2=value of v2
// e.g. addsystemerror("file copy failed", v1, v2=UserReadableNameForv2
// Message added will be: Error occurred: file copy failed. System error number = #, Syetem error message = permission denied. Parameter values are: v1=value of v1, UserReadableNameForv2=value of v2
// 
// If return-type is bool, a bool bRet is created. It's value is set to value. bRet is returned
// If return-type is int, errors return ngapp::kNgAppFailed or iRet if it exists
//
// Another feature: initialization determines the type. For e.g. b1 = false => b1 is a bool
bool TestFunction(const str& arg1) : includes=yes, debuglog=yes, trycatch=yes {
  b1 = false;
  localVar = "foo";
  if (0)
    adderror("error1", b1, localVar)
}
// Program expands above to below
#include "wbintegutils/LoggingHelper.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/stringutils/astring.h"
#include "NgAnsoftCOMApp/NgAnsoftCOMApplicationUtils.h"
bool TestFunction(const AString& arg1) 
{
  bool bRet = true;
  LoggingHelper logHlpr(ACHAR("TestFunction"));
  logHlpr.LogParam(ACHAR("arg1"), arg1);
  try 
  {
    bool b1 = false;
    AString localVar (ACHAR("foo"));
    if (0)
    {
      throw new AStringException(FStr("Error occurred: error1. Parameter values are: b1 = %d, localVar = %s", b1, localVar.c_str()));
    }
  }
  catch(AStringException msg)
  {
    bRet = false;
    ngapp::ErrorMessage(ngapp::kNgAppFailed, msg.m_asciiStr);
  }

  logHlpr.LogParam(ACHAR("bRet"), bRet);
  return bRet;
}

void RunTestForUnit(const AString& unitName)
{
  if (unitName.CompareNoCase(ACHAR(""))
}


// Goal: make parsing of arbitrary text files very very easy
// How: let the parsing be defined as a schema. Output will be named-values. Multiple matches
// for a line-type 
// Schema is defined as a set of line matches. A literal identifies type of line, which is
// followed by a regulax expression to parse the rest of line. Attributes (name, etc.) of the line type follow
// Example: for batchlog, 
// Following is the schema:
// - "Starting Batch Run:" => "\'time' \'date'", "type=batchstart"
// - "Stopping Batch Run:" => "\'time' \'date'", "type=batchstart"
// - "[info]|[warning]|[error]" => "Project:(^\w.+),\sDesign:(^\w.+),\sA\svariation\s\((.+)\)\s.+\s\((.+)\)", "type=varanalysis,$1=proj,$2=design,$3=varn,$4=time"
// - "[info]|[warning]|[error]" => "Project:(^\w.+),\sDesign:(^\w.+),(.+)\s\((.+)\)", "type=varmsg,$1=proj,$2=design,$3=msg,$4=time"
// Following is the usage:
// NgAppFileContents fileContents;
// NgAppeReadTextFile(fileContents, lfn);
// GenericNamedValues batchAnalysisLineInfo;
// Declaration: int GetMatchedLine(named-values, match regex, ... -> names for matches)
// int matchedLineIndex = fileContents.GetMatchedLine(batchAnalysisLineInfo, "Starting Batch Run: (\\time)\\s+(\\date)", "start_time", "start_date");
// while(matchedLineIndex) {
//   GenericNamedValues batchLogMsgs;
//   matchedLineIndex = fileContents.GetMatchedLine(batchLogMsgs, matchedLineIndex,
//                                                    "([info]|[warning]|[error])\\s+Project:(^\w.+),\sDesign:(^\w.+),(.+)\s\((.+)\)",
//                                                  "severity", "proj", "design", "msgtxt", "time");
// }
// matchedLineIndex = fileContents.GetMatchedLine(batchAnalysisLineInfo, "Stopping Batch Run: (\\time)\\s+(\\date)", "stop_time", "stop_date");
// 



// Goal: make parsing of streamio block text files very very easy

// Goal: make parsing of library files very very easy


// Goal: Adding commandline options should be very very easy


// Goal: propose a way to extract reports for 
