// Take a input and print a 2d array

#include<iostream>
using namespace std;
int main() {
    
    int arr[3][3];
    cout << "\nEnter the 2D Array(3x3):" << endl; 
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    cout << "\nThe entered 2D array:\n";
    for(int i=0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}