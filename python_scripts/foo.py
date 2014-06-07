import os, sys, re
import myutils

gConfigVars = {}

def InitializeConfig(argc, argv):
  configFilePath = "../config.cmd"
  if not os.path.exists(configFilePath):
    print >>sys.stderr, configFilePath, "does not exist!\n"
    return

  configFile = open(configFilePath, "r")
  fileContents = configFile.read()
  fileLines = fileContents.split("\n")
  for configLine in fileLines:
    configLineMatchPattern = r'set\s+(\w+)=(.+)'
    match = re.search(configLineMatchPattern, configLine)
    if match:
      gConfigVars[match.group(1)] = match.group(2)
    else:
      # Ignore empty lines or the ones that start with REM, etc. 
      pass

  configFile.close()

def MainFunction(argc, argv):
  InitializeConfig(argc, argv)
  print gConfigVars
