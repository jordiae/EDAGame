#!/bin/bash
rm data.txt
for (( i = 0; i < 100000; i++ )); do
	./script.sh >> data.txt
        ./stats < data.txt
done
./stats < data.txt
