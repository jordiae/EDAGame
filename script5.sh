#!/bin/bash

./Game SovereignTO Sovereign SovereignTO Sovereign -s $RANDOM -i default.cnf -o default.res 2> >(grep -c "SovereignTO got top score")
