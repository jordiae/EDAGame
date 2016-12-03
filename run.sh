#!/bin/bash
rm data.txt
for (( i = 0; i < 10000; i++ )); do
	./script.sh >> data.txt
done
./stats < data.txt