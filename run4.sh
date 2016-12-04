#!/bin/bash
rm data4.txt
for (( i = 0; i < 100000; i++ )); do
	./script4.sh >> data4.txt
        ./stats < data4.txt
done
./stats < data4.txt
