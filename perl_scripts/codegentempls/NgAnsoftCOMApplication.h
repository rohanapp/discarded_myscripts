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
#ifndef _NGANSOFTCOMAPPLICATION_H
#define _NGANSOFTCOMAPPLICATION_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "AnsoftCOM/AnsoftCOMApplication.h"

class io::CBlock;


class NGANSOFTCOMAPP_API NgAnsoftCOMApplication : public AnsoftCOMApplication 
{
   
  public:
  
  // Client app overrides below to accept message that came from it's service call
  // Default behavior: message-manager is populated and message handled
  virtual bool HandleClientCallbackFromService(const io::CBlock& msgAsBlock) ;
  
  //
  // Service application
  //
  // Service app needs to provide below method and return command result. Framework passes results to the clientapp that 
  // made this service request
  // Note: No override is needed for pure client apps as long as they don't additionally provide a service
  virtual bool HandleServiceRequestFromClient(const io::CBlock& cmdAsBlock) ;

};

#endif
