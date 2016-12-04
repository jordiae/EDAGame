#!/bin/bash

./Game Joan2 Sovereignv6 Joan2 Joan2 -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "Sovereignv6 got top score")
