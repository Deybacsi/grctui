
function getinfo {
	$GRCCOMMAND getinfo > $GETINFO
}

function getmininginfo {
	$GRCCOMMAND getmininginfo > $GETMININGINFO
}

function getprop {	# ( property, file)
	grep "\"$1\"" $2 | cut -d ":" -f 2 | sed 's/ //; s/"//g; s/,//g'
}


BALANCE=$(getprop "balance" $GETINFO);
STAKE=$(getprop "stake" $GETINFO);
UNCONFIRMED=$(getprop "newmint" $GETINFO);

TOTAL=$(getprop "balance" $GETINFO);

BLOCKS=$(getprop "blocks" $GETINFO);
DIFFICULTY=$(getprop "proof-of-stake" $GETINFO);
NETWEIGHT=$(getprop "netstakeweight" $GETMININGINFO);
COINWEIGHT=$(getprop "combined" $GETMININGINFO);	# it's the goo value?
MAGNITUDE=;
PROJECT=$(getprop "MiningProject" $GETMININGINFO);
CPID=$(getprop "CPID" $GETMININGINFO);
STATUS=$(getprop "MiningInfo 1" $GETMININGINFO);

CURRENTPOLL=$(getprop "MiningInfo 2" $GETMININGINFO);
CLIENTMESSAGES=$(getprop "mining-message" $GETMININGINFO);

