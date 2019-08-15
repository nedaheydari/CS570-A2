/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #2
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include "Clock.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int fullClock = 0; // to check if the frame is full or not
vector<int> frameClock;
vector<int> referenceBitsClock;

int Clock::replace(int page, int frameSize){
    int temp;
    int bitCheck = 0; // To enter the referenceBit array
    // If the page has been referenced before, then give it one more chance
    while(referenceBitsClock[bitCheck] != 0 && bitCheck <= frameSize){
        referenceBitsClock[bitCheck] = 0; // Give one more chance
        bitCheck++;
        if(bitCheck == frameSize) bitCheck = 0; // If you reach the end, then start over
    }

    temp = frameClock[bitCheck]; // Grab first that has reference bit = 0
    frameClock.erase(frameClock.begin() + bitCheck); // Remove page with ref = 0
    referenceBitsClock.erase(referenceBitsClock.begin() + bitCheck); // Also get rid of reference bit for that page
    
    // Insert page at that index, not at the end like second chance.
    frameClock.insert(frameClock.begin() + bitCheck, page);
    referenceBitsClock.insert(referenceBitsClock.begin() + bitCheck, 0);
    
    return temp;
}

int Clock::fault(int page, int frameSize){
    // If the frame is not full then insert the page
    if(fullClock != frameSize){
        referenceBitsClock.insert(referenceBitsClock.begin() + fullClock, 0);
        frameClock.insert(frameClock.begin() + fullClock, page);
        fullClock++;
        return -1;
    } else return replace(page, frameSize);
}

bool Clock::find(int page, int frameSize){
    bool flag = false;
    for(int i = 0; i < frameClock.size(); i++){
        if(page == frameClock[i]) {
            flag = true;
            referenceBitsClock[i] =  1; // If it is already there then set ref bit to 1
            break;
        } 
    }
    return flag;
}

int Clock::run(vector<int> pages, int frameSize){
    int holder;
    int count = 0;
    int size = pages.size();
    
    // Process all the pages passed from main.cpp
    for(int i = 0; i < size; i++){
        // If you want to print the frames to console
        cout << "Frame: ";
        for(int j = 0; j < frameClock.size(); j++){
            cout << frameClock[j] << " ";
        }
        cout << endl;
        

        if(!find(pages[i], frameSize)){
            // Page was not found so there will be a fault 
            holder = fault(pages[i], frameSize);
            count++; // increase fault count
        }
        
        // else cout << pages[i] << " is already present" << endl;
    }
    return count;
}
