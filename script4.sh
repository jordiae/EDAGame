#!/bin/bash

./Game Sovereignv12 Sovereignv18 Sovereignv12 Sovereignv18 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv18 got top score")
