
# first line after the logo
LOGOBOTTOM=5;

SECTION=$(($MAXX / 5));
LEFTAREA_X=0;
LEFTAREA_W=$(($SECTION -1));
MAINAREA_X=$SECTION;
MAINAREA_W=$(($SECTION*2));
RIGHTAREA_X=$(($SECTION*3+1));
RIGHTAREA_W=$(($SECTION*2));

function clearscreen {
	echo -en "\033[2J";
}

function setcursor {	# ( x, y)
	# tput cup $2 $1
	echo -en "\033[$(($2+1));$(($1+1))H";	
}             

# print text to x,y
function puttext {	# ( x, y, str
	setcursor $1 $2
	echo -n "$3";
}

# draw the grc logo
function drawgrclogo {	# ( x, y)
	i=0;
	for row in "${GRCLOGO[@]}"
	do
		setcursor $1 $(($2+$i))
		echo "$row";
		i=$(($i+1))
	done
	puttext $(($1+${#GRCLOGO})) $(($2+$i-1)) $VERSION;
}

# draw the glorious Boinc logo
function drawboinclogo {	# ( x, y)
	i=0;
	for row in "${BOINCLOGO[@]}"
	do
		setcursor $1 $(($2+$i))
		echo "$row";
		i=$(($i+1))
	done
}

# draw a horizontal line to x,y len length with char
function drawline {	# ( x, y, len, char)
	setcursor $1 $2
	for (( i=1; i<=$3; i++ ))
	do
		echo -n "$4";
	done
}

# draw a vertical line to x,y height height with char
function drawvertline {	# ( x, y, height, char)
	for (( i=1; i<=$3; i++ ))
	do
		setcursor $1 $(($2+$i-1))
		echo -n "$4";
	done
}

# draw the header - grc+boinc logo + separator line
function drawheader {
	drawgrclogo 0 0
	drawboinclogo $(($MAXX-${#BOINCLOGO})) 0
	drawline 0 4 $(($MAXX-${#BOINCLOGO})) '_'
	puttext $((${#GRCLOGO}+7)) $(($LOGOBOTTOM-2)) "x - Exit";
}

# redraw the screen - header + separators
function repaint {
	drawheader
	drawvertline $(($MAINAREA_X-1)) $LOGOBOTTOM $(($MAXY-$LOGOBOTTOM)) '|'
	drawvertline $(($RIGHTAREA_X-1)) $LOGOBOTTOM $(($MAXY-$LOGOBOTTOM)) '|'
}

# print the datas to main area
function putmaininfos {
	puttext $(($MAINAREA_X+1)) $(($LOGOBOTTOM+1)) "$T_BALANCE: " ;    puttext $(($MAINAREA_X+18)) $(($LOGOBOTTOM+1)) "$BALANCE"
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
}
