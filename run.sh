g++ -std=c++17 -O2 -Wall -o o.o $1
./o.o <input >output
vimdiff output stdput
