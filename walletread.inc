# read the datas for main view

BALANCE=$(getprop "balance" $GETINFO);
STAKE=$(getprop "stake" $GETINFO);
UNCONFIRMED=$(getprop "newmint" $GETINFO);

TOTAL=$(getprop "balance" $GETINFO);

BLOCKS=$(getprop "blocks" $GETINFO);
DIFFICULTY=$(getprop "proof-of-stake" $GETINFO);
NETWEIGHT=$(getprop "netstakeweight" $GETMININGINFO);
COINWEIGHT=$(getprop "combined" $GETMININGINFO);	# is it the good value?
MAGNITUDE=;
PROJECT=$(getprop "MiningProject" $GETMININGINFO);
CPID=$(getprop "CPID" $GETMININGINFO);
STATUS=$(getprop "MiningInfo 1" $GETMININGINFO);

CURRENTPOLL=$(getprop "MiningInfo 2" $GETMININGINFO);
CLIENTMESSAGES=$(getprop "mining-message" $GETMININGINFO);
