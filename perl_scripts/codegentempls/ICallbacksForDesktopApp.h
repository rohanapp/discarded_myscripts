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
#ifndef _ICALLBACKSFORDESKTOPAPP_H
#define _ICALLBACKSFORDESKTOPAPP_H

class IDesktop;
class IProject;
class LongFileName;
class IMessageHandler;

// 
// Purpose: 
// - Interface that is implemented by desktops are
//   merged into integrated desktop.
// - Provides implementation for functionality that's
//   considered 'product specific' rather than
//   being same for all products in the desktop
//
class ICallbacksForDesktopApp
{
   
  public:
  
  virtual IDesktop* GetIDesktop() = 0;
  virtual IProject* GetActiveIProject() const = 0;
  virtual bool IsProjectLocked(const LongFileName& projectFile) = 0;
  virtual void UnlockProject(const LongFileName& projectFileName) = 0;
  virtual IMessageHandler* GetIMessageHandler() = 0;

};

#endif
