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

    # Read or edit. E.g. $size += -s _; #(stat($filePath))[7]
    my ($fname, $fdir, $fextn) = ParseFilePathComponents($currFile);
    return if ($fextn ne ".bat");

    print "Targeting '$currFile' ...\n" if ($gModVerbose);
    # Replace
    #    call (buildproj_release | buildsln_release)
    # With
    #    call buildsln_release64
    foreach (<$currFile>) {
	my $line = $_;
        
    return if ($gPreviewOnly);

  
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
