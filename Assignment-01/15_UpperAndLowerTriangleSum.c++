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

    
    int sumUpper = sumUpperTriangle(matrix, size);
    cout << "Sum of upper triangle elements: " << sumUpper << endl;

    
    int sumLower = sumLowerTriangle(matrix, size);
    cout << "Sum of lower triangle elements: " << sumLower << endl;

    return 0;
}
