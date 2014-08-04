import os, subprocess, myutils

def UninstallUnifiedInstallation(installPath):
  print "UninstallUnifiedInstallation", installPath
  uninstallCmd = installPath + "\\Uninstall.exe"
  if os.path.exists(uninstallCmd):
    uninstallCmdLine = ['call', uninstallCmd, "-silent", "-keepAppData"]
    progRet = myutils.RunProgramCaptureAll(uninstallCmdLine, handleOutput = True)
  return

def InstallUnifiedInstallation(installPath):
  ansysDownloadDir = os.path.realpath(myutils.GetConfigVal("artifact_download_dir"))
  # REVISIT: path-separators are hardcoded to Windows platform
  setupExe = ansysDownloadDir + "\\v160_Certified\\winx64\setup.exe"
  installCmdLine = [setupExe, "-silent", "-nohelp", "-noprereqs", "-install_dir", installPath]
  print "InstallUnifiedInstallation", installCmdLine
  progRet = myutils.RunProgramCaptureAll(installCmdLine, handleOutput = True)
  return

def ExtractDevelopmentFramework(installPath):
  print "!!!!!ExtractDevelopmentFramework is NOT YET IMPLEMENTED", installPath
  return

def MainFunction(argc, argv):
  installPath = myutils.GetConfigVal("install_path")
  installPath = os.path.realpath(installPath)
  # installPath = os.environ.get('AWP_ROOT151')
  if installPath and os.path.exists(installPath):
    UninstallUnifiedInstallation(installPath)

  InstallUnifiedInstallation(installPath)
  ExtractDevelopmentFramework(installPath)
