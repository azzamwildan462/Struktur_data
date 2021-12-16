#!/usr/bin/bash

cd obj
echo "Compiling.."
# g++ ../src/db.cpp ../src/ui.cpp ../src/executor.cpp ../src/main.cpp -c 
g++ ../src/db.cpp -c 
echo "25% complete.."
g++ ../src/ui.cpp -c 
echo "50% complete.."
g++ ../src/executor.cpp -c
echo "75% complete.. "
g++ ../src/main.cpp -c 
echo "100% complete.."
echo "Finishing.."

# g++ db.o ui.o main.o -o EAS 
g++ db.o ui.o executor.o main.o -o EAS -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
echo "Done 100%"

#THIS IS DEPRECATED!!!
