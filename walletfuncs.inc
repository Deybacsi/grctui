
# get basic infos and put it to file
function getinfo {
	if [[ $1 != "" ]]; then
		echo -en "\r$ANSI_CLRLINE$T_LOADING_WALLET_INFOS";
	fi
	$GRCCOMMAND getinfo > $GETINFO
}

# get mininginfo and put it to file
function getmininginfo {
	if [[ $1 != "" ]]; then
		echo -en "\r$ANSI_CLRLINE$T_LOADING_WALLET_EINFOS";
	fi
	$GRCCOMMAND getmininginfo > $GETMININGINFO
}

# lists all transactions to file
# Returns up to [count] most recent transactions skipping the first [from] transactions
function listtransactions { # count, from, progress
	if [[ $3 != "" ]]; then
		echo -en "\r$ANSI_CLRLINE$T_LOADING_TRANSACTIONS";
	fi
	$GRCCOMMAND listtransactions "" $1 $2 > $LISTTRANSACTIONS
}

# parses a property value from a text file ->  "propertyname" : "value"
function getprop {	# ( propertyname, file)
	grep "\"$1\"" $2 | cut -d ":" -f 2 | sed 's/ //; s/"//g; s/,//g'
}

# puts the details of the transaction list to a .csv
function gettransactiondetails {	
	# if temp csv file exist, then delete the contents
	if [ -f $TRANSACTIONS ]; then
	   > $TRANSACTIONS;
	fi
	# no of our transactions
	TRNO=$(wc -l < $LISTTRANSACTIONS_TXIDS);
	TRACT=1;
	# do the loop
	cat $LISTTRANSACTIONS_TXIDS | while read TXID
	do
		# get the props from transactions based by txids
		$GRCCOMMAND gettransaction $TXID > "$TMPDIR/$TXID";
		TIME=$(getprop "timereceived" "$TMPDIR/$TXID");
		ADDRESS=$(getprop "address" "$TMPDIR/$TXID");
		GENERATED=$(getprop "generated" "$TMPDIR/$TXID");
		CATEGORY=$(getprop "category" "$TMPDIR/$TXID");
		TYPE=$(getprop "Type" "$TMPDIR/$TXID");
		AMOUNT=$(getprop "amount" "$TMPDIR/$TXID" | head -n 1);
		FEE=$(getprop "fee" "$TMPDIR/$TXID" | head -n 1);
		if [[ $FEE == "" ]]; then
			FEE="0";
		fi
		SUM=$(echo $AMOUNT $FEE | awk '{printf "%f", $1 + $2}');
		# put the things to a nicely formatted csv
		echo "$TIME;$ADDRESS;$GENERATED;$CATEGORY;$TYPE;$AMOUNT;$FEE;$SUM;$TXID" >> $TRANSACTIONS;
		# if we have any parameter, then print a fancy progressbar ;´
		if [[ $1 != "" ]]; then
			echo -en "\r$ANSI_CLRLINE$T_LOADING_TRANSACTION_DATA $TRACT / $TRNO ";
			echo -en "["
			for (( I=1; I<=$TRACT; I++ )); do  echo -n "="; done
			for (( I=$TRACT; I<=$TRNO; I++ )); do echo -n "."; done
			echo -en "]";
		fi
		# inc the actual line number counter
		TRACT=$(($TRACT+1));
	done
}





