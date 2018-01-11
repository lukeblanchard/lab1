/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 8, 2018
 ** Description: readMatrix implementation; the readMatrix function has two 
 ** parameters--pointer to 2D array and an integer for size of matrix. The 
 ** function prompts user to enter all numbers in the matrix.
 ****************************************************************************/

#include "readMatrix.hpp"
#include <iostream>

void readMatrix(int **matrix, int size)
{
    for(int row = 0; row < size; row++) 
    {
        for(int col = 0; col < size; col++) 
        {
            std::cout << "Please enter number for " << row << ", " << col << ": "; 
            std::cin >> matrix[row][col]; 
        }
    }
}
