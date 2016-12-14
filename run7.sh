#!/bin/bash
rm data.txt
for (( i = 0; i < 100000; i++ )); do
	./script7.sh >> data.txt
    ./stats_complex < data.txt
done
