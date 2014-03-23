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
#ifndef _DISTRIBUTEDMACHINETREETWOLEVEL_H
#define _DISTRIBUTEDMACHINETREETWOLEVEL_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include <vector>
#include "ngcore/stringutils/astring.h"



class NGANSOFTCOMAPP_API DistributedMachineTreeTwoLevel
{
  
  public:
  
  bool InitializeMachinesToTwoLevel(const std::vector<AString>& uniqueNodesAtFirstLevel, const std::vector<int>& uniqueNodeCoresAtSecondLevel) ;
  // Below is the case of machines assigned to launch a leaf command
  bool InitializeMachinesToSingleLevel(const std::vector<AString>& nodeVec) ;
  int GetFlatMachineListForImmediateChildren(std::vector<AString>& macNamesVec, std::vector<int>& vecMacCores) const;
  int GetFlatMachineListForGrandChildren(std::vector<AString>& macNamesVec, std::vector<int>& vecMacCores, int childIndex) const;
  
  private:
  
  // REVISIT: below needs to be made more generic to support more activation topologies
  std::vector<AString> m_childMachineList;
  std::vector<int> m_childMachineCores;

};

#endif
