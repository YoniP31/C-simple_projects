/*
A. Write a function that fills a two-dimensional array with random 0 or 1,
   and show it on screen.
B. Write a function that encodes the array to a number of type unsigned long
   long 64 bits, so that char '1' will be represented by bit 1 and char '0' 
   will be represented by bit 0 (from bin_board[0][0] to bin_board[7][7]
   MSB to LSB).
C. Write a function that displays the number as a table of ones and zeros,
   bit 0 as '0' bit 1 as '1') every eight bits will be in a different row,
   from the MSB at the top row and LSB at the last row.
   (Basically decode the number)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define SIZE 8

typedef char board[SIZE][SIZE];
board bin_board;

void fillBoard(board bin_board) {
	int i, j;
	printf("Random array of '0' and '1': \n");
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			bin_board[i][j] = rand() % 2;
			printf("%d, ", bin_board[i][j]);
		}
		printf("\n");
	}
}

unsigned long long boardToBits(board bin_board) {
	int i, j, k = 1;
	unsigned long long code = 0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			unsigned long long int x = pow(2, 64 - k);
			code += bin_board[i][j] * x;
			k++;
		}
	}
	return code;
}

void displayBinaryBoard(unsigned long long coded_bin_board) {
	int bit, i, j;
	char array[SIZE][SIZE];
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			array[i][j] = coded_bin_board % 2;
			coded_bin_board /= 2;
		}
	}
	printf("Decoded array: \n");
	for (i = SIZE - 1; i >= 0; i--) {
		for (j = SIZE - 1; j >= 0; j--) {
			printf("%d, ", array[i][j]);
		}
		printf("\n");
	}
}

void main() {
	unsigned long long code;
	fillBoard(bin_board);
	code = boardToBits(bin_board);
	printf("coded number: %llu\n", code);
	displayBinaryBoard(code);
}