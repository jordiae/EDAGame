#!/bin/bash

./Game Sovereignv12 Sovereignv17 Sovereignv12 Sovereignv17 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv17 got top score")
