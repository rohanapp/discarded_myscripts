use strict;
use Cwd;
use Getopt::Long;
use File::Basename;

my $gVerbose = 0;

my $gSystemCommand = "";

sub PrintIfVerbose
{
    if ($gVerbose) {
	print("$_[0] $_[1]\n");
    }
}

sub RunSystemCommandInCurrDir
{
    die "System command must be specified" if $gSystemCommand eq "";

    my $runStatus = system($gSystemCommand);
    if ($runStatus != 0) {
	print "Error occurred in running the command. Status is '$runStatus'\n";
    }
}

MAIN:
{
    GetOptions("verbose" => \$gVerbose) or 
	die usage("Incorrect Usage:");

    my $initialWorkDir = getcwd;

    my $perlScriptsDir = dirname(__FILE__);
    $gSystemCommand = "perl $perlScriptsDir/dofordir.pl -cmd \"perl $perlScriptsDir/currentdirsize.pl\"";
    print("Running command '$gSystemCommand'...\n");

    chdir($initialWorkDir);
    RunSystemCommandInCurrDir();

    exit(0);
}
