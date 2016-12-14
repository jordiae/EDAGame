#!/bin/bash
rm data8.txt
for (( i = 0; i < 100000; i++ )); do
	./script8.sh >> data8.txt
        ./stats < data8.txt
done
./stats < data8.txt
