#!/bin/bash

./Game Sovereign Sovereignv6 Sovereign Sovereignv6 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv6 got top score")
