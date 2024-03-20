#include<iostream>
using namespace std;

void SelectionSort(int array[], int size){
    for(int i=0; i<size; i++){
        int min = i; 

        for(int j = i+1; j < size + 1; j++){
            if(array[j]<array[min]){
                min = j;
            }
        }

        if(min!=i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

int main(){
    int n, i; 
    cout << "No of elements: ";
    cin >> n; 

    int arr[n];

    cout << "Enter the elements: ";
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    SelectionSort(arr, n);

    cout << "\nSorted Array: ";
    for(i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    
    return 0;
}