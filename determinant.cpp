/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 11, 2018
 ** Description: Takes two parameters, pointer to a 2D array and size, and 
 ** calculates determinant. If size > 2, determinant makes recursive call.
 ****************************************************************************/

#include "determinant.hpp"

int determinant(int **matrix, int size)
{
    int det = 0;
    
    //Base case
    if(size == 2) 
    {
        det += matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];     
    }
    //Recursive step
    else
    {
        int sign = -1; //must alternate sign
        int **smallMatrix; //pointer to smaller matrix for recursive call
        int offSet; //counter for determining correct index of cols in smallMatrix, details below

        for(int firstRowCol = 0; firstRowCol < size; firstRowCol++)
        {
            sign *= -1; //start with positive 1 
            smallMatrix = new int*[size - 1]; //for each col in firstRow we create a smaller matrix
             
            //matrix[0] not included in recursive call, start with matrix[1] 
            for(int row = 1; row < size; row++) 
            {

                smallMatrix[row - 1] = new int[size - 1]; 

                //the number of cols in original matrix that are correctly indexed for smallMatrix equals firstRowCol.
                //All other cols must equal col - 1. Example: when firstRowCol = 0, 0 cols in original matrix have correct index
                //and all must decrease by 1. When firstRowCol = 1, 1 col in original matrix has correct index, and the rest 
                //must decrease by one, and so on.
                offSet = firstRowCol; 

                //loop through cols of smaller matrix
                for(int col = 0; col < size; col++)
                {
                    if(col != firstRowCol)//add only those numbers not in the same row and col
                    {
                        if(offSet > 0) 
                        {
                            smallMatrix[row - 1][col] = matrix[row][col];  
                        }
                        else
                        {
                            smallMatrix[row - 1][col - 1] = matrix[row][col]; 
                        }
                    }
                    offSet -= 1; //reduce offset with each loop to determine correct index of next col
                }
            }
            //firstRowCol * determinant of the matrix not in firstRowCol's row or col
            //must decrease size with each recursive call
            det += sign * matrix[0][firstRowCol] * determinant(smallMatrix, size - 1); 
        }

        //free memory 
        for(int row = 0; row < size - 1; row++)
           delete [] smallMatrix[row]; 
        delete [] smallMatrix;
    }

    return det;
}
