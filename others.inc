function welcomescreen {
	clear;
	echo "This is only a rudimentary version, under development.";
	echo "It can be slow, and shit. It can miss some functions what you need.";
	echo "It comes 'as is', without any warranty.";
	echo
}


function exitgrctui {
	clear;
	echo "Thanks for using GrcTUI $VERSION";
	echo "----------------------------";
	echo "Please visit https://github.com/Deybacsi/grctui for updates";
	echo
	rm -rf ./tmp/*
	rm -rf ./tmp/*.*
}
