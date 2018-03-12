#!/bin/bash

VERSION='v0.3';

MAXX=$(tput cols);
MAXY=$(tput lines);

. ./ascii.inc
. ./config.inc
. ./drawfuncs.inc
. ./languages/texts_en.inc
. ./languages/texts_$LANG.inc
. ./others.inc
. ./walletfuncs.inc


welcomescreen;
echo "$T_LOADING:"
getinfo "progress";
getmininginfo "progress";
listtransactions $LAST_TRANSACTION_NO 0 "progress";

getprop  "txid" $LISTTRANSACTIONS > "$LISTTRANSACTIONS_TXIDS";

gettransactiondetails "progress";

echo -en "\r$ANSI_CLRLINE$T_LOADING_FINISHED\n\n";
echo "If you agree, press any key...";
echo
echo "If not, press CTRL-C";

. ./walletread.inc

read -n1 -s;

echo -e $THEME_TEXT;

trap 'repaint' WINCH

clearscreen;
repaint;
putmaininfos;
puttransactions

COUNTER=0;	
while [[ "$INPUT" != "x" ]]; do
	
	if [[ $COUNTER == $REFRESHINTERVAL ]]; then
		getinfo
		getmininginfo
		listtransactions $LAST_TRANSACTION_NO 0
		# reread the datas
		. ./walletread.inc
		
		repaint

		COUNTER=0;	
	fi

	read -n1 -s -t1 INPUT;
	COUNTER=$(($COUNTER+1));

done

exitgrctui

