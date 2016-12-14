#!/bin/bash

./Game Sovereignv24 Sovereignv12 Sovereignv12 Sovereignv12 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv24 got top score")
