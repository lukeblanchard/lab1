/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 8, 2018
 ** Description: readMatrix implementation;  
 ****************************************************************************/
#include "readMatrix.hpp"
#include <iostream>

/****************************************************************************
 ** Two parameters: pointer to 2D array and an integer for size of the array. 
 ** The function prompts user to enter all numbers in the matrix.
 ****************************************************************************/
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
            invalidResponse = validateInput(std::cin.fail(), input); //loop until user enters integer
            while(invalidResponse)
            {
                invalidResponse = validateInput(std::cin.fail(), input); 
            }
            matrix[row][col] = input;
        }
    }
}

/****************************************************************************
 ** Two parameters: boolean and integer passed by reference. The std::cin.fail()
 ** function returns a value of true when an error occurs with user input. 
 ** The validateInput function returns true if the user enters an integer,
 ** and false otherwise.
 ****************************************************************************/
bool validateInput(bool inValid, int &userInput)
{
    if(inValid)
    {
        std::cin.clear(); //clears error flag on cin
        std::cin.ignore(); //skips to next line
        std::cout << "Pleaser enter an integer: "; 
        std::cin >> userInput; 
    }
    return std::cin.fail(); 
}




