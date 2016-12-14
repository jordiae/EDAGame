#!/bin/bash

./Game Sovereignv12 Sovereign Sovereign Sovereignv12 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv12 got top score")
