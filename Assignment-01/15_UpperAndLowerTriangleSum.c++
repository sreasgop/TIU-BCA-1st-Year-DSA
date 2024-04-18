// Question: 
// Write a program to find the sum of the upper/lower triangle elements of a giver matrix. 



// Code:

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;


int sumUpperTriangle(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}


int sumLowerTriangle(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
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

    
    int sumUpper = sumUpperTriangle(matrix, size);
    cout << "\nSum of upper triangle elements: " << sumUpper << endl;

    
    int sumLower = sumLowerTriangle(matrix, size);
    cout << "Sum of lower triangle elements: " << sumLower << "\n\n";

    return 0;
}



// Output:
/*
Enter the size of the square matrix: 3
Enter the elements of the matrix:
5 10 15
2 4 8
1 9 12

Sum of upper triangle elements: 54
Sum of lower triangle elements: 33
*/