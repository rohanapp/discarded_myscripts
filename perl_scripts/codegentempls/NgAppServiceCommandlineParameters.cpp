#include "headers.h"
#include "NgAppServiceCommandlineParameters.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kProgOptionsStr = ACHAR("ProgOptions");
static const AChar* kCommandDefStr = ACHAR("CommandDef");
static const AChar* kCommandParamsStr = ACHAR("CommandParams");

NgAppServiceCommandlineParameters::NgAppServiceCommandlineParameters()
: m_namedProps(ACHAR("NgAppServiceCommandlineParameters"))
{
  InitiliazeObjectPropertySpec();
}

NgAppServiceCommandlineParameters::~NgAppServiceCommandlineParameters()
{
}

AString NgAppServiceCommandlineParameters::GetProgOptionsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProgOptionsStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

AString NgAppServiceCommandlineParameters::GetCommandDefProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kCommandDefStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

AString NgAppServiceCommandlineParameters::GetCommandParamsProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kCommandParamsStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return vb->GetStringValue();
}

bool NgAppServiceCommandlineParameters::SetProgOptionsPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProgOptionsStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppServiceCommandlineParameters::SetCommandDefPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kCommandDefStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppServiceCommandlineParameters::SetCommandParamsPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kCommandParamsStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppServiceCommandlineParameters::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppServiceCommandlineParameters::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppServiceCommandlineParameters::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kProgOptionsStr, ACHAR("block"));
  m_namedProps.InitializePropertySpec(kCommandDefStr, ACHAR("block"));
  m_namedProps.InitializePropertySpec(kCommandParamsStr, ACHAR("block"));
}

