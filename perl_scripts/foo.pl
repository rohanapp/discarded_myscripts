use strict;
use lib "..\\Lib";
use Cwd;
use Getopt::Long;
use GlobUtils;
use Win32::Clipboard;

#----------------------------------------------------------
sub usage
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
=  -pids 23,34 (comma-separated process IDs)
=  -interval 1 (specify in seconds)

$sep
EOU__
exit(1);
}

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

MAIN:
{
    my $inputFileName;
    my $verbose = 0;

    GetOptions("verbose" => \$verbose, "inputfile=s" => \$inputFileName) or 
	die usage("Incorrect Usage:");

    SetVerboseMode($verbose);

    die "'$inputFileName' does not exist!" unless (-e $inputFileName);
    my $initialWorkFile = getcwd;


    ProcessFile($inputFileName);
}

