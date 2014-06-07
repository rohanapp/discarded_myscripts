import os, subprocess, myutils

def UninstallUnifiedInstallation(installPath):
  # print "UninstallUnifiedInstallation", installPath
  uninstallCmdLine = ['call', installPath + "\\Uninstall.exe", "-silent", "-keepAppData"]
  progRet = myutils.RunProgramCaptureAll(uninstallCmdLine, handleOutput = True)
  return

def InstallUnifiedInstallation(installPath):
  ansysDownloadDir = os.path.realpath(myutils.GetConfigVal("artifact_download_dir"))
  # REVISIT: path-separators are hardcoded to Windows platform
  setupExe = ansysDownloadDir + "\\v160_Certified\\winx64\setup.exe"
  installCmdLine = [setupExe, "-silent", "-nohelp", "-noprereqs", "-install_dir", installPath]
  progRet = myutils.RunProgramCaptureAll(installCmdLine, handleOutput = True)
  # print "InstallUnifiedInstallation", installCmdLine
  return

def ExtractDevelopmentFramework(installPath):
  print "!!!!!ExtractDevelopmentFramework is NOT YET IMPLEMENTED", installPath
  return

def MainFunction(argc, argv):
  installPath = os.environ.get('AWP_ROOT151')
  if installPath and os.path.exists(installPath):
    UninstallUnifiedInstallation(installPath)

  installPath = "E:/Program Files/ANSYS Inc"

  installPath = os.path.realpath(installPath)    
  InstallUnifiedInstallation(installPath)
  ExtractDevelopmentFramework(installPath)
