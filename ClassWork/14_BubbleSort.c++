#include<iostream>
using namespace std;

void BubbleSort(int array[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<(size-i-1); j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    cout << "No. of Elements: ";
    cin >> n;
    
    int arr[n];

    cout << "Enter the elements: ";
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    BubbleSort(arr, n);

    cout << "\nSorted Array: ";
    for(i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    return 0;
}