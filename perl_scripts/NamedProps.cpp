#include "headers.h"
#include "DJobTaskStatusBlockObject.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "ngcore/value/ValueUtil.h"

static const AChar* kTotalTasksForFullJobStr = ACHAR("TotalTasksForFullJob");
static const AChar* kNumTasksDoneSuccessStr = ACHAR("NumTasksDoneSuccess");
static const AChar* kNumTasksDoneErrorStr = ACHAR("NumTasksDoneError");
static const AChar* kStartTaskGlobalIndexStr = ACHAR("StartTaskGlobalIndex");
static const AChar* kEndTaskGlobalExclIndexStr = ACHAR("EndTaskGlobalExclIndex");
static const AChar* kErrorStrsStr = ACHAR("ErrorStrs");

DJobTaskStatusBlockObject::DJobTaskStatusBlockObject()
: m_namedProps(ACHAR("DJobTaskStatusBlockObject"))
{
  InitiliazeObjectPropertySpec();
}

DJobTaskStatusBlockObject::~DJobTaskStatusBlockObject()
{
}

int DJobTaskStatusBlockObject::GetTotalTasksForFullJobProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kTotalTasksForFullJobStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobTaskStatusBlockObject::GetNumTasksDoneSuccessProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kNumTasksDoneSuccessStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobTaskStatusBlockObject::GetNumTasksDoneErrorProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kNumTasksDoneErrorStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobTaskStatusBlockObject::GetStartTaskGlobalIndexProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kStartTaskGlobalIndexStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobTaskStatusBlockObject::GetEndTaskGlobalExclIndexProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kEndTaskGlobalExclIndexStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

AString DJobTaskStatusBlockObject::GetErrorStrsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kErrorStrsStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool DJobTaskStatusBlockObject::SetTotalTasksForFullJobPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kTotalTasksForFullJobStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobTaskStatusBlockObject::SetNumTasksDoneSuccessPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kNumTasksDoneSuccessStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobTaskStatusBlockObject::SetNumTasksDoneErrorPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kNumTasksDoneErrorStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobTaskStatusBlockObject::SetStartTaskGlobalIndexPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kStartTaskGlobalIndexStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobTaskStatusBlockObject::SetEndTaskGlobalExclIndexPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kEndTaskGlobalExclIndexStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobTaskStatusBlockObject::SetErrorStrsPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kErrorStrsStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError DJobTaskStatusBlockObject::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString DJobTaskStatusBlockObject::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void DJobTaskStatusBlockObject::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kTotalTasksForFullJobStr, Value(-1));
  m_namedProps.InitializePropertySpec(kNumTasksDoneSuccessStr, Value(-1));
  m_namedProps.InitializePropertySpec(kNumTasksDoneErrorStr, Value(-1));
  m_namedProps.InitializePropertySpec(kStartTaskGlobalIndexStr, Value(-1));
  m_namedProps.InitializePropertySpec(kEndTaskGlobalExclIndexStr, Value(-1));
  m_namedProps.InitializePropertySpec(kErrorStrsStr, ACHAR(""));
}

