#!/bin/bash

./Game Joan2 Sovereign Joan2 Joan2 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereign got top score")
