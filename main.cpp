/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #1
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include <stdlib.h> // used for atoi
#include <vector>
#include <string>
#include <iostream>

#include "Scanner.h"
#include "./Algorithms/SecondChance.h"
#include "./Algorithms/Clock.h"
#include "./Algorithms/Optimal.h"
using namespace std;


int getFrames(){
    int input;
    cout << "Please enter the number of frames: ";
    cin >> input;
    return input;
}


int main(int argc, char *argv[]){
    int frames = getFrames();

    // create the objects
    Scanner *scan = new Scanner;
    vector<int> pages = scan -> readFile();
  
    SecondChance *secondChance = new SecondChance;
    Clock *clockalgo = new Clock;
    Optimal * optimal = new Optimal;


    int SCFaults = secondChance -> run(pages, frames);
    int clockFaults = clockalgo -> run(pages, frames);
    int optimalFaults = optimal -> run(pages, frames);


    cout << "Optimal faults: " << optimalFaults << endl;
    cout << "Second chance faults: " << SCFaults << endl;
    cout << "Clock faults: " << clockFaults << endl;

    cout << "Done" << endl;
    return 0;
}

