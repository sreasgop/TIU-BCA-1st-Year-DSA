// Write a program to search an element in an array using binary search technique.

#include<iostream>
#define MAXSIZE 100
using namespace std;

int BinarySearch(int array[], int num, int low, int high){
    while(low<=high){
        int mid = low + (high -low)/2;
        if(array[mid]==num){
            return mid;
        } else if(array[mid]<num){
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    return -1;      
}

int main(){
    
    int n, i, x;
    int array[MAXSIZE];

    cout << "\nNumber of elements: "; 
    cin >> n; 

    cout << "Enter the sorted array: ";
    for(i=0; i<n; i++){
        cin >> array[i];
    }
    
    cout << "Search number: ";
    cin >> x;
    
    int result = BinarySearch(array, x, 0, n);

    if(result==-1){
        cout << "Number not found!" << endl;
    } else {
        cout << "\nElement found at index: " << result << endl << endl; 
    }

    return 0;
}