/* 
Names:
    Thomas Gibbons
    Malcolm Morton
    Samuel Njogo
    Thomas Holloway
Couse Section: CSCE 3600.002
Date: September 10th, 2021
Description:
Contains a single function to perform the endian swap operation of the 32-bit input argument 
passed to this function. Endianness refers to how the bytes are stored in memory. 
In a 32-bit word, there are 4 bytes – B0, B1, B2, and B3. Let us assume that B0 refers to the 
least significant byte and B3 the most significant byte. The function will swap bytes B0 and B3,
as well as bytes B1 and B2.
*/

#include "major1.h"

void endianSwap ( unsigned int unsignedInput ) {
	//declaring variables to store each byte in so the swap can be made clear.
	unsigned int mostSByte;
	unsigned int middleMSByte;
	unsigned int middleLSByte;
	unsigned int leastSByte;
	//variable to store the final value
	unsigned int swappedVal;

	//in each of these operations, each positional byte variable is &&'d with its
	//corresponding bits in hexadecimal and stored for combination later.
	mostSByte = (unsignedInput & 0x000000FF) >> 0;
	middleMSByte = (unsignedInput & 0x0000FF00) >> 8;
	middleLSByte = (unsignedInput & 0x00FF0000) >> 16;
	leastSByte = (unsignedInput & 0xFF000000) >> 24;

	//after the correct values are stored in the variables, then each variable is shifted
	//so that the bits line up correctly with their new position.
	mostSByte <<= 24;
	middleMSByte <<= 16;
	middleLSByte <<= 8;
	leastSByte <<= 0;

	//finally, all of the byte variables are ||'d together to make up the final result.
	swappedVal = (mostSByte | middleMSByte | middleLSByte | leastSByte);

	//prints the final value of the swapped numbers.
    	printf("Endian swap of %u gives %u\n", unsignedInput, swappedVal);
}
