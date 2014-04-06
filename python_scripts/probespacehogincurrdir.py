import sys, subprocess, os, re

def RunPerlScript(scriptName):
  """ This function runs the given perl script and will return
      only after the invoked perl script exits. Returns
      a list: exit code from the invoked process, the captured stdout and stderr
  """
  perlscriptdir = "e:/programs/myscripts/perl_scripts"
  perlscript = perlscriptdir + "/" + scriptName
  proccmdline = ["perl", "-I" + perlscriptdir, perlscript];
  proc1 = subprocess.Popen(proccmdline, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
  proc1ret = proc1.communicate()
  # Insert returncode at the beginning of the list
  retvalList = list(proc1ret)
  retvalList[0:0] = [proc1.returncode]
  return retvalList

def ParseDirDiskUsage(dirLine):
  # Each output line is of the form:
  # <dir-name-with-extension>:         <Size as a floating point number> (mega bytes)
  outputPattern = r'(.+):\s+(.+)\s+\(mega bytes\)'
  match = re.search(outputPattern, dirLine)

  # Ensure that the second value of below tuple is treated as number
  # rather than a string - so that the dictionary in the caller is sorted
  # correctly
  retVal = (None, 0.0, None)

  if match:
    dirname = match.group(1)
    try:
      sizeInMBStr = match.group(2)
      sizeInMB = float(sizeInMBStr)
    except:
      retVal = (None, None, "Invalid size format: " + sizeInMBStr)
    else:
      retVal = (dirname, sizeInMB, None)
  return retVal

def DiskSpaceLeadersInCurrDir(subdirDiskUse, maxDiskUsageVal):
  """
     Return: dict(spaceUsed:dirname), error message string
  """
  # Ignore directories less than 20% of max size
  diskSpaceIgnoreLimitFraction = 0.2
  diskSpaceIgnoreLimit = diskSpaceIgnoreLimitFraction*maxDiskUsageVal

  perlscript = "dirsizesincurrdir.pl"
  [exitCode, procout, procerr] = RunPerlScript(perlscript)
  if (exitCode):
    procerr += "\nError: some failures in computing space taken by: "
    procerr += os.path.realpath(os.getcwd())
  
  dirLines = procout.split('\n')
  for dirLine in dirLines:
    (dirname, diskUsageVal, errStr) = ParseDirDiskUsage(dirLine)
    if (dirname == None):
      if (errStr):
        procerr += errStr
      continue;
    if (diskUsageVal < diskSpaceIgnoreLimit):
      continue
    if (diskUsageVal > maxDiskUsageVal):
      maxDiskUsageVal = diskUsageVal
      diskSpaceIgnoreLimit = diskSpaceIgnoreLimitFraction*maxDiskUsageVal
    subdirDiskUse[os.path.realpath(dirname)] = diskUsageVal

  if (len(subdirDiskUse) <= 0):
    return

  subdirList = subdirDiskUse.keys()
  for dirName in subdirList:
    duVal = subdirDiskUse[dirName]
    currdir = os.getcwd()
    try:
      os.chdir(dirName)
      tempSubdirDiskUse = {}
      localErrors = DiskSpaceLeadersInCurrDir(tempSubdirDiskUse, maxDiskUsageVal)
      subdirDiskUse.update(tempSubdirDiskUse)
      if (localErrors and len(localErrors)):
        procerr += "\n"
        procerr += localErrors
    except:
      raise
    finally:
      os.chdir(currdir)
    
  return procerr

# Main function
if __name__ == '__main__':
  try:  
    subdirDiskUse = {}
    errstrs = DiskSpaceLeadersInCurrDir(subdirDiskUse, 0)

    duSubdirsMap = {}
    for dirName, duVal in subdirDiskUse.iteritems():
      duSubdirsMap[duVal] = dirName

    print "\n\n\n"
    for duVal, dirName in duSubdirsMap.iteritems():
      print duVal, "(MB)", "-"*10 + ">", dirName
    print "\n\n\n"

  except Exception as e:
    print "Error: exception caught!"
    print "\nException type is", type(e), ".\n\nDescription:\n", e
    raise

  if(len(errstrs)):
    print "Errors occurred!\n", errstrs
