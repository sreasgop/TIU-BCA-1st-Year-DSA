#include<iostream>
using namespace std;

void PrintArray(int arr[], int size){
    for(int i=0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

int main() {
    int arr[100];
    int n, val, pos; 
    int capacity = sizeof(arr)/sizeof(arr[0]);

    cout << "\nNumber of elements: ";
    cin >> n; 

    capacity = sizeof(arr)/sizeof(arr[0]);

    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to insert: ";
    cin >> val; 
    cout << "Enter index position: "; 
    cin >> pos; 

    if(n>=capacity){
        cout << "Array is full, can't insert element\n";
    } else {
        for(int i=n+1; i>=pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
    }
    n++;
    cout << "\nArray after insertion of new element:\n";
    PrintArray(arr, n);
    return 0;
}