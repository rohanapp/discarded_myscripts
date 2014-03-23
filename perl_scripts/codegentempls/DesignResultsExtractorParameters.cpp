#include "headers.h"
#include "DesignResultsExtractorParameters.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"
#include "ngcore/value/ValueUtil.h"

static const AChar* kDesignNameStr = ACHAR("DesignName");
static const AChar* kProjPathStr = ACHAR("ProjPath");
static const AChar* kOutputFolderStr = ACHAR("OutputFolder");
static const AChar* kCSVFilePathStr = ACHAR("CSVFilePath");

DesignResultsExtractorParameters::DesignResultsExtractorParameters()
: m_namedProps(ACHAR("DesignResultsExtractorParameters"))
{
  InitiliazeObjectPropertySpec();
}

DesignResultsExtractorParameters::~DesignResultsExtractorParameters()
{
}

AString DesignResultsExtractorParameters::GetDesignNameProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kDesignNameStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString DesignResultsExtractorParameters::GetProjPathProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kProjPathStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString DesignResultsExtractorParameters::GetOutputFolderProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kOutputFolderStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

AString DesignResultsExtractorParameters::GetCSVFilePathProp() const
{
  const ValueBase* vb = m_namedProps.GetPropertyValue(kCSVFilePathStr);
  SS_ASSERT(vb);
  if (!vb)
    return ACHAR("");
  return ValueUtil::GetStringInsideQuotes(vb->GetStringValue());
}

bool DesignResultsExtractorParameters::SetDesignNamePropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kDesignNameStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool DesignResultsExtractorParameters::SetProjPathPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kProjPathStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool DesignResultsExtractorParameters::SetOutputFolderPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kOutputFolderStr, val);
  SS_ASSERT(retVal);
  return retVal;
}

bool DesignResultsExtractorParameters::SetCSVFilePathPropVal(const AString& val)
{
  bool retVal = m_namedProps.SetPropertyValue(kCSVFilePathStr, val);
  SS_ASSERT(retVal);
  return retVal;
}


io::ReadError DesignResultsExtractorParameters::DoDataExchange(io::CBlock& block, bool do_read) 
{
  return m_namedProps.DoDataExchange(block, do_read);
}

AString DesignResultsExtractorParameters::GetItemName() const
{
  return m_namedProps.GetItemName();
}

void DesignResultsExtractorParameters::InitiliazeObjectPropertySpec()
{
  m_namedProps.InitializePropertySpec(kDesignNameStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kProjPathStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kOutputFolderStr, ACHAR(""));
  m_namedProps.InitializePropertySpec(kCSVFilePathStr, ACHAR(""));
}

