/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void update_spiral_array(int rows, int columns,int **input_array, int x, int y, int x_inc, int y_inc, int limit,int *spiral_array, int count){
	if (count == rows * columns)
		return;

	spiral_array[count++] = input_array[x][y];
	if ((y == columns - limit) && (x_inc == 0) && (y_inc == 1)){
		x_inc = 1;
		y_inc = 0;
	}
	else if ((x == rows - limit) && (x_inc == 1) && (y_inc == 0)){
		x_inc = 0;
		y_inc = -1;
	}
	else if ((y == limit - 1) && (x_inc == 0) && (y_inc == -1)){
		x_inc = -1;
		y_inc = 0;
		limit++;
	}
	else if ((x == limit - 1) && (x_inc == -1) && (y_inc == 0)){
		x_inc = 0;
		y_inc = 1;
	}
	update_spiral_array(rows, columns, input_array, x + x_inc, y + y_inc, x_inc, y_inc, limit, spiral_array, count);

}

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;

	int *spiral_array;
	spiral_array = (int *)malloc((rows * columns) * sizeof(int));

	update_spiral_array(rows, columns, input_array, 0, 0, 0, 1, 1, spiral_array, 0);
	return spiral_array;
}
