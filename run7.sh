#!/bin/bash
rm data7.txt
for (( i = 0; i < 100000; i++ )); do
	./script7.sh >> data7.txt
        ./stats < data7.txt
done
./stats < data7.txt
