/*
Write a program that receives a matrix and returns its transposed matrix
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

void free_matrix(int** c, int n) {
	int i;
	for (i = 0; i < n; i++)
		free(c[i]);
	free(c);
}

int** alloc_matrix(int rows, int cols) {
	int** c, i;
	c = (int**)calloc(rows, sizeof(int*));
	if (c == NULL)
		return NULL;
	for (i = 0; i < rows; i++) {
		c[i] = (int*)calloc(cols, sizeof(int));
		if (c[i] == NULL) {
			free_matrix(c, i);
			return NULL;
		}
	}
	return c;
}

int Transpose_matrix(int** A, int n, int m) {
	int** At, i, j;
	At = alloc_matrix(m, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			At[j][i] = A[i][j];
		}
	}
	return At;
}

void print_matrix(int** Mat, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d, ", Mat[i][j]);
		}
		printf("\n");
	}
}

void main() {
	//matrix input from user
	int** A, i, j, rows, cols;
	printf("Enter number of rows: ");
	scanf("%d", &rows);
	printf("Enter number of cols: ");
	scanf("%d", &cols);
	A = alloc_matrix(rows, cols);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("Enter a Natural number in [%d][%d]: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	print_matrix(A, rows, cols);

	//transposing matrix
	int** At = Transpose_matrix(A, rows, cols);
	printf("Trandposed matrix: \n");
	print_matrix(At, rows, cols);
	free_matrix(At, cols);
	free_matrix(A, rows);
}