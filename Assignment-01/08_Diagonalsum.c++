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

    
    cout << "Sum of Primary Diagonal: " << primaryDiagonalSum << endl;
    cout << "Sum of Secondary Diagonal: " << secondaryDiagonalSum << endl;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    
    findDiagonalSum(matrix, size);

    return 0;
}
