#include <iostream> 
#include "readMatrix.hpp"
#include "determinant.hpp"
using namespace std; 

int main()
{
    int matrixSize; 
    int **matrix = nullptr; 

    cout << "Please enter size for your matrix: "; 
    cin >> matrixSize; 
    
    matrix = new int*[matrixSize]; 
    for(int row = 0; row < matrixSize; row++)
        matrix[row] = new int[matrixSize];

    readMatrix(matrix, matrixSize); 

    int det = determinant(matrix, matrixSize); 

//Display matrix

    for(int row = 0; row < matrixSize; row++)
    {
        for(int col = 0; col < matrixSize; col++)
        {
            cout << matrix[row][col] << " "; 
        }
        cout << endl; 
    }
    
    cout << "Determinant: " << det << endl;

    //free memory 
    for(int row = 0; row < matrixSize; row++)
        delete [] matrix[row]; 
    delete [] matrix;  

    return 0;
}
