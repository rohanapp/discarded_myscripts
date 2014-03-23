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
#ifndef _DESKTOPJOBSIMULATIONMANAGER_H
#define _DESKTOPJOBSIMULATIONMANAGER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "NgAnsoftCOMApp/IDesktopJobSimulationManager.h"

class SimAction;
class PrepareForLargeScaleDSOParams;


class NGANSOFTCOMAPP_API DesktopJobSimulationManager : public IDesktopJobSimulationManager 
{
  public:
  
  // Analysis code invokes below before taking up a task
  virtual bool IsTaskUnitStolen(int taskNum) const;
  // Anaysis code waiting for a new task invokes below before fetching the new task
  virtual bool IsNewTaskAvailable(SimAction& nextAction) const;
  // Once below is invoked, the invoking analysis is the new owner of the task
  virtual bool FetchNewTaskAssigned(PrepareForLargeScaleDSOParams& prms, int& newTaskUnit) ;
  
  // Notification regarding progress/status
  virtual void NotifyOnStartReadingOfInputFiles() ;
  virtual void NotifyOnEndReadingOfInputFiles() ;
  
  virtual void NotifyOnStartOfSimulation() ;
  virtual void NotifyOnCompletionOfSimulation() ;
  
  virtual void NotifyOnStartExtractionOfResultFiles() ;
  virtual void NotifyOnEndExtractionOfResultFiles() ;

};

#endif
