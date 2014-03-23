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
#ifndef _NGAPPANSOFTCOMMAND_H
#define _NGAPPANSOFTCOMMAND_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "NgAnsoftCOMApp/INgAppCommandCallback.h"
#include "NgAnsoftCOMApp/NgAppCommandDef.h"
#include "ngcore/streamio/block.h"

class NgAppCommandDef;
class ProgressMessageDef;
class NgAppCommandProgress;
class NgAppCommandResult;
class NgAppProgramOptions;
class io::CBlock;


//
// This class encapsulates the entire job. It'll include command parameters that come from command-line option.
// As the command runs, messages/progress/results are managed here. The final status is also included.

class NGANSOFTCOMAPP_API NgAppAnsoftCommand : public INgAppCommandCallback 
{
   
  public:
  
   NgAppAnsoftCommand(const NgAppCommandDef& cmdDef, CommandState state) ;
   ~NgAppAnsoftCommand() ;
  
  // Default handler pushes all below messages to message manager and message handler will take 
  // action (handling might flush the messages to log file or send over the tcp/ip connection)
  // Set isAborted to 'true' to abort command. It is set to false before invoking below methods
  virtual void OnNgAppCommandMessage(const ProgressMessageDef& msg) ;
  virtual void OnNgAppCommandProgress(bool& isAborted, const NgAppCommandProgress& prog) ;
  virtual void OnNgAppCommandResult(const NgAppCommandResult& res) ;
  
  virtual const NgAppCommandDef& GetNgAppCommandDef() const;
  virtual const NgAppProgramOptions& GetNgAppProgramGeneralOptions() ;
  virtual const io::CBlock& GetNgAppCommandParameters() ;
  
  virtual bool IsCommandAbortedByUser() const;
  virtual CommandState GetCommandCurrentState() const;
  
  void SetIsCommandAbortedByUser() ;
  void SetCommandCurrentState(CommandState state) ;
  
  private:
  
  NgAppCommandDef m_cmdDef;
  // Command parameters specific to command
  io::CBlock m_cmdParams;
  INgAppCommandCallback::CommandState m_cmdCurrentState;
  // Command could still be running as it may not be able to handle abort at the
  // time user issues abort command
  bool m_isCommandAbortedByUser;
  

};

#endif
