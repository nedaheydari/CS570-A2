/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #2
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class SecondChance{
    public:
        int run(vector<int> pages, int frames);
    private:
        int replace(int page, int frameSize); 
        int fault(int page, int frameSize);
        bool find(int page, int frameSize);    
};