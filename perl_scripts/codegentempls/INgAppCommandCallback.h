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
#ifndef _INGAPPCOMMANDCALLBACK_H
#define _INGAPPCOMMANDCALLBACK_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"


class ProgressMessageDef;
class NgAppCommandProgress;
class NgAppCommandResult;
class NgAppCommandDef;
class NgAppProgramOptions;
class io::CBlock;


class NGANSOFTCOMAPP_API INgAppCommandCallback
{
   
  public:
  
  // Command status:
  // kNgAppCommandPreparingToRun -> it's in the process of parsing command lines, setting up env (batchoptions)
  enum CommandState { kNgAppCommandPreparingToRun, kNgAppCommandRunning, kNgAppCommandCompleted_Success,
                      kNgAppCommandCompleted_Failed };
  
  // Default handler pushes all below messages to message manager and message handler will take 
  // action (handling might flush the messages to log file or send over the tcp/ip connection)
  // Set isAborted to 'true' to abort command. It is set to false before invoking below methods
  virtual void OnNgAppCommandMessage(bool& isAborted, const ProgressMessageDef& msg) = 0;
  virtual void OnNgAppCommandProgress(bool& isAborted, const NgAppCommandProgress& prog) = 0;
  virtual void OnNgAppCommandResult(const NgAppCommandResult& res) = 0;
  
  // Use below to obtain command's distribution-level, rank info
  virtual const NgAppCommandDef& GetNgAppCommandDef() const = 0;
  virtual const NgAppProgramOptions& GetNgAppProgramGeneralOptions() = 0;
  // If you didn't cache the command parameter, use the below block to restore 
  // cmd parameters datastructure
  virtual const io::CBlock& GetNgAppCommandParameters() = 0;
  
  virtual CommandState GetCommandCurrentState() const = 0;
  virtual bool IsCommandAbortedByUser() const = 0;
  

};

#endif
