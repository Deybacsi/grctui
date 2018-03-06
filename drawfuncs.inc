
# first line after the logo
LOGOBOTTOM=5;

SECTION=$(($MAXX / 5));
LEFTAREA_X=0;
LEFTAREA_W=$(($SECTION -1));
MAINAREA_X=$SECTION;
MAINAREA_W=$(($SECTION*2));
RIGHTAREA_X=$(($SECTION*3+1));
RIGHTAREA_W=$(($SECTION*2));

function setcursor {	# ( x, y)
	tput cup $2 $1
}             

function puttext {	# ( x, y, str
	setcursor $1 $2
	echo -n "$3";
}

function drawgrclogo {	# ( x, y)
	i=0;
	for row in "${GRCLOGO[@]}"
	do
		setcursor $1 $(($2+$i))
		echo "$row";
		i=$(($i+1))
	done
}

function drawboinclogo {	# ( x, y)
	i=0;
	for row in "${BOINCLOGO[@]}"
	do
		setcursor $1 $(($2+$i))
		echo "$row";
		i=$(($i+1))
	done
}

function drawline {	# ( x, y, len, char)
	setcursor $1 $2
	for (( i=1; i<=$3; i++ ))
	do
		echo -n "$4";
	done
}

function drawvertline {	# ( x, y, len, char)
	for (( i=1; i<=$3; i++ ))
	do
		setcursor $1 $(($2+$i-1))
		echo -n "$4";
	done
}
