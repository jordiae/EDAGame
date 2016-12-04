#!/bin/bash

./Game Sovereignv6 Sovereign Sovereignv6 Sovereign -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv6 got top score")
