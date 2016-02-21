#!/bin/bash
EXEC=./out
PATH=ParkingLot/
FILESTART=images
FILEEND=.jpg

#for i in {1..`ls ParkingLot -1 | wc -l`}
END=$(/bin/ls ParkingLot -1 | /usr/bin/wc -l)
INT_END=${END%.*}
#for i in `/usr/bin/seq 1 INT_END`
for i in `/usr/bin/seq 1 28`
#for file in `/bin/ls ${PATH}`
do
	STRFILE=${PATH}${FILESTART}"$i"${FILEEND}
#	printf $STRFILE
#	strfile=${PATH}/$file
# 	printf $file
# 	printf $strfile
#	printf ${STRFILE}
#	${EXECUTABLE} $(< $file)
	${EXECUTABLE} $STRFILE
done
/bin/mv *.jpg OutputResized/
