#!/bin/bash

./Game Sovereignv5 Sovereign Sovereignv5 Sovereign -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv5 got top score")