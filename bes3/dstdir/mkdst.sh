#!/bin/bash
MODIFY=1
#DSTPATH="/scratchfs/bes/lify/664/mc/etapee/gampipi/pipipi/dst"
#DSTPATH="/scratchfs/bes/lify/664p03/mc/etapee/gampipi/gametap/dst"
DSTPATH="/scratchfs/bes/lify/664/mc/etapee/gampipi/gampipiee/dst"

CPWD=$(pwd -P)
OUTFILE=path
test -f $OUTFILE && rm -rf $OUTFILE
cd $DSTPATH
for file in $(ls)
do
#	echo $file
	if [ -f $file ];then
		echo $DSTPATH/$file >> $CPWD/$OUTFILE
	fi
done
cd $CPWD
if [ $MODIFY -eq 1 ] ;then
	sed -i "s%^%\"%g;"  $OUTFILE
	sed -i "s%$%\"%g;"  $OUTFILE
fi
cd $CPWD
#for dir in $(ls)
#do
#	echo $dir
#	if [ -d $dir ];then
#		cd $dir 
#		for file in $(ls)
#		do
#			echo $DSTPATH/$dir/$file >> $CPWD/pipiee.txt
#		done
#		cd ..
#	fi
#done
