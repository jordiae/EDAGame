#!/bin/bash

./Game Sovereignv22 Sovereignv12 Sovereignv24 Sovereignv23 -s $RANDOM -i default.cnf -o default.res 2> >(grep "got top score")
