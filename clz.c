/* 
Names:
    Thomas Gibbons
    Malcolm Morton
    Samuel Njogo
    Thomas Holloway
Couse Section: CSCE 3600.002
Date: September 10th, 2021
Description:
Contains a single function to count the number of leading zeroes in the 32-bit input argument 
passed to the function
*/

#include "major1.h"

void leadingZeroes (unsigned int unsignedInput) {
    unsigned int tempBit = 0;
    unsigned int count = 0;
    // conversion to binary
    for(int i = 31; i >= 0; --i){
        tempBit = unsignedInput >> i; // converts unsigned int to binary (per bit)
        if (tempBit & 1){ i = 0; } // end the loop if a 1 is found
        else { ++count; } // increase count for each 0
    }

    printf("The number of leading zeroes in %u is %u\n", unsignedInput, count);
}