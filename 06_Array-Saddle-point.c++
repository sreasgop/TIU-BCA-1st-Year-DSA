// Take a 2d array as input and find the minimum element of each row n chech whether it is the maximum element for that particular column.

#include<iostream>
using namespace std;

int checkarray(int arr[][3], int row_col_no){
    int min = arr[row_col_no][0]; 
    int max = arr[0][row_col_no];  

    for(int i = 1; i < 3; i++){
        if(min > arr[row_col_no][i]){
            min = arr[row_col_no][i];
        }
        if(max < arr[i][row_col_no]){
            max = arr[i][row_col_no];        
        }        
    } 

    if(min >= max){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

int main() {
    int arr[3][3];
    cout << "Enter the a 3x3 2D Array: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    cout << "\n\n";

    for(int i = 0; i < 3; i++){
        checkarray(arr, i);
    }

    return 0;
}