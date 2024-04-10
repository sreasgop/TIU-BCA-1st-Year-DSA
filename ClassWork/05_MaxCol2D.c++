// In a 2d array find the maximum elements of a column

#include<iostream>
using namespace std;
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int col, max = arr[0][0]; 
    
    cout << "Enter column number (1-3): "; 
    cin >> col;
    col = col - 1;

    for(int i = 1; i<3; i++){
        if(arr[i][col]>max){
            max = arr[i][col];
        }
    }
    cout << max;
    return 0;
}

