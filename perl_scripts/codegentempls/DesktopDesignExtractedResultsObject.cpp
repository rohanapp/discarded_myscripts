#include "headers.h"
#include "DesktopDesignExtractedResultsObject.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/ngutils/LongFileName.h"
#include "ngcore/column/Column.h"
#include "wbintegutils/LoggingHelper.h"
#include "ngcore/ipcutils/GeneralFunctions.h"
#include "ngcore/streamio/data_exchange.h"
#include "algorithm"
#include "ngcore/value/io_data_exchange.h"


 DesktopDesignExtractedResultsObject::DesktopDesignExtractedResultsObject() 
{
}


 DesktopDesignExtractedResultsObject::~DesktopDesignExtractedResultsObject() 
{
}


io::ReadError DesktopDesignExtractedResultsObject::WriteExtractedResultsObject(const LongFileName& fpath) 
{
  CLoggingHelper logHelp(ACHAR("DesktopDesignExtractedResultsObject::WriteExtractedResultsObject"));
  logHelp.LogParam(ACHAR("fpath"), fpath);
  AString tempfile;
  bool ret = AnstGetTempFileName(tempfile, destinationDir, extension string (optional), prefix string options);
  io::CToken_ostream out(m_filePathName);
  io::CBlock blk(blockName);
  if (out.fail()) ZZZ // handle error;
  out.Format(false);
  out.Close();
  out << io::NewLine;
}


io::ReadError DesktopDesignExtractedResultsObject::ReadExtractedResultsObject(const LongFileName& fpath) 
{
  CLoggingHelper logHelp(ACHAR("DesktopDesignExtractedResultsObject::ReadExtractedResultsObject"));
  logHelp.LogParam(ACHAR("fpath"), fpath);
  LongFileName lfn;
  io::CToken_istream inStream(lfn);
  // get the name of the outermost block in the file
  AString blockName;
  io::CBlockPtr blockPtr(blockName);
  inStream >> *blockPtr;
  if (blockPtr->Found() == false) ZZZZ // error;
  
  // Read block into your streamio object
  // Note: GetItemName of below streamio obj should match the blockName
  io::ReadError err = streamioobj.Read(*blockPtr);
  if (err != io::kNoError) ZZZZ // handle error;
}


io::ReadError DesktopDesignExtractedResultsObject::ReadImmediateChildResultsAndMerge(const std::vector<AString>& filePaths) 
{
  std::vector<T> container;
  std::vector<type>::iterator iter;
  for(iter = container.begin(); iter != container.end(); ++iter)
  const type& elem = *iter;
}


io::ReadError DesktopDesignExtractedResultsObject::GenerateCSVFilesOfOneDResults(const AString& csvFileName) const
{
  CLoggingHelper logHelp(ACHAR("DesktopDesignExtractedResultsObject::GenerateCSVFilesOfOneDResults"));
  logHelp.LogParam(ACHAR("csvFileName"), csvFileName);
  io::CToken_ostream out(m_filePathName);
  io::CBlock blk(blockName);
  if (out.fail()) ZZZ // handle error;
  out.Format(false);
  out.Close();
  out << io::NewLine;
}


void DesktopDesignExtractedResultsObject::InitializeOneDSimResults(const AString& sweepName, const Column& sweepVals) 
{
  CLoggingHelper logHelp(ACHAR("DesktopDesignExtractedResultsObject::InitializeOneDSimResults"));
  logHelp.LogParam(ACHAR("sweepName"), sweepName);
  logHelp.LogParam(ACHAR("sweepVals"), sweepVals);
  SS_ASSERT(!ACHAR(""));
}


void DesktopDesignExtractedResultsObject::AddOneDResult(id::BasicID majorvvID, const AString& qtyName, const Column& qtyVals, const Column* sweepVals) 
{
  CLoggingHelper logHelp(ACHAR("DesktopDesignExtractedResultsObject::AddOneDResult"));
  logHelp.LogParam(ACHAR("majorvvID"), majorvvID);
  logHelp.LogParam(ACHAR("qtyName"), qtyName);
  logHelp.LogParam(ACHAR("qtyVals"), qtyVals);
  logHelp.LogParam(ACHAR("sweepVals"), sweepVals);
  SS_ASSERT(!ACHAR(""));
}


const OneDimensionSimulationResults& DesktopDesignExtractedResultsObject::GetOneDResults() const
{
}


io::ReadError DesktopDesignExtractedResultsObject::DoDataExchangeResultsObject(io::CBlock& block, bool do_read) 
{
  // ngcore/streamio/data_exchange.h
  // Concrete streamio_block object: make sure to implement virtual AString GetItemName
  io::CReadError err;
  err += io::DoDataExchange(block, do_read, kKeepOriginalsStr, m_keepOriginals);
  err += io::DoDataExchange(block, do_read, kBlankPartIDStr, m_blankPartID);
  err += io::DoDataExchangeVec(block, do_read, kEdgeListStr, m_vSelectedEdgeIDs);
  
  io::CBlock cmdOptionsBlock(ACHAR("CommandLine"));
  cmdOptions_istream >> cmdOptionsBlock;
  
  // Writing of block func
  io::CBlock_func func(kEdgeListStr);
  std::vector<id::BasicID>::const_iterator iter;
  for (iter = m_vSelectedEdgeIDs.begin();iter != m_vSelectedEdgeIDs.end();++iter)
  func << *iter;
  io::CBlock << func;
  
  // Reading of block func
  io::CBlock_func func(kEdgeListStr);
  io::CBlock >> func;
  if (!block.Found()) ZZZ //sth;
  err = io::kNotFound;
  io::CBlock_func::const_list_iterator func_iter = func.begin();
  while (func_iter != func.end());
  if (!func.QueryUnamedValues(func_iter,edgeID)) ;
  
  // STLmap. Similarly Vec, etc. can be done. Works only for containers that contain
  // simple objects
  std::map<AString, AString, AString::NoCaseLess> strStrMap;
  err += io::DoDataExchangeMap(block, do_read, ACHAR("STLMapBlock"), strStrMap);
  SS_ASSERT(err == io::kNoError);
  RecordError(err);
  return err;
}
