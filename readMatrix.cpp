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
    int input; 
    bool invalidResponse; 

    for(int row = 0; row < size; row++) 
    {
        for(int col = 0; col < size; col++) 
        {
            std::cout << "Please enter number for " << row << ", " << col << ": "; 
            std::cin >> input; 
            invalidResponse = validateInput(std::cin.fail(), input); 
            while(invalidResponse)
            {
                invalidResponse = validateInput(std::cin.fail(), input); 
            }
            matrix[row][col] = input;
        }
    }
}

bool validateInput(bool inValid, int &userInput)
{
    if(inValid)
    {
        std::cin.clear(); 
        std::cin.ignore(); 
        std::cout << "Pleaser enter an integer: "; 
        std::cin >> userInput; 
    }
    return std::cin.fail(); 
}




