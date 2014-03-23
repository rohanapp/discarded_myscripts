#include "headers.h"
#include "NgAppCommunicationMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kServiceRequestMessageTypeStr = ACHAR("ServiceRequestMessageType");
static const AChar* kAbortDirectiveMessageTypeStr = ACHAR("AbortDirectiveMessageType");
static const AChar* kClientCallbackMessageTypeStr = ACHAR("ClientCallbackMessageType");
static const AChar* kServiceRequestFulfilledMessageTypeStr = ACHAR("ServiceRequestFulfilledMessageType");
static const AChar* kkClientCallbackInitMessageTypeStr = ACHAR("kClientCallbackInitMessageType");

NgAppCommunicationMessage::NgAppCommunicationMessage()
: m_namedProps(ACHAR("NgAppCommunicationMessage"))
{
  InitiliazeObjectPropertySpec();
}

NgAppCommunicationMessage::~NgAppCommunicationMessage()
{
}

AString NgAppCommunicationMessage::GetServiceRequestMessageTypeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kServiceRequestMessageTypeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCommunicationMessage::GetAbortDirectiveMessageTypeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kAbortDirectiveMessageTypeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCommunicationMessage::GetClientCallbackMessageTypeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kClientCallbackMessageTypeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCommunicationMessage::GetServiceRequestFulfilledMessageTypeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kServiceRequestFulfilledMessageTypeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString NgAppCommunicationMessage::GetkClientCallbackInitMessageTypeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kkClientCallbackInitMessageTypeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool NgAppCommunicationMessage::SetServiceRequestMessageTypePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kServiceRequestMessageTypeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCommunicationMessage::SetAbortDirectiveMessageTypePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kAbortDirectiveMessageTypeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCommunicationMessage::SetClientCallbackMessageTypePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kClientCallbackMessageTypeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCommunicationMessage::SetServiceRequestFulfilledMessageTypePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kServiceRequestFulfilledMessageTypeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool NgAppCommunicationMessage::SetkClientCallbackInitMessageTypePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kkClientCallbackInitMessageTypeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppCommunicationMessage::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppCommunicationMessage::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppCommunicationMessage::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kServiceRequestMessageTypeStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kAbortDirectiveMessageTypeStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kClientCallbackMessageTypeStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kServiceRequestFulfilledMessageTypeStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kkClientCallbackInitMessageTypeStr, ACHAR(""));
}

