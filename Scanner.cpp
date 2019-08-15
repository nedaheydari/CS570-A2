/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #2
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Scanner.h"
using namespace std;

vector<int> Scanner::readFile(){
    vector<int> pages;
    ifstream readPages("pages.txt");
    if(readPages.is_open()){  
        int i = 0;
        while(readPages >> i) pages.push_back(i);
        readPages.close();
    } else cout << "There was an error while reading the pages" << endl;
    return pages;   
}