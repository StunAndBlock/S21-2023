#!/bin/bash

mv door_management_fi door_management_files
cd door_management_files
mkdir door_configuration
mkdir door_logs
mkdir door_map

for var in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
do
mv door_$var.conf door_configuration
done

mv door_21.conf door_configuration

for var in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
do
mv door_$var.log door_logs
done

mv door_map_1.1 door_map