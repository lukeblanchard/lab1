/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Creates a 2x2 or 3x3 matrix based on user input
 ****************************************************************************/
#include <iostream> 
#include "readMatrix.hpp"
#include "determinant.hpp"

int main()
{
    int matrixSize; 
    int det; //determinant
    bool invalidResponse;
    int **matrix = nullptr; 

    std::cout << "Please enter size for your square matrix (2 or 3): "; 
    std::cin >> matrixSize; 

    //Input validation
    invalidResponse = validateInput(std::cin.fail(), matrixSize, true); 
    while(invalidResponse)
    {
        invalidResponse = validateInput(std::cin.fail(), matrixSize, true); 
    }
    
    //Dynamically allocated memory
    matrix = new int*[matrixSize]; 
    for(int row = 0; row < matrixSize; row++)
        matrix[row] = new int[matrixSize];

    //Use readMatrix to let user fill matrix
    readMatrix(matrix, matrixSize); 
    
    //Calculate determinant
    det = determinant(matrix, matrixSize); 


    //Display matrix
    std::cout << std::endl;
    for(int row = 0; row < matrixSize; row++)
    {
        for(int col = 0; col < matrixSize; col++)
        {
            std::cout << matrix[row][col] << " "; 
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
    
    std::cout << "Determinant: " << det << std::endl;

    //free memory 
    for(int row = 0; row < matrixSize; row++)
        delete [] matrix[row]; 
    delete [] matrix;  

    return 0;
}
