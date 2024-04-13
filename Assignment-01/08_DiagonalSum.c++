// Question: 
// Write a C program to find sum of the two diagonals of a square matrix (n x n). 



// Code: 

#include <iostream>
using namespace std;

#define MAX_SIZE 10

void findDiagonalSum(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < size; i++) {
        primaryDiagonalSum += matrix[i][i];
    }
    
    for (int i = 0; i < size; i++) {
        secondaryDiagonalSum += matrix[i][size - 1 - i];
    }
    
    cout << "\nSum of Primary Diagonal: " << primaryDiagonalSum << endl;
    cout << "Sum of Secondary Diagonal: " << secondaryDiagonalSum << "\n\n";
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    
    cout << "\nEnter the size of the square matrix: ";
    cin >> size;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
    
    findDiagonalSum(matrix, size);

    return 0;
}



// Output: 
/*
Enter the size of the square matrix: 3
Enter the elements of the matrix:
5 10 15
2 4 8 
9 10 9

Sum of Primary Diagonal: 18
Sum of Secondary Diagonal: 28

*/