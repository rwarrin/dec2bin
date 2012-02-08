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

    // make sure the program is being used properly
    if(argc != 2) {
        cout << "Usage: dec2bin <number>\n";
        return 1;
    }

    // convert the argument from a cstring to an int
    int number = atoi(argv[1]);

    // convert the number to binary
    string binary = DecimalToBinary(number);

    // print to screen
    cout << binary << endl;

    return 0;
}

// Get largest multiple of two for a number
int GetLargestMultipleOfTwo(int number) {
    int multiple = 1;
    bool found = false;

    // keep looping as long as multiple * 2 is not greater than number
    // if it is then stop and return multiple
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
    
    // create a stream to treat as an output stream
    ostringstream oss;
    string str;
    
    // get multiple of two for the number
    int multiple = GetLargestMultipleOfTwo(number);

    // start at the highest multiple and count down by half, each time checking
    // that number - multiple isn't less than 0.  If it's greater than or equal
    // to zero then reduce the number and output a '1', otherwise output '0'.
    for(; multiple >= 1; multiple /= 2) {
        if((number - multiple) >= 0) {
            number -= multiple;
            oss << "1";
        }
        else
            oss << "0";
    }

    // get the string from the ostreamstring object
    str = oss.str();
    return str;
}
