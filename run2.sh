#!/bin/bash
rm data2.txt
for (( i = 0; i < 100000; i++ )); do
	./script2.sh >> data2.txt
        ./stats < data2.txt
done
./stats < data2.txt
