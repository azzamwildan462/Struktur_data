cd include
rm Makefile CMakeCache.txt cmake_install.cmake
rm -r CMakeFiles
cmake -S . -B .

cd ../
rm Makefile CMakeCache.txt cmake_install.cmake
rm -r CMakeFiles
cmake -S . -B .