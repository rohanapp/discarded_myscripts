CodeType: Class

// Purpose:
//
// Message queue:
// Ng AnsoftCOMApplications typically run multiple threads. Each thread needs it's own message buffer. This class allows such
// thread-specific queues. 
//
// Message handling:
// The algorithms running in the
// thread handle the message buffer as appropriate: some threads that run AnsoftCOM service will likely pass back the
// messages to caller. A thread that runs in a batch application might flush message buffer to a log file.
// A default message-hanlder that flushes msgs to output/error files is provided by this class. Clients can use this
// handler if necessary. 
//
class ThreadMessageManager : msgmgr,msghandler {

public:

ClassMethods {

Constructor(const str& pathToLogFile) {}

// Use the below static to access message manager for the current thread
static msgmgr* GetMessageManager() {tlsaccessimpl}

// Call below methods for initialization and destruction
static void InitializeThreadMessageManager() {tlsconstruct}
static void DestroyThreadMessageManager() {tlsdestruct}

}

private:

ClassMembers {
static pthread_key_t gThreadSpecificKey {none}
lfn m_logFileLfn {none}
}

}
