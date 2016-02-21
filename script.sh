#!/bin/bash
EXEC=./out
PATH=ParkingLot/
FILESTART=image\(
FILEEND=\).jpg
#for i in {1..`ls ParkingLot -1 | wc -l`}
end=$(/bin/ls ParkingLot -1 | /usr/bin/wc -l)
for i in `/usr/bin/seq 1 end`
#for file in "$(ls ParkingLot)"
do
	STRFILE=${PATH}${FILESTART}"$i"${FILEEND}
#	strfile= "$file"
# 	printf $file
	printf ${STRFILE}
#	${EXECUTABLE} $(< $file)
#	${EXECUTABLE} $file
done
#mv *.jpg OutputResized/
