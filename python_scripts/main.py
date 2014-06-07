import sys

import site
site.addsitedir('E:/programs/myscripts/python_scripts/site-packages')

import myutils

# Main function
if __name__ == '__main__':
  
  try:  

    scriptToRun = sys.argv[1]
    scriptModule = __import__(scriptToRun)
    currArgv = sys.argv[1:]
    currArgc = len(sys.argv) - 1

    myutils.InitializeConfig(currArgc, currArgv)
    scriptModule.MainFunction(currArgc, currArgv)

  except Exception as e:
    print "Error: exception caught!"
    print "\nException type is", type(e), ".\n\nDescription:\n", e
    raise
