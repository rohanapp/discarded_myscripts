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
#ifndef _INGAPPDISTRIBUTEDSERVICEPROXY_H
#define _INGAPPDISTRIBUTEDSERVICEPROXY_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"




class NGANSOFTCOMAPP_API INgAppDistributedServiceProxy
{
   
  public:
  
  // After calling below method, the pointer to this object is no longer valid.
  // So below must be the last call to be made to this interface
  virtual void OnDoneUsingService() = 0;
  virtual int DistributeNgAppCommandToAllNodes() = 0;
  

};

#endif
