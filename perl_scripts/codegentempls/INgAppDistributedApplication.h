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
#ifndef _INGAPPDISTRIBUTEDAPPLICATION_H
#define _INGAPPDISTRIBUTEDAPPLICATION_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "ngcore/Value/Value.h"
#include "ngcore/stringutils/astring.h"

class AString;


class NGANSOFTCOMAPP_API INgAppDistributedApplication
{
  
  public:
  
  virtual int GetDistributionLevelOfThisApp() const = 0;
  virtual AString GetHostMachineName() const = 0;
  virtual AString GetSiblingRelativeRank() const = 0;
  

};

#endif
