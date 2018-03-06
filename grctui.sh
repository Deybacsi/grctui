#!/bin/bash

MAXX=$(tput cols);
MAXY=$(tput lines);

echo $MAXX*$MAXY;


. ./ascii.inc
. ./config.inc
. ./drawfuncs.inc
. ./languages/texts_$LANG.inc


clear;
drawgrclogo 5 0
drawboinclogo $(($MAXX-${#BOINCLOGO})) 0
drawline 0 4 $(($MAXX-${#BOINCLOGO})) '_'

drawvertline $(($MAINAREA_X-1)) $LOGOBOTTOM $(($MAXY-$LOGOBOTTOM)) '|'
drawvertline $(($RIGHTAREA_X-1)) $LOGOBOTTOM $(($MAXY-$LOGOBOTTOM)) '|'


BALANCE='100000.123456';
STAKE='1000.4567';
UNCONFIRMED='500.1234';

TOTAL='11500.12345';

BLOCKS='1189123';
DIFFICULTY='1.652234';
NETWEIGHT='12345123';
COINWEIGHT='13453';
MAGNITUDE='5.0';
PROJECT='Seti@Home';
CPID='xxxyxyxyxyxxyxyxy';
STATUS='Mining';

CURRENTPOLL='Current poll';
CLIENTMESSAGES='Client Messages';


puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+1)) "$T_BALANCE: " ;    puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+1)) "$BALANCE GRC"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+2)) "$T_STAKE: "   ;    puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+2)) "$STAKE"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+3)) "$T_UNCONFIRMED: "; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+3)) "$UNCONFIRMED"

puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+5)) "$T_TOTAL: "      ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+5)) "$TOTAL"

puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+7)) "$T_BLOCKS: "     ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+7)) "$BLOCKS"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+8)) "$T_DIFFICULTY: " ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+8)) "$DIFFICULTY"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+9)) "$T_NETWEIGHT: "  ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+9)) "$NETWEIGHT"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+10)) "$T_COINWEIGHT: "; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+10)) "$COINWEIGHT"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+11)) "$T_MAGNITUDE: " ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+11)) "$MAGNITUDE"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+12)) "$T_PROJECT: "   ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+12)) "$PROJECT"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+13)) "$T_CPID: "      ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+13)) "$CPID"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+14)) "$T_STATUS: "    ; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+14)) "$STATUS"

puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+16)) "$T_CURRENTPOLL: "; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+16)) "$CURRENTPOLL"
puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+18)) "$T_CLIENTMESSAGES: "; puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+18)) "$CLIENTMESSAGES"

read -n1 -s
