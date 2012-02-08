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

// Convert decimal number to binary
// Takes a number to convert to binary
// Returns a string of binary digits
std::string DecimalToBinary(int number);

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

// Convert decimal to binary
std::string DecimalToBinary(int number) {
    using namespace std;
    ostringstream oss;
    string str;
    int multiple = GetLargestMultipleOfTwo(number);

    for(; multiple >= 1; multiple /= 2) {
        if((number - multiple) >= 0) {
            number -= multiple;
            oss << "1";
        }
        else
            oss << "0";
    }
    str = oss.str();
    return str;
}
