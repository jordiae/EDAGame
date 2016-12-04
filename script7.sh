#!/bin/bash

./Game Sovereign Sovereignv9 Sovereign Sovereignv9 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv9 got top score")
