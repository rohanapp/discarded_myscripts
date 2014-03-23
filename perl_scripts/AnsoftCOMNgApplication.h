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
#ifndef _ANSOFTCOMNGAPPLICATION_H
#define _ANSOFTCOMNGAPPLICATION_H

#include "ngcore/common/portab.h"
#include "ngcore/ngutils/assert.hxx"

#include "AnsoftCOM/AnsoftCOMApplication.h"
#include "CoreInterfaces/IMessageHandler.h"
#include "wbintegutils/ApplicationStartupParams.h"

class BoostProgramOptionsDesc;
class AnsoftMessage;
class AnsoftCommandContext;
class AString;
class IMessageHandler;
class IMessageManager;


// Application object for ng applications. Supports the following functionality:
// - Initialize/finalize AnsoftCOM
// 
// - Provides a per-thread message-manager
// 
// - Provide a message-handler that flushes messages to specified logfile
// 
// - Supports standard command-line parsing: -help -env "name=val", -debugmode "num:logfolder" -logfile file.
//   Supports parsing of custom command-lines - custom parsing specified through Initialize method
//
// - Keeps around working dir of app when it started and app's location
// 
// - Provide reasonable default implementation for all IAnsoftApplication methods. Notable: tempdir, installdir, 
//   versioned-product-exe-name (to enable usage of registryaccessng), exedir
//   Provides additional methods such as machine-name as exactly specified in ansoftcom config file
//
// - Tempdir: can be overridden through batchoptions and the value used is as per file-based registry
// 
// - Provide IsAlive infrastructure: 
// - Dependencies: uicore (for file-based registry. Needed??)
// 
// - Uses: reads productlist.txt from the installation folder that has product name, version


// my $classMatchStr = "^class\\s+(.+)\\s*:\\s*(.+)\\s*{";
// my $classParentsMatchStr = "\\s*(.+?)\\s*(|,)";
// my $classParents = "AnsoftCOMApplication, IMessageHandler";
// my @parentClasses = split(/\s*,\s*/, $classParents); // strip whitespace
class AnsoftCOMNgApplication : public AnsoftCOMApplication, public IMessageHandler {
  
  public:
  
  typedef boost::program_options::options_description BoostProgramOptionsDesc;
  
  
  // my $lineStr = "Constructor(){}";
  // if ($lineStr =~ m/constructor/i) { print "matches\n"; }
   AnsoftCOMNgApplication() ;
  
  // my $lineStr = "bool InitializeApplication(int argc, char** argv) {}";
  // my $methodPartsMatchStr = "(.+)\\((.+)\\)(.+)";
  // "bool InitializeApplication(int argc, char** argv) {}" =~ m/$methodPartsMatchStr/;
  // my $methodNameReturnPart = $1, my $methodArgsPart, my $methodModifiersBodyPart = $3;
  // my $anchorNameLeadPartMatchStr = "\\s*(.+)\\s+(\\w+)\\s*\$"; // This is a general split of string into anchor-name and leading-part
  // my $matchBodyStrGivenModifiersBody = "{(.*)}"; "const = 0 {}" =~ m/$matchBodyStrGivenModifiersBody/; print "$1;\n";
  bool InitializeApplication(int argc, char** argv) ;
  virtual bool GetCustomCommandLineOptions(BoostProgramOptionsDesc& genericOptions, BoostProgramOptionsDesc& configFileOptions, BoostProgramOptionsDesc& hiddenOptions) const;
  
  // Implementation for IMessageHandler 
  virtual bool ClearQMessages(const int remainingMsg) ;
  virtual AnsoftMessage* GetNextMessage() ;
  virtual int GetNumMessages() const;
  virtual int GetNumMessages(MessageSeverity severity) const;
  // 
  virtual bool HandleMessages(const AnsoftCommandContext* context) ;
  virtual int ShowQueuedMessages(UINT type, bool flushToMsgWnd, const AnsoftCommandContext* context, const AString& sQuestion) ;
  virtual int AnsoftMessageBox(const AString& message, UINT type, UINT nHelpID, bool bExitIfLogging) ;
  virtual int AnsoftMessageBox(const AnsoftMessage& message, UINT type, UINT nHelpID, bool bExitIfLogging) ;
  
  IMessageHandler* GetIMessageHandler() ;
  // Return a message manager that is unique for each thread
  IMessageManager* GetIMessageManager() ;
  
  private:
  
  CApplicationStartupParams m_appStartupParams;
  

};

#endif
