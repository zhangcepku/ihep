#!/bin/bash
MODIFY=1
#DSTPATH="/scratchfs/bes/lify/664/mc/etapee/gampipi/pipipi/dst"
DSTPATH="/besfs/groups/nphy/users/lify/mc/664/etapee/etapee3_etapipi"

FILE_TYPR=""

CPWD=$(pwd -P)
OUTFILE=path
test -f $OUTFILE && rm -rf $OUTFILE
cd $DSTPATH
for file in $(ls ${FILE_TYPE}) 
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

