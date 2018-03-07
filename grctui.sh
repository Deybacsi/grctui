#!/bin/bash

VERSION='v0.2';

MAXX=$(tput cols);
MAXY=$(tput lines);

. ./ascii.inc
. ./config.inc
. ./drawfuncs.inc
. ./languages/texts_$LANG.inc
. ./others.inc
. ./walletfuncs.inc


getinfo
getmininginfo

. ./walletfuncs.inc
clear;
repaint
putmaininfos

COUNTER=0;	
while [[ "$INPUT" != "x" ]]; do
	
	if [[ $COUNTER == 5 ]]; then
		getinfo
		getmininginfo
		# reread the datas
		. ./walletfuncs.inc
		clear
		repaint
		putmaininfos
		COUNTER=0;	
	fi

	read -n1 -s -t1 INPUT;
	COUNTER=$(($COUNTER+1));

done

>$GETINFO
>$GETMININGINFO
