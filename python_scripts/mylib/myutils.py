import sys, subprocess, os, re

gConfigVars = {}

def InitializeConfig(argc, argv):
  configFilePath = "E:/programs/myscripts/config.cmd"
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

def GetConfigVal(name):
  return gConfigVars[name]

def HandleProgramOutput(progCommandLine, progRet):
  """ This function expects program output as 
      a list: exit code from the invoked process, the captured stdout and stderr
  """
  exitCode = progRet[0]
  procout = progRet[1]
  procerr = progRet[2]
  if (exitCode):
    print >>sys.stderr, "Error in the execution of program:", progCommandLine, "Exit code = ", exitCode
  if(len(procerr)):
    print >>sys.stderr, "Error messages from program:\n", procerr
  if(len(procout)):
    print "Info messages from program:\n", procout

def RunProgramCaptureAll(progCommandLine, handleOutput = False):
  """ This function runs the given program and will return
      only after it exits. Returns
      a list: exit code from the invoked process, the captured stdout and stderr
  """
  proc1 = subprocess.Popen(progCommandLine, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  proc1ret = proc1.communicate()
  # Insert returncode at the beginning of the list
  retvalList = list(proc1ret)
  retvalList[0:0] = [proc1.returncode]
  if (handleOutput):
    HandleProgramOutput(progCommandLine, retvalList)
  return retvalList

def RunPerlScript(scriptName, handleOutput = False):
  """ This function runs the given perl script and will return
      only after the invoked perl script exits. Returns
      a list: exit code from the invoked process, the captured stdout and stderr
  """
  perlscriptdir = "e:/programs/myscripts/perl_scripts"
  perlscript = perlscriptdir + "/" + scriptName
  proccmdline = ["perl", "-I" + perlscriptdir, perlscript];
  return RunProgramCaptureAll(proccmdline, handleOutput)
  return retvalList

