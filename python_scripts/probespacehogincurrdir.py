import os, re

import myutils

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

def PrintDiskSpaceUsageInCurrDir(subdirDiskUse, maxDiskUsageVal):
  """
     Return: dict(spaceUsed:dirname), error message string
  """
  # Ignore directories less than 20% of max size
  diskSpaceIgnoreLimitFraction = 0.2
  diskSpaceIgnoreLimit = diskSpaceIgnoreLimitFraction*maxDiskUsageVal

  perlscript = "dirsizesincurrdir.pl"
  [exitCode, procout, procerr] = myutils.RunPerlScript(perlscript)
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
      localErrors = PrintDiskSpaceUsageInCurrDir(tempSubdirDiskUse, maxDiskUsageVal)
      subdirDiskUse.update(tempSubdirDiskUse)
      if (localErrors and len(localErrors)):
        procerr += "\n"
        procerr += localErrors
    except:
      raise
    finally:
      os.chdir(currdir)
    
  return procerr

# Function invoked from main.py
def MainFunction(argc, argv):
  subdirDiskUse = {}
  errstrs = PrintDiskSpaceUsageInCurrDir(subdirDiskUse, 0)

  duSubdirsMap = {}
  for dirName, duVal in subdirDiskUse.iteritems():
    duSubdirsMap[duVal] = dirName

  print "\n\n\n"
  for duVal in sorted(duSubdirsMap.keys()):
    dirName = duSubdirsMap[duVal]
    print duVal, "(MB)", "-"*10 + ">", dirName
  print "\n\n\n"

  if(len(errstrs)):
    print "Errors occurred!\n", errstrs
