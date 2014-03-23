#include "headers.h"
#include "DJobServiceStatus.h"
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

DJobServiceStatus::DJobServiceStatus()
: m_namedProps(ACHAR("DJobServiceStatus"))
{
  InitiliazeObjectPropertySpec();
}

DJobServiceStatus::~DJobServiceStatus()
{
}

int DJobServiceStatus::GetTotalChildJobsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kTotalChildJobsStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int DJobServiceStatus::GetNumJobsRunningProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kNumJobsRunningStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

bool DJobServiceStatus::SetTotalChildJobsPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kTotalChildJobsStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool DJobServiceStatus::SetNumJobsRunningPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kNumJobsRunningStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError DJobServiceStatus::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString DJobServiceStatus::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void DJobServiceStatus::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kTotalChildJobsStr, Value(-1));
  m_namedProps.InitializePropertySpec(kNumJobsRunningStr, Value(-1));
}

