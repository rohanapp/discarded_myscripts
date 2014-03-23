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
#ifndef _INGAPPCOMMANDPROVIDER_H
#define _INGAPPCOMMANDPROVIDER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include <vector>
#include "ngcore/stringutils/astring.h"

class io::CBlock;
class IGeneralOptionSetter;
class AString;
class NgAppProgramOptions;
class NgAppCommandDef;
class INgAppCommandCallback;


class NGANSOFTCOMAPP_API INgAppCommandProvider
{
  
  public:
  
  // One provider can support multiple commands. So return all commands for which you have the algorithms.
  virtual void GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const = 0;
  
  // For the given command, parse the command line parameters. The cmdline parsed by the framework
  // is supplied in the cmdLine argument.
  // The subset of the command-line option that are not interpreted by NgApp are passed as argc/argv. So
  // it is an error if there are unidentified arguments or if arguments are invalid
  // Output on success: block representing command line
  virtual bool ParseCommandLineOptions(io::CBlock& cmdParams, IGeneralOptionSetter* setGenOptions, const AString& cmdName, int argc, char** argv, const NgAppProgramOptions& generalOptions) = 0;
  
  // At this stage, NgApp is done parsing command lines. 
  // NgApp and command provider setup environment and do any other preparation to kickoff the job
  // NOTE: objective is to kickoff the job quickly (so the distributed compute resources get utilized sooner than later)
  // and so perform only activities that must be done before distributed resources can be utilized
  // Time spent here is logged
  // cmdDef is needed to find out the distribution level. Such info is needed as preparation is different at
  // different levels
  virtual bool PrepareCommandExecutionEnv(const NgAppCommandDef& cmdDef, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions) = 0;
  
  // Now run the command using the information collected from command-line options, etc.
  virtual bool RunNgCommand(INgAppCommandCallback* icmdCB) = 0;
  

};

#endif
