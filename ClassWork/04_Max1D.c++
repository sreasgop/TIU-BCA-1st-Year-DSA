// Find the maximum elements of a row of 1d array

#include<iostream>
using namespace std;
int main() {
    int arr[10] = {19, 2, 21, 4, 34, 41, 109, 39, 20, 10}; 
    int max = arr[0];

    cout << "\nThe array: ";

    for(int i=1; i<10; i++){
        cout << arr[i] << " ";
        if(arr[i]> max){
            max = arr[i];
        }
    }

    cout << "\nThe Maximum element: " << max << "\n\n";
    return 0;
}