#include "headers.h"
#include "NgAppCommandDef.h"
#include "ngcore/ngutils/ans_debug.h"
#include "CoreInterfaces/IMessageManager.h"
#include "ngcore/messagelibni/AnsoftMessage.h"
#include "ngcore/streamio/block.h"


 NgAppCommandDef::NgAppCommandDef() 
{
  SS_ASSERT(!ACHAR(""));
}


 NgAppCommandDef::~NgAppCommandDef() 
{
}


io::ReadError NgAppCommandDef::DoDataExchange(io::CBlock& block, bool do_read) 
{
}


AString NgAppCommandDef::GetItemName() const
{
}
