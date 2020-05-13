#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */

#define magic_num_size 2

/*	Read and edit image based on the given option
	option 1 -> remove_red
	option 2 -> convert_to_black_and_white
	option 3 -> instagram_square
*/
void editor(int option) {
	char magic_num;
	// get and print the magic number
	for (int i = 0; i < magic_num_size; i++) {
		scanf("%c", &magic_num);
		printf("%c", magic_num);
	}
	int col, row, max_val;
	// get # of col, row, and maximum value
	scanf("%d %d %d", &col, &row, &max_val);
	// change to square dimensions for if instagram_square option selected
	int change_col = 0, change_row = 0, max = col;
	if (option == 3) {
		if (col > row) {
			change_col = 1;
			max = row;
		}
		else {
			change_row = 1;
			row = col;
		}
	}
	// print number of columns, row, and maximum value
	printf("\n%d %d\n%d\n", max, row, max_val);
	int r, g, b;
	//	for option 3:
	//		since scanf scans from left to right and then top to bottom,
	//		all columns of a row have to be read, and in case of col reduction,
	//		we simply read but ignore the extra pixels on the right
	//		but if the row number has to be reduced, we can stop reading
	//		once we reach the new row number
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d %d %d", &r, &g, &b);
			// if option 1 selected, substitute red value with 0
			if (option == 1) printf("%d %d %d\n", 0, g, b);
			else if (option == 2) {
				// if option 2 is selected, substitute all values with their average
				int avg = (r + g + b) / 3;
				printf("%d %d %d\n", avg, avg, avg);
			}
			// if option 3 is selected, just print the actual values
			else if (option == 3 && (change_row || (change_col && j < row))) printf("%d %d %d\n", r, g, b);
		}
	}
}

void remove_red()
{
	editor(1);
}
/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
	editor(2);
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
	// removes the right most column or bottom row, dpending on which is larger
	editor(3);
}

