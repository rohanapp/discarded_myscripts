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
#ifndef _WINDOWSAPPCRASHLOGGER_H
#define _WINDOWSAPPCRASHLOGGER_H

#include "NgAnsoftCOMApp.h"
#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"
#include "ngcore/common/PlatformSpecifics_C++.h"

#include "ngcore/stringutils/astring.h"

class AString;


// 
// Purpose: 
// Represents the state of crashing application as a streamio_block object convenient for IO.
// Contains state so as to help with debugging this crash.
//
// Inputs: Directory that holds crash logs
// Output: A unique file in the crash-log directory named as crashlog_<pid>_#.txt
// 
class NGANSOFTCOMAPP_API WindowsAppCrashLogger
{
   
  public:
  
   WindowsAppCrashLogger(const AString& logFileDirPath) ;
   ~WindowsAppCrashLogger() ;
  
  
  void DumpCrashLog() ;
  
  private:
  
  AString m_logFilesDir;
  

};

#endif
