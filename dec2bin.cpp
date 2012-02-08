/******************************************************************************
 * dec2bin.cpp
 *
 * Rick W
 * 02/07/2012
 *
 * Converts a number to binary from base 10.
 *
 *****************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

// Find the largest multiple of two that goes into a number
// Takes a number to get multiple of.
// Returns the largest multiple of two for a number.
int GetLargestMultipleOfTwo(int number);

// uses std namespace
int main(int argc, char *argv[]) {
    using namespace std;

    return 0;
}

// Get largest multiple of two for a number
int GetLargestMultipleOfTwo(int number) {
    int multiple = 1;
    bool found = false;

    while(!found) {
        if(multiple * 2 <= number) 
            multiple *= 2;
        else
            found = true;
    }

    return multiple;
}
