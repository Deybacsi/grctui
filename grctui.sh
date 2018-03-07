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



clear;
echo "This is only a rudimentary version, under development.";
echo "It can be slow, and shit. It can miss some functions what you need.";
echo "It comes 'as is', without any warranty.";
echo
echo "If you agree, press any key...";
echo
echo "If not, press CTRL-C";

getinfo
getmininginfo

. ./walletfuncs.inc

read -n1 -s;

clearscreen;
repaint;
putmaininfos;

COUNTER=0;	
while [[ "$INPUT" != "x" ]]; do
	
	if [[ $COUNTER == $REFRESHINTERVAL ]]; then
		getinfo
		getmininginfo
		# reread the datas
		. ./walletfuncs.inc
		clearscreen
		repaint
		putmaininfos
		COUNTER=0;	
	fi

	read -n1 -s -t1 INPUT;
	COUNTER=$(($COUNTER+1));

done

exitgrctui

