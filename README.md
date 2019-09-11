# CS570-A2
Page Replacement Algorithms

Class information: CS 570, Summer 2017
Neda Heydari, Ole Larsen

FILE MANIFEST:
1) main.cpp
2) pages.txt
3) Scanner.cpp
4) Scanner.h
5) Algorithms/Clock.cpp
6) Algorithms/Clock.h
7) Algorithms/SecondChance.cpp
8) Algorithms/SecondChance.cpp
9) Algorithms/Optimal.cpp
10) Algorithm/Optimal.h


To compile the main.cpp you need to type "g++ main.cpp Scanner.cpp Scanner.h ./Algorithms/SecondChance.cpp ./Algorithms/SecondChance.h ./Algorithms/Clock.cpp ./Algorithms/Clock.h ./Algorithms/Optimal.cpp ./Algorithms/Optimal.h".
This will link the files together and create the a.out file. To run the Makefile you type "make" on the command line.

For this assignment we were to implement three page replacement algorithms. To achieve this we created a separate class for each algorithm. Each algorithm has a run function that calls the methods needed to process the pages passed from main.cpp, and helps determine which page replacement algorithms provide the least amount of page faults.
