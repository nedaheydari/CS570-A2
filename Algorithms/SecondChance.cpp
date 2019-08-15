/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #2
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include "SecondChance.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int full = 0; // to check if the frame is full or not
vector<int> frame;
vector<int> referenceBits;

int SecondChance::replace(int page, int frameSize){
    int temp;
    int bitCheck = 0; // To enter the referenceBit array
    // If the page has been referenced before, then give it one more chance
    while(referenceBits[bitCheck] != 0 && bitCheck <= frameSize){
        referenceBits[bitCheck] = 0; // Give one more chance
        bitCheck++;
        if(bitCheck == frameSize) bitCheck = 0;
    }

    temp = frame[bitCheck]; // Grab first that has reference bit = 0
    frame.erase(frame.begin() + bitCheck); // Remove page with ref = 0
    referenceBits.erase(referenceBits.begin() + bitCheck); // Also get rid of reference bit for that page
    frame.push_back(page); // Insert the page at the end of frame
    referenceBits.push_back(0); // Set reference bit of last item to 1
    return temp;
}

int SecondChance::fault(int page, int frameSize){
    // If the frame is not full then insert the page
    if(full != frameSize){
        referenceBits.insert(referenceBits.begin() + full, 0);
        frame.insert(frame.begin() + full, page);
        full++;
        return -1;
    } else return replace(page, frameSize);
}

bool SecondChance::find(int page, int frameSize){
    bool flag = false;
    for(int i = 0; i < frame.size(); i++){
        if(page == frame[i]) {
            flag = true;
            referenceBits[i] =  1; // If it is already there then set ref bit to 1
            break;
        } 
    }
    return flag;
}

int SecondChance::run(vector<int> pages, int frameSize){
    int holder;
    int count = 0;
    int size = pages.size();
    
    // Process all the pages passed from main.cpp
    for(int i = 0; i < size; i++){
        // If you want to print the frames to console
        cout << "Frame: ";
        for(int j = 0; j < frame.size(); j++){
            cout << frame[j] << " ";
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
