#!/bin/bash
rm data5.txt
for (( i = 0; i < 100000; i++ )); do
	./script5.sh >> data5.txt
        ./stats < data5.txt
done
./stats < dat5a.txt
