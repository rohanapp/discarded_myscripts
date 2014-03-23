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
#ifndef _DJOBSERVICESTATUS_H
#define _DJOBSERVICESTATUS_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/common/Win32Types.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"
#include "ngcore/streamio/streamio_object.h"
#include "ngcore/streamio/errorConstants.h"
#include "ngcore/stringutils/astring.h"
#include "NgAnsoftCOMApp/GenericNamedPropertiesObject.h"

class io::CBlock;

class NGANSOFTCOMAPP_API DJobServiceStatus : public io::CStreamio_block_object
{

public:

  DJobServiceStatus();
  ~DJobServiceStatus();

  int GetTotalChildJobsProp() const;
  int GetNumJobsRunningProp() const;
  
  bool SetTotalChildJobsPropVal(int val);
  bool SetNumJobsRunningPropVal(int val);
  
  virtual io::ReadError DoDataExchange(io::CBlock& block, bool do_read);
  virtual AString GetItemName() const;

private:

  void InitiliazeObjectPropertySpec();

  GenericNamedPropertiesObject m_namedProps;

};

#endif
