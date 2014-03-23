#include "GenericCommandLineOptions.h"

rtype GenericCommandLineOptions::GetName(int i1name, i2type i2name) const
{
  CLoggingHelper logHelp(ACHAR("GetName"));
  logHelp.LogParam(ACHAR("i1name"), i1name);
  logHelp.LogParam(ACHAR("i2name"), i2name);
}

IMessageHandler* GenericCommandLineOptions::GetIMessageHandler() const
{
}

rtype GenericCommandLineOptions::GetPropertyValue(long* i1name, i2type i2name)
{
  CLoggingHelper logHelp(ACHAR("GetPropertyValue"));
  logHelp.LogParam(ACHAR("i1name"), i1name);
  logHelp.LogParam(ACHAR("i2name"), i2name);
}

