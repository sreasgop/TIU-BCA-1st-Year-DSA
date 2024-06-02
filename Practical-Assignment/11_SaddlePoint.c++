// Take a matrix as input and find the minimum element of each row n chech whether it is the maximum element for that particular column, i.e. Saddle Point.

#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void findSaddlePoint(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int minInRow = matrix[i][0];
        int colIndexOfMin = 0, rowIndexOfMin = 0;

        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                colIndexOfMin = j;
                rowIndexOfMin = i;
            }  
        }

        bool saddlePointFound = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndexOfMin] > minInRow) {
                saddlePointFound = false;
                break;
            }
        }

        if (saddlePointFound) {
            cout << "\nSaddle Point Found: " << minInRow << endl;
            cout << "At Index: " << "[" << rowIndexOfMin << "]" << "[" << colIndexOfMin << "]" << endl << endl;
            return;
        }
    }

    cout << "No Saddle Point Found" << endl;
}

int main() {
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];

    cout << "\n\nFind Saddle Poit:\n=================\n\n";

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    findSaddlePoint(matrix, rows, cols);

    return 0;
}