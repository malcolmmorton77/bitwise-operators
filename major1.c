/* 
Names:
    Thomas Gibbons
    Malcolm Morton
    Samuel Njogo
    Thomas Holloway
Couse Section: CSCE 3600.002
Date: September 10th, 2021
Description:
This is the code file with the main() function that will do the following: 
(1) display the menu
(2) read in the user’s response for the menu selection
(3) prompt for and read an integer operand between 1 and 4294967295, inclusively
(4) if the “Rotate Right” operation is selected, then prompt for a second integer 
    between 0 and 31 (inclusively) to obtain the rotate amount
(5) based on the menu selection, call the appropriate function call for the specified operation, 
    passing the integer operand(s) as parameter(s) to the function. 
    This functionality will be contained in a loop that will continue to iterate until the user
    selects the option to end the program.
*/

#include "major1.h"

void header() {
	printf("+----------------------------------------------+\n");
	printf("|       Computer Science and Engineering       |\n");
	printf("|                                              |\n");
	printf("|       CSCE 3600 - Systems Programming        |\n");
	printf("|            September 10th, 2021              |\n");
	printf("|                                              |\n");
	printf("| Thomas Gibbons   trg0117  trg0117@my.unt.edu |\n");
	printf("| Malcolm Morton   mtm0221  mtm0221@my.unt.edu |\n");
	printf("|  Samuel Njogo    snn0070  snn0070@my.unt.edu |\n");
	printf("| Thomas Holloway  tlh0354  tlh0354@my.unt.edu |\n");
	printf("+----------------------------------------------+\n");
} // header

int printMenu(unsigned short int menuInput){
    // displays the menu options
    printf("Enter the menu option for the operation to perform:\n(1)  Count Leading Zeroes\n(2)  Endian Swap\n(3)  Rotate-right\n(4)  Parity\n(5)  EXIT\n --> ");
    scanf("%hu", &menuInput);
    // error checking with a meaningful message
    if ((menuInput != 1) && (menuInput != 2) && (menuInput != 3) && (menuInput != 4) && (menuInput != 5)){ printf("Error: Invalid option. Please try again.\n");}
    // returns input
    return (menuInput);
} // printMenu function

int main(){

	header(); // prints header output

    // variables used to pass to each function
    int userInput = 0;
    unsigned int unsignedInput = 0;
    unsigned short int uShortInt = 0;

    // do loop for user interface via switch case
    while (userInput != 5) {
        // displays the menu options
        userInput = printMenu(userInput);

        if ( userInput >= 1 && userInput <= 4 ) {
            // input asked for each case other than case 5
            do {
                printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
                scanf("%u", &unsignedInput);
            } while (!(unsignedInput >= 1) || !(unsignedInput <= 4294967295));
            // need to error check for negatives
            
            if (userInput == 3) {
                do {
                    printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
                    scanf("%hu", &uShortInt);
                } while (!(uShortInt >= 0) || !(uShortInt <= 31));
            } // if test for third switch case (requires second variable to be passed)
        } // if to check for the exit case

        // calls different functions based on user input
        switch (userInput) {

            case 1: // Count Leading Zeroes
                leadingZeroes(unsignedInput);
                break;

            case 2: // Endian Swap
                endianSwap(unsignedInput);
                break;

            case 3: // Rotate-right
                rotateR(unsignedInput, uShortInt);
                break;

            case 4: // Parity
                parity(unsignedInput);
                break;

            case 5: // Exit
                printf("Program terminating. Goodbye...\n");
                break;
        } // switch case
    } // while loop only stops if user input is 5

    return 0;
} // main
