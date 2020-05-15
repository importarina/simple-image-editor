#include <stdio.h>
#include <stdlib.h>


void remove_red();
void convert_to_black_and_white();
void instagram_square();

int main(int argc, char *argv[]) {
        /* Task 1 needs to be completed here: Make sure that the command line arguments are correct. In case an error exists,
         * print the error message and terminate the program. Otherwise, invoke the corresponding
         * image processing function. */

		// check the number of arguments

		switch (argc) {
			case 2:
				// check the validity of arguments
				switch (**(argv + 1)) {
					case '1':
						// call remove_red for option 1
						remove_red();
						break;

					case '2':
						// call convert_to_black_and_white for option 2
						convert_to_black_and_white();
						break;

					case '3':
						// call instagram_square for option 3
						instagram_square();
						break;

					default:
						// print error message for invalid option
						printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.");
						break;
				}
				break;

			default:
				// return error message for invalid input
				printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.");
				break;
		}

        return 0;
}
