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
#ifndef _NGAPPDISTRIBUTEDCOMMMGR_H
#define _NGAPPDISTRIBUTEDCOMMMGR_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"


class NgAppAnsoftCOMApplication;


//
// Purpose
//
// - Facilitates easy communication across the machines. It does this through the proxies and stubs it manages
// - Services register with the communication manager using a unique name. Clients invoke services using the same name
// Supports standard  interface to single-threaded applications that are based on ngapp framework:
// DeliverServiceRequest(callback for ServiceProgressMessage, ServiceCompletion)
// Makes standard requests to the service: HandleServiceRequest(callback for service progressmessage, service completion)
// CreateCommandObject given named-parameters. Will issue unique IDs to commands.
// Will take the command and address and dispatch the cmd and bring back the results. All in the
// same thread. The service offered: remote execution. The challenges tackled: typically IPC challenges
// such as: reliable startup/shutdown, distributed communication, messages/progress.
//
class NGANSOFTCOMAPP_API NgAppDistributedCommMgr
{
  
  public:
   NgAppDistributedCommMgr(NgAppAnsoftCOMApplication* owner) ;
   ~NgAppDistributedCommMgr() ;
  
  // Initialize stubs
  bool InitializeCommunicationObjects() ;
  
  private:
  
  NgAppAnsoftCOMApplication* m_ownerApp;
  // Used to assign IDs to commands including distributed ones
  AnsoftIDServer idServer;
  

};

#endif
