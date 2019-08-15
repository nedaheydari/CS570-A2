/*
CLASS NAME: CS 570
ASSIGNMENT: LAB #2
NAMES: Neda Heydari, Ole Larsen
USERNAMES: CSSC1147, CSSC1140
*/

#include <stdio.h>
#include "Optimal.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int fullOpt = 0; // to check if the frame is full or not
vector<int> frameOpt;
int position = 0; // Used to increment our position on the pages list

int Optimal::replace(int page, int frameSize, vector<int> pages){
    vector<int> distance;
    int longest = 0;
    int longestIndex = 0;
    int temp = 0;
    int pos = 0;

    // For each page in the frame, count the length until the next
    // instance of that page in the page list
    for(int i = 0; i < frameOpt.size(); i++){
        for(int j = position + 1 ; j < pages.size(); j++){
            if(frameOpt[i] == pages[j]) break; // If found page stop looking
            temp++; // If not found, increase counter
        }
        distance.insert(distance.begin() + pos, temp); // Insert the distance
        
        // Update the page with the longest distance
        if (temp > longest){
            longestIndex = pos;
            longest = temp;
        }
            
        pos++;
        temp = 0;
    }

    // replace the page with the longest distance
    int tempPage = frameOpt[longestIndex];
    frameOpt[longestIndex] = page;
    return tempPage;
}

int Optimal::fault(int page, int frameSize, vector<int> pages){
    // If the frame is not full then insert the page
    if(fullOpt != frameSize){
        frameOpt.insert(frameOpt.begin() + fullOpt, page);
        fullOpt++;
        return -1;
    } else return replace(page, frameSize, pages);
}

bool Optimal::find(int page, int frameSize){
    bool flag = false;
    for(int i = 0; i < frameOpt.size(); i++){
        if(page == frameOpt[i]) {
            flag = true;
            break;
        } 
    }
    return flag;
}

int Optimal::run(vector<int> pages, int frameSize){
    int holder;
    int count = 0;
    int size = pages.size();
    
    // Process all the pages passed from main.cpp
    for(int i = 0; i < size; i++){
        ///* If you want to print the frames to console
        cout << "Frame: ";
        for(int j = 0; j < frameOpt.size(); j++){
            cout << frameOpt[j] << " ";
        }
        cout << endl;
        //

        if(!find(pages[i], frameSize)){
            // Page was not found so there will be a fault 
            holder = fault(pages[i], frameSize, pages);
            count++; // increase fault count
        }
        else cout << pages[i] << " is already present" << endl;
        position++;
        
    }
    return count;
}
