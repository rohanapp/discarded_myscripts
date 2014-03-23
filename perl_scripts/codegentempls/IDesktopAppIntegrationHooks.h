// -----------------------------------------------------------------
// Original Author: Naresh Appannagaari
// Contents: 
//     
// Copyright 2013 ANSYS Inc, All Rights Reserved
// No part of this file may be reproduced, stored in a 
// retrieval system, or transmitted in any form or by any means -
// electronic, mechanical, photocopying, recording, or otherwise - 
// without prior written permission of ANSYS Inc.
// -----------------------------------------------------------------
#ifndef _IDESKTOPAPPINTEGRATIONHOOKS_H
#define _IDESKTOPAPPINTEGRATIONHOOKS_H


#include <vector>
#include "ngcore/stringutils/astring.h"
#include "CoreInterfaces/InterfaceDefs.h"

class CMenu;
class std::vector<CCmdTarget*>;
class AString;
class IDesktopCmdLineInfo;


// 
// Purpose: 
// - Interface that is implemented by desktops are
//   merged into integrated desktop.
// - Provides implementation for functionality that's
//   considered 'product specific' rather than
//   being same for all products in the desktop
//
class IDesktopAppIntegrationHooks
{
   
  public:
  
  virtual bool DoAutomaticDesignCleanup() const = 0;
  
  virtual void ExtendMainMenu(CMenu& menu, std::vector<CCmdTarget*>& vecCmdTargets) = 0;
  
  virtual void GetCustomBatchCommands(std::map<AString,int>& cmds) const = 0;
  virtual bool DoCustomBatchCommand(AString& command, std::vector<AString>& args) = 0;
  
  virtual void InitializeProductModule(IDesktopCmdLineInfo& cmdInfo) = 0;
  
  virtual void* GetInterface(InterfaceID nID) = 0;
  

};

#endif
