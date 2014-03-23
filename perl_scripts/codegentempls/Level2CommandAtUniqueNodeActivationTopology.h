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
#ifndef _LEVEL2COMMANDATUNIQUENODEACTIVATIONTOPOLOGY_H
#define _LEVEL2COMMANDATUNIQUENODEACTIVATIONTOPOLOGY_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "NgAnsoftCOMApp/NgAppCommandActivationTopology.h"

class DistributedMachineTreeTwoLevel;
class NgAppCommandDef;


class NGANSOFTCOMAPP_API Level2CommandAtUniqueNodeActivationTopology : public NgAppCommandActivationTopology 
{
  
  public:
  
  virtual int GetDistributedMachineListForChildActivation(DistributedMachineTreeTwoLevel& childMacList, const NgAppCommandDef& cmdDef) const;
  virtual bool IsWorkLoadDistributionNeededAtThisLevel(const NgAppCommandDef& cmdDef) const;
  

};

#endif
