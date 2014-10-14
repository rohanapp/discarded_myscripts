use strict;
use File::Glob;
use Getopt::Long;
use Cwd;
use File::Spec;
use Carp;
use File::Basename; # for fileparse

#----------------------------------------------------------
sub Usage
{
   my $err = shift;
   my $sep = "="x60 . "\n";

   print $sep;
   if ($err) 
   {
      print "= Error: $err\n";
      print $sep;
   }

   print << "EOU__";
= $0 
= Options:
=  -verbose 
=  -clean <performs a clean build>

$sep
EOU__
exit(1);
}

my $gModVerbose = 0;
my $gPreviewOnly = 0;
my $gInitialWorkDir = "";

sub SetVerboseMode { $gModVerbose = $_[0]; }
sub SetPreviewMode { $gPreviewOnly = $_[0]; }

# input: verbose-mode-flag
sub OnApplicationStartup
{
    SetVerboseMode($_[0]);
    SetPreviewMode($_[1]);
    $gInitialWorkDir = getcwd;
}

sub OnApplicationExit
{
    chdir($gInitialWorkDir);
}

sub StartingWorkDir {return $gInitialWorkDir;}

sub PrintIfVerboseMode($)
{
    if ($gModVerbose) {
        print "$_[0]";
    }
}

# UTILITY function
sub ProcessFile
{
  my $fileHandle;
  open($fileHandle, "< $_[0]") or die "Unable to open '$_[0]' for reading";
  my @fileLines = <$fileHandle>;
  my $funcName, my $param1, my $name1, my $param2, my $name2;
  my $doneParsingFunc = 0;
  my $doneParsingFuncFirstPart = 0;
  my $spaces = qr/\s*/;
  my $funcName = qr/STDMETHOD\((\w+)\)\s*/; #funcname
  my $parambegin = qr/\(\s*/;
  my $paramend = qr/\)\s*\;\s*/;
  my $comment = qr/\/\*.+\*\/\s*/;
  my $noModVarDecl = qr/(\w+|\w+\*)\s+(\w+)\s*/; #vartype, varname
  my $varSep = qr/\,\s*/;
  my $funcLine1Pattern = qr/$spaces $funcName $parambegin $comment $noModVarDecl $varSep/x; #funcname,vartype, varname
  my $funcLine2Pattern = qr/$spaces $comment $noModVarDecl $paramend/x;#vartype, varname
  my $oneLineFuncPattern = qr/$spaces $funcName $parambegin $comment $noModVarDecl $paramend/x; #funcname, vartype, varname
  foreach(@fileLines) {
    #print "$_\n";
    if ($_ =~ m/$funcLine1Pattern/g) {
      $funcName = $1;
      $param1 = $2;
      $name1 = $3;
      $param2 = "";
      $doneParsingFunc = 0;
      $doneParsingFuncFirstPart = 1;
    } elsif ($doneParsingFuncFirstPart) {
      $_ =~ m/$funcLine2Pattern/g;
      $param2 = $1;
      $name2 = $2;
      $doneParsingFunc = 1;
      $doneParsingFuncFirstPart = 0;
    } elsif ($_ =~ m/$oneLineFuncPattern/g) {
      $funcName = $1;
      $param1 = $2;
      $name1 = $3;
      $param2 = "";
      $doneParsingFunc = 1;
      $doneParsingFuncFirstPart = 0;
    }

    if ($doneParsingFunc) {
      chomp($funcName);
      chomp($param1);
      chomp($name1);
      chomp($param2);
      chomp($name2);
      print "\n";
      print "//" . "-"x78 . "\n\n";
      if ($param2 ne "") {
        print "STDMETHODIMP CAnsoftDesignerFactory::". $funcName . "($param1 $name1, \n" . " "x45 . "$param2 $name2)\n";
      } else {
        print "STDMETHODIMP CAnsoftDesignerFactory::". $funcName . "($param1 $name1)\n";
      }
      print "{\n";
      print "  LPDISPATCH idisp = 0;\n";
      print "  GetApp(L\"HFSS\", &idisp);\n";
      print "  SS_ASSERT(idisp);\n";
      print "  IHfssAppDLLComInterface* ihfss = dynamic_cast<IHfssAppDLLComInterface*>(idisp);\n";
      if ($param2 ne "") {
        print "  return  ihfss->" . $funcName . "($name1, $name2)" . ";\n";
      } else {
        print "  return  ihfss->" . $funcName . "($name1)" . ";\n";
      }
      print "}\n";
    }
  }
}

# UTILITY function
# Expects absolute path
# returns name, dir, extension. 
# Extension includes "." in the beginning
sub ParseFilePathComponents
{
    return fileparse($_[0], qr/\.[^.]*/);
}

# TEMPLATE FUNCTION
# Purpose: 
#     - For each file in *current* directory, do action
#     - Recursively drills down
# CUSTOMIZE: Edit or read file. (Note: Not inteneded to work in cases requiring deletion or creation of files in visited directories)
#            Edit caller to switch current directory to target directory
sub DoEditOrReadOfFile
{
    my $currFile = $_[0];
    my ($fname, $fdir, $fextn) = ParseFilePathComponents($currFile);
    print "Targeting '$currFile', Extn = '$fextn' ...\n" if ($gModVerbose || $gPreviewOnly);
    return if ($gPreviewOnly);

    # Read or edit. E.g. $size += -s _; #(stat($filePath))[7]
    return if ($fextn != "bat");
}

sub DoActionForFilesInCurrDir
{
    my $dirHandle;
    opendir($dirHandle, ".") or die "Unable to open current directory";
    
    my @dirFiles = readdir($dirHandle) or die "Unable to read directory contents of current directory";
    
    foreach(@dirFiles) {
	next if ($_ eq "." || $_ eq "..");
	my $dirPath = "./$_";
	if (-d $dirPath) {
	    my $currDir = getcwd;
	    chdir($dirPath) or die "Unable to change working directory to '$dirPath'";
	    DoActionForFilesInCurrDir(); 
	    chdir($currDir) or die "Unable to switch back the working directory to '$currDir'";
	} else {
            # CUSTOMIZE
	    DoEditOrReadOfFile($dirPath);
	}
    }
}

MAIN:
{

    my ($verbose, $preview) = (0, 0);
    GetOptions("verbose" => \$verbose, "preview" => \$preview) or Usage("Incorrect command-line");

    OnApplicationStartup($verbose, $preview);

    my $startWorkDir = StartingWorkDir;
    print "Starting workdir is '$startWorkDir'\n";

    DoActionForFilesInCurrDir();

    OnApplicationExit;
}
