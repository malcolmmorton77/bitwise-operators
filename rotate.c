/*
Names:
    Thomas Gibbons
    Malcolm Morton
    Samuel Njogo
    Thomas Holloway
Couse Section: CSCE 3600.002
Date: September 10th, 2021
Description:
Contains a single function to perform the rotation operation using the two integer operands
passed to this function. The first integer operand is the number to be rotated. The second
integer operand is the number of bit positions that the first operand must be rotated by.
*/

#include "major1.h"

void rotateR ( unsigned int unsignedInput, unsigned short int uShortInt ) {
    //shift right the given value, then OR the unsignedInput left shifted by the full length minus the given shift
    //this copies the right-most string of bits (length = uShortInt) to the left of the unsignedInput
    unsigned int temp = unsignedInput >> uShortInt | unsignedInput << (32 - uShortInt);
    if (uShortInt == 1) { //if test for english
        printf("%u rotated by %hu position gives: %u\n", unsignedInput, uShortInt, temp);
    }
    else if ((uShortInt >= 0) && (uShortInt <= 31)) {//note position and positions
        printf("%u rotated by %hu positions gives: %u\n", unsignedInput, uShortInt, temp);
    }
}

