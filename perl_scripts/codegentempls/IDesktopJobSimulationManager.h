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
#ifndef _IDESKTOPJOBSIMULATIONMANAGER_H
#define _IDESKTOPJOBSIMULATIONMANAGER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"


class PrepareForLargeScaleDSOParams;


class NGANSOFTCOMAPP_API IDesktopJobSimulationManager
{
  public:
  
  // REVISIT: below code shouldn't be specific to largedso but apply to other parallel apps
  virtual void InitializeDesktopJobSimulationManager(const PrepareForLargeScaleDSOParams& prms) = 0;
  
  // Notification regarding progress/status
  virtual void NotifyOnStartReadingOfInputFiles() = 0;
  virtual void NotifyOnEndReadingOfInputFiles() = 0;
  
  // The entire job is aborted when below is invoked. E.g. missing main solve license
  virtual void ForceAbortJob() = 0;
  
  virtual void NotifyOnSimulationStart(int numTargetTasks, int startTaskIndex, int endTaskIndex) = 0;
  // Analysis code invokes below before taking up a task
  virtual bool IsTaskHijackedByAnotherEngine(int taskIndex) const = 0;
  virtual void NotifyOnTaskStart(int taskIndex) = 0;
  virtual void NotifyOnTaskCompletion(int taskIndex, bool taskSucceeded) = 0;
  virtual void NotifyOnAllTasksCompletion() = 0;
  // Analysis code invokes below prior to license checkin and exit
  virtual void WaitForExitEvent() = 0;
  
  virtual void NotifyOnStartExtractionOfResultFiles() = 0;
  virtual void NotifyOnEndExtractionOfResultFiles() = 0;

};

#endif
