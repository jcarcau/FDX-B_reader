#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: $# <serial_port>"
    exit 1
fi

while [ 1 ]; do
    hexReaderData=`./serial_rfid $1`
    error=$?
    if [[ $error -ne 0 ]]; then
        printf "Leaving...\n"
        exit $error
    fi
    iso=`echo $hexReaderData | awk -F" " '{print $5$6}'`
    end=`echo $hexReaderData | awk -F" " '{print $7$8$9$10$11}'`
    decIso=`printf "%.3d" $((16#$iso))`
    decEnd=`printf "%.12d\n" $((16#$end)) | sed 's/.\{2\}/& /g'`
    entier=`echo $decIso $decEnd`
    echo $entier
done