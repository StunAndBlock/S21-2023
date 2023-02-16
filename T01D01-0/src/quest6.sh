#!/bin/bash

cd ai_help
chmod +x keygen.sh
./keygen.sh

cd key
for var in {1..300}
do
rm file$var
done

cd ..
chmod +x unifier.sh
./unifier.sh