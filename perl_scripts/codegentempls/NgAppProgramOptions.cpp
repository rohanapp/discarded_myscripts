#include "headers.h"
#include "NgAppProgramOptions.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"

static const AChar* kProdExeStr = ACHAR("ProdExe");

NgAppProgramOptions::NgAppProgramOptions()
: m_namedProps(ACHAR("NgAppProgramOptions"))
{
  InitiliazeObjectPropertySpec();
}

NgAppProgramOptions::~NgAppProgramOptions()
{
}

AString NgAppProgramOptions::GetProdExeProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProdExeStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool NgAppProgramOptions::SetProdExePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProdExeStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError NgAppProgramOptions::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString NgAppProgramOptions::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void NgAppProgramOptions::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kProdExeStr, ACHAR("maxwell.exe"));
}

