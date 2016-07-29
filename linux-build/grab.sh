#!/bin/bash


#get file path
ldd ./YouTube-Player | cut -f2 -d '>' | cut -f1 -d '(' > test

while read -r line || [[ -n "$line" ]]; 
do
	if [ -f $line ]
	then
		cp $line ./lib/				
		
	fi    
	
done < "test"
