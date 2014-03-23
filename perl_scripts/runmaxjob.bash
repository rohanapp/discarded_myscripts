#! /bin/bash

command=("perl $HOME/scripts/maxjob.pl --r=$1 --p=mpi-12 --n=$2 --eng=$2 --mon --a $3")

${command}

exit $?
