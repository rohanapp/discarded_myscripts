#include "headers.h"
#include "LargeDSOCommandParams.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kDistribMachinesStr = ACHAR("DistribMachines");
static const AChar* kIsNonGraphicalStr = ACHAR("IsNonGraphical");
static const AChar* kWaitForLicenseStr = ACHAR("WaitForLicense");
static const AChar* kMPStr = ACHAR("MP");
static const AChar* kIdleCoresStr = ACHAR("IdleCores");
static const AChar* kSolveSetupNameStr = ACHAR("SolveSetupName");
static const AChar* kProjectPathStr = ACHAR("ProjectPath");

LargeDSOCommandParams::LargeDSOCommandParams()
: m_namedProps(ACHAR("LargeDSOCommandParams"))
{
  InitiliazeObjectPropertySpec();
}

LargeDSOCommandParams::~LargeDSOCommandParams()
{
}

AString LargeDSOCommandParams::GetDistribMachinesProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kDistribMachinesStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

bool LargeDSOCommandParams::GetIsNonGraphicalProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kIsNonGraphicalStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetIntValue() ? true : false;
}

bool LargeDSOCommandParams::GetWaitForLicenseProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kWaitForLicenseStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetIntValue() ? true : false;
}

int LargeDSOCommandParams::GetMPProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kMPStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

int LargeDSOCommandParams::GetIdleCoresProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kIdleCoresStr);
  SS_ASSERT(vb);
  if (!vb)
    return -1;
  return vb->GetIntValue();
}

AString LargeDSOCommandParams::GetSolveSetupNameProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kSolveSetupNameStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

AString LargeDSOCommandParams::GetProjectPathProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProjectPathStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

bool LargeDSOCommandParams::SetDistribMachinesPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kDistribMachinesStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetIsNonGraphicalPropVal(bool val)
{
  bool retVal = m_namedProps.SetPropertyValue(kIsNonGraphicalStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetWaitForLicensePropVal(bool val)
{
  bool retVal = m_namedProps.SetPropertyValue(kWaitForLicenseStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetMPPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kMPStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetIdleCoresPropVal(int val)
{
  bool retVal = m_namedProps.SetPropertyValue(kIdleCoresStr, Value(val));
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetSolveSetupNamePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kSolveSetupNameStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool LargeDSOCommandParams::SetProjectPathPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProjectPathStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError LargeDSOCommandParams::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString LargeDSOCommandParams::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void LargeDSOCommandParams::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kDistribMachinesStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kIsNonGraphicalStr, Value(true));
  m_namedProps.InitializePropertySpec(kWaitForLicenseStr, Value(false));
  m_namedProps.InitializePropertySpec(kMPStr, Value(1));
  m_namedProps.InitializePropertySpec(kIdleCoresStr, Value(0));
  m_namedProps.InitializePropertySpec(kSolveSetupNameStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kProjectPathStr, ACHAR(""));
}

