/* 
Names:
    Thomas Gibbons
    Malcolm Morton
    Samuel Njogo
    Thomas Holloway
Couse Section: CSCE 3600.002
Date: September 10th, 2021
Description:
Contains a single function to perform the parity computation on the input integer passed to this function. 
The output of the function is 0 if the input has even parity and 1 if the input has odd parity.
*/

#include "major1.h"

// void parity( unsigned int unsignedInput ) {
//     printf("Parity of %u is (0|1)\n", unsignedInput);
// }

void parity( unsigned int unsignedInput ) {

  int y = unsignedInput ^ (unsignedInput >> 1);

    for (int i = 2; i <= 16; i *= 2){
        y = y ^ (y >> i);
    }

    if (y & 1)
      printf("Parity of %u is 1\n", unsignedInput);    // to be put in the function itself
    else
      printf("Parity of %u is 0\n", unsignedInput);
}
