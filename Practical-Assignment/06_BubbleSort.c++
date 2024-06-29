#include<iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    int temp;
    for(int i=size-1; i>=0; i--){
        int is_swapped = 0;
        for(int j=0; j<=i-1; j++){
            if(arr[j]>=arr[j+1]){
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                is_swapped++;
            }
        }
        if(is_swapped == 0){
            break;
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