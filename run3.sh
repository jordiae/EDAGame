#!/bin/bash
rm data3.txt
for (( i = 0; i < 100000; i++ )); do
	./script3.sh >> data3.txt
        ./stats < data3.txt
done
./stats < data3.txt
