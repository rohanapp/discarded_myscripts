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
#ifndef _LARGESCALEDSOCOMMANDPROVIDER_H
#define _LARGESCALEDSOCOMMANDPROVIDER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include <vector>
#include "ngcore/stringutils/astring.h"
#include "NgAnsoftCOMApp/INgAppCommandProvider.h"
#include "LargeDSOCommandParams.h"

class io;
class IGeneralOptionSetter;
class AString;
class NgAppProgramOptions;
class io::CBlock;
class INgAppCommandCallback;


class NGANSOFTCOMAPP_API LargeScaleDSOCommandProvider : public INgAppCommandProvider 
{
  
  public:
  
  // Returns dso. User starts desktopjob with commandline -cmd dso
  virtual void GetSupportedNgCommands(std::vector<AString>& cmdUniqueNames) const;
  
  virtual bool ParseCommandLineOptions(io::CBlock& cmdParams, IGeneralOptionSetter* setGenOptions, const AString& cmdName, int argc, char** argv, const NgAppProgramOptions& generalOptions) ;
  
  virtual bool PrepareCommandExecutionEnv(const AString& cmdName, const io::CBlock& cmdParams, const NgAppProgramOptions& generalOptions) ;
  
  virtual bool RunNgCommand(INgAppCommandCallback* icmdCB) ;
  
  private:
  
  LargeDSOCommandParams m_dsoParams;
  

};

#endif
