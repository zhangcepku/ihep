#!/bin/bash
MODIFY=1
DSTPATH="/scratchfs/bes/lify/664p03/root/etapee/gampipi/mc/12"

CPWD=$(pwd -P)
OUTFILE=list
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
	sed -i "s%^%chain->Add(\"%g;"  $OUTFILE
	sed -i "s%$%/save\");%g;"  $OUTFILE
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

