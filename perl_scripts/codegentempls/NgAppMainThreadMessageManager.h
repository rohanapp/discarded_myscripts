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
#ifndef _NGAPPMAINTHREADMESSAGEMANAGER_H
#define _NGAPPMAINTHREADMESSAGEMANAGER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "NgAppMessageManager.h"

class AString;


class NGANSOFTCOMAPP_API NgAppMainThreadMessageManager : public NgAppMessageManager 
{
  
  public:
  
   NgAppMainThreadMessageManager() ;
  bool SetMessageDestinationFile(const AString& pathToLogFile) ;
  

};

#endif
