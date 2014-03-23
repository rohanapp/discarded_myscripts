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
#ifndef _ILEGACYDESKTOP_H
#define _ILEGACYDESKTOP_H


#include "CoreInterfaces/IDesktop.h"
#include "ngcore/stringutils/astring.h"
#include "ngcore/common/Win32Types.h"
#include <vector>

class CMenu;
class std::vector<CCmdTarget*>;
class AString;
class LongFileName;
class LocalVersion;


// 
// Purpose: 
// - Interface that is implemented by desktops are
//   merged into integrated desktop.
// - Has legacy implementation for methods (overridden from
//   IDesktop and DesktopApp) that are potentially needed in
//   integrated desktop environment. For e.g. to access
//   one product's branding, for legacy translation
//
class ILegacyDesktop : public IDesktop 
{
   
  public:
  
  
  virtual AString GetHelpFile() const = 0;
  virtual bool ProductSupportsContextHelp() const = 0;
  
  virtual bool DoAutomaticDesignCleanup() const = 0;
  
  virtual DWORD GetSplashScreenBitmapID() const = 0;
  AString GetProductTrademarkSymbol() const = 0;
  
  virtual void ExtendMainMenu(CMenu& menu, std::vector<CCmdTarget*>& vecCmdTargets) = 0;
  virtual void GetCustomBatchCommands(std::map<AString,int>& cmds) const = 0;
  virtual bool DoCustomBatchCommand(AString& command, std::vector<AString>& args) = 0;
  
  virtual AString GetVersionDependentProgID() const = 0;
  
  virtual bool AllowOpenOfVersion(AString& errMsg, const LongFileName& projectFile, const LocalVersion& fileVersion) const = 0;
  
  virtual bool GetShowProjectSimulateAllMenu() const = 0;
  virtual bool GetShowScriptingMenuItems() const = 0;
  virtual bool GetShowSaveAsTechnologyFileMenuItem() const = 0;
  virtual bool SupportsAnsoftCOM() const = 0;
  virtual bool SupportsArrayVariables() const = 0;
  virtual bool SupportsExitNoSaveInWBDataInteg() const = 0;
  virtual bool SupportsFileBasedRegistry() const = 0;
  virtual bool AllowUseOfDesignDatasetsInGeometry() const = 0;
  bool GetSupportsWorkspaceUsabilityOptions() const = 0;
  bool SupportMultiThreadsPrePostProcessing() const = 0;
  

};

#endif
