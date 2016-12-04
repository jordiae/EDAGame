#!/bin/bash
rm data6.txt
for (( i = 0; i < 100000; i++ )); do
	./script6.sh >> data6.txt
        ./stats < data6.txt
done
./stats < data6.txt
