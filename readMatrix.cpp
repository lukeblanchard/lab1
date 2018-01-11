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
            invalidResponse = validateInput(std::cin.fail(), input, false); //loop until user enters integer
            while(invalidResponse)
            {
                invalidResponse = validateInput(std::cin.fail(), input, false); 
            }
            matrix[row][col] = input;
        }
    }
}

/****************************************************************************
 ** Two parameters: boolean to test cin input, an integer passed by reference, 
 ** and a boolean indicating whether integer input should be greater than zero. 
 ** The std::cin.fail() function returns a value of true when an error occurs with user input. 
 ** The validateInput function returns true if the user enters an integer greater 
 ** than zero, and false otherwise.
 ****************************************************************************/
bool validateInput(bool inValid, int &userInput, bool positive)
{
    bool askAgain; 
    if(inValid)
    {
        std::cin.clear(); //clears error flag on cin
        std::cin.ignore(); //skips to next line
        std::cout << "Pleaser enter an integer: "; 
        std::cin >> userInput; 
        askAgain = std::cin.fail(); 
    }
    else if(userInput <= 0 && positive)
    {
        std::cout << "Pleaser enter an integer greater than 0: "; 
        std::cin >> userInput; 
        askAgain = true; 
    }
    else 
    {
        askAgain = false; 
    }
    return askAgain;  
}




