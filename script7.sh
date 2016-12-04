#!/bin/bash

./Game SovereignX Sovereignv9 SovereignX Sovereignv9 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "SovereignX got top score")
