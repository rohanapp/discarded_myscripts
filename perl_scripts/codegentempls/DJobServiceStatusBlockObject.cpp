#include "headers.h"
#include "DJobServiceStatusBlockObject.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "ngcore/value/ValueUtil.h"

static const AChar* kTotalChildJobsStr = ACHAR("TotalChildJobs");
static const AChar* kNumJobsRunningStr = ACHAR("NumJobsRunning");

DJobServiceStatusBlockObject::DJobServiceStatusBlockObject()
: m_namedProps(ACHAR("DJobServiceStatusBlockObject"))
{
  InitiliazeObjectPropertySpec();
}

DJobServiceStatusBlockObject::~DJobServiceStatusBlockObject()
{
}

int DJobServiceStatusBlockObject::GetTotalChildJobsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kTotalChildJobsStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobServiceStatusBlockObject::GetNumJobsRunningProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kNumJobsRunningStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

bool DJobServiceStatusBlockObject::SetTotalChildJobsPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kTotalChildJobsStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobServiceStatusBlockObject::SetNumJobsRunningPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kNumJobsRunningStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError DJobServiceStatusBlockObject::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString DJobServiceStatusBlockObject::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void DJobServiceStatusBlockObject::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kTotalChildJobsStr, Value(-1));
  m_namedProps.InitializePropertySpec(kNumJobsRunningStr, Value(-1));
}

