#!/bin/bash
EXEC=./out
PATH=ParkingLot/
#FILESTART=image\(
#FILEEND=\).jpg

#for i in {1..`ls ParkingLot -1 | wc -l`}
#end=$(/bin/ls ParkingLot -1 | /usr/bin/wc -l)
#for i in `/usr/bin/seq 1 end`
for file in `/bin/ls ${PATH}`
do
#	STRFILE=${PATH}${FILESTART}"$i"${FILEEND}
	strfile=${PATH}$file
# 	printf $file
# 	printf $strfile
#	printf ${STRFILE}
#	${EXECUTABLE} $(< $file)
	${EXECUTABLE} $strfile
done
#mv *.jpg OutputResized/
