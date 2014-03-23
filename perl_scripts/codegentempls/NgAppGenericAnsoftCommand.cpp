#include "headers.h"
#include "NgAppGenericAnsoftCommand.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kCommandNameStr = ACHAR("CommandName");
static const AChar* kCommandBlockStr = ACHAR("CommandBlock");

NgAppGenericAnsoftCommand::NgAppGenericAnsoftCommand()
: m_namedProps(ACHAR("NgAppGenericAnsoftCommand"))
{
  InitiliazeObjectPropertySpec();
}

NgAppGenericAnsoftCommand::~NgAppGenericAnsoftCommand()
{
}

AString NgAppGenericAnsoftCommand::GetCommandNameProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kCommandNameStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppGenericAnsoftCommand::GetCommandBlockProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kCommandBlockStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool NgAppGenericAnsoftCommand::SetCommandNamePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kCommandNameStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppGenericAnsoftCommand::SetCommandBlockPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kCommandBlockStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppGenericAnsoftCommand::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppGenericAnsoftCommand::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppGenericAnsoftCommand::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kCommandNameStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kCommandBlockStr, ACHAR(""));
}

