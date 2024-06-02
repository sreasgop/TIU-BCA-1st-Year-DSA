#include<iostream>
#define MAX_SIZE 100
using namespace std;


int deleteElement(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
            while(i<size-1){
                arr[i] = arr[i+1];
                i++;
            }
            size--;
            break;
        }
    }
    return size;
}


void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}


int main() {
    
    int arr[MAX_SIZE];
    int n, newSize, key; 

    cout << "Number of elements: ";
    cin >> n; 

    cout << "Enter the elements: "; 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter element to delete: "; 
    cin >> key; 

    newSize = deleteElement(arr, n, key);
    
    if(n==newSize){
        cout << key << " not found in the array!\n\n";
    } else{
        printArray(arr, newSize);
    }

    return 0;
}