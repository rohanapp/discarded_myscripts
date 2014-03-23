#include "headers.h"
#include "NgAppCmdInteractionProgramParameters.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kProgNameStr = ACHAR("ProgName");
static const AChar* kProgParamsStr = ACHAR("ProgParams");
static const AChar* kInputProjStr = ACHAR("InputProj");

NgAppCmdInteractionProgramParameters::NgAppCmdInteractionProgramParameters()
: m_namedProps(ACHAR("NgAppCmdInteractionProgramParameters"))
{
  InitiliazeObjectPropertySpec();
}

NgAppCmdInteractionProgramParameters::~NgAppCmdInteractionProgramParameters()
{
}

AString NgAppCmdInteractionProgramParameters::GetProgNameProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProgNameStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCmdInteractionProgramParameters::GetProgParamsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProgParamsStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCmdInteractionProgramParameters::GetInputProjProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kInputProjStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool NgAppCmdInteractionProgramParameters::SetProgNamePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProgNameStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCmdInteractionProgramParameters::SetProgParamsPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProgParamsStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCmdInteractionProgramParameters::SetInputProjPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kInputProjStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppCmdInteractionProgramParameters::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppCmdInteractionProgramParameters::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppCmdInteractionProgramParameters::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kProgNameStr, ACHAR("interrupt"));
  m_namedProps.InitializePropertySpec(kProgParamsStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kInputProjStr, ACHAR(""));
}

