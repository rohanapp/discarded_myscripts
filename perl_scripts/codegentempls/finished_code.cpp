static void SetEnvironmentVariableNewValue(const AString& envName, const AString& envVal, bool unsetEnv = false)
{
  // REVISIT: existing ngcore code uses "envName=" to unset. But man of LINUX says to use "envName". Going with
  // the nextgen code sample
  AString env_str;
  (unsetEnv == true) ? env_str.Format(ACHAR("%s=", envName.c_str())) :
    env_str.Format(ACHAR("%s=%s", envName.c_str(), envVal.c_str()));

  // NOTE: each env requires it's own buffer! Don't reuse the same buffer for 2 diff envs
  // Don't delete the env buffer in destructor. System takes care of deleting it
  const int kMaxEnvStrBuffer = 512;
  char* bufferForEnvString = new char[kMaxEnvStrBuffer];
  memset(bufferForEnvString, 0, kMaxEnvStrBuffer);
  strcpy(bufferForEnvString, env_str.ASCII().Str());

  ANSOFT_PUTENV(envstring);
}

EnvironmentVariablesContext::EnvironmentVariablesContext(const AString& envName, const AString& envVal)
  : m_isEnvSetOriginally(false)
{
  SS_ASSERT(envName.size());
  SS_ASSERT(envVal.size());

  CLoggingHelper logHelp(ACHAR("EnvironmentVariablesContext::EnvironmentVariablesContext"));
  logHelp.LogParam(ACHAR("envName"), envName);
  logHelp.LogParam(ACHAR("envVal"), envVal);

  m_origEnvName = envName;
  const AChar* envVarOldVal = i18n::ACharGetEnv(envName);
  if (envVarOldVal)
  {
    m_isEnvSetOriginally = true;
    // Make sure to copy it. Putenv releases the original buffer when value is unset
    m_origEnvVal = envVarOldVal;
  }

  SetEnvironmentVariableNewValue(envName, envVal);
}


EnvironmentVariablesContext::~EnvironmentVariablesContext() 
{
  SetEnvironmentVariableNewValue(m_origEnvName, m_origEnvVal, !m_isEnvSetOriginally);

  // Ensure env is actually reset correctly!
  const AChar* currEnvVal = i18n::ACharGetEnv(envName);
  if (!m_isEnvSetOriginally)
  {
    SS_ASSERT(currEnvVal == NULL);
  }
  else
  {
    SS_ASSERT(currEnvVal);
    if (currEnvVal)
      SS_ASSERT(m_origEnvVal == AString(currEnvVal));
  }
  
}
