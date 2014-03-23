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
#ifndef _DESKTOPPROXYLIBDLL_H
#define _DESKTOPPROXYLIBDLL_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"


class AString;
class LaunchDesktopCmdDefinition;


class NGANSOFTCOMAPP_API DesktopProxyLibDLL
{
  
  public:
  
  bool InitializeDesktopProxyLibDLL() ;
  bool ResetDesktopProxyLibDLL() ;
  bool LaunchDesktop(const LaunchDesktopCmdDefinition& defn) ;
  

};

#endif
