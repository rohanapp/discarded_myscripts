#include "headers.h"
#include "NgAppProgressMessages.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kMessageStr = ACHAR("Message");
static const AChar* kProgressStr = ACHAR("Progress");

NgAppProgressMessages::NgAppProgressMessages()
: m_namedProps(ACHAR("NgAppProgressMessages"))
{
  InitiliazeObjectPropertySpec();
}

NgAppProgressMessages::~NgAppProgressMessages()
{
}

AString NgAppProgressMessages::GetMessageProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kMessageStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppProgressMessages::GetProgressProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProgressStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool NgAppProgressMessages::SetMessagePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kMessageStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppProgressMessages::SetProgressPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProgressStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppProgressMessages::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppProgressMessages::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppProgressMessages::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kMessageStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kProgressStr, ACHAR(""));
}

