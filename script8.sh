#!/bin/bash

./Game Sovereignv12 Sovereignv20 Sovereignv12 Sovereignv20 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv20 got top score")
