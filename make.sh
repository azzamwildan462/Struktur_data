#!/usr/bin/bash

cd obj
g++ ../src/db.cpp -c 
g++ ../src/ui.cpp -c 
g++ ../src/main.cpp -c 

g++ db.o ui.o main.o -o EAS 
