#!/bin/bash

./Game Sovereignv21 Sovereignv12 Sovereignv21 Sovereignv12 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv21 got top score")
