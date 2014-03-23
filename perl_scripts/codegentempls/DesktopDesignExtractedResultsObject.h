// -----------------------------------------------------------------
// Original Author: Naresh Appannagaari
// Contents: 
//     
// Copyright 2011 ANSYS Inc, All Rights Reserved
// No part of this file may be reproduced, stored in a 
// retrieval system, or transmitted in any form or by any means -
// electronic, mechanical, photocopying, recording, or otherwise - 
// without prior written permission of ANSYS Inc.
// -----------------------------------------------------------------
#ifndef _DESKTOPDESIGNEXTRACTEDRESULTSOBJECT_H
#define _DESKTOPDESIGNEXTRACTEDRESULTSOBJECT_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "ngcore/streamio/block.h"
#include "ngcore/streamio/streamio_object.h"
#include "ngcore/streamio/errorConstants.h"
#include <vector>
#include "ngcore/stringutils/astring.h"
#include "ngcore/ngutils/UtilityIds.h"

class LongFileName;
class AString;
class Column;
class OneDimensionSimulationResults;
class io::CBlock;

//ExtraIncludeInCpp: none

//
// !!PURPOSE!!
// 
// Denotes the full extracted results for a design
// Fow now, just has 0D, 1D results. Scope of 1D results: all outputs for all
// variations are at the same set of primary sweep values
class NGANSOFTCOMAPP_API DesktopDesignExtractedResultsObject : public io::CStreamio_block_object 
{
  
  public:
  
   DesktopDesignExtractedResultsObject() ;
   ~DesktopDesignExtractedResultsObject() ;
  
  // Keep columns as external files referenced by a header file.
  // External column files are always referenced relative to job's root folder
  io::ReadError WriteExtractedResultsObject(const LongFileName& fpath) ;
  io::ReadError ReadExtractedResultsObject(const LongFileName& fpath) ;
  // Read multiple files, one per child and merge them in to single file
  io::ReadError ReadImmediateChildResultsAndMerge(const std::vector<AString>& filePaths) ;
  // Write file in the job root folder with name "projname_jobid.csv"
  io::ReadError GenerateCSVFilesOfOneDResults(const AString& csvFileName) const;
  
  void InitializeOneDSimResults(const AString& sweepName, const Column& sweepVals) ;
  // At this time, all 1D results should have the same primary sweep values. So last parameter should be NULL
  void AddOneDResult(id::BasicID majorvvID, const AString& qtyName, const Column& qtyVals, const Column* sweepVals) ;
  
  const OneDimensionSimulationResults& GetOneDResults() const;
  
  private:
  
  io::ReadError DoDataExchangeResultsObject(io::CBlock& block, bool do_read) ;
  OneDimensionSimulationResults m_results1D;
  

};

#endif
