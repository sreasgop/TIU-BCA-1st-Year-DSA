#include<iostream>
#define MAXSIZE 100
using namespace std;

int LinearSearch(int arr[], int arr_size, int num) {
    int i, index;
    for(i=0; i<arr_size; i++){
    if(arr[i]==num){
        return index = i;
        }
    } 
    return -1;
}

int main(){
    int array[MAXSIZE], n, i, num, value_index; 
    
    cout << "\nNumber of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(i=0; i<n; i++){
        cin >> array[i];
    }

    cout << "Enter number to search: ";
    cin >> num; 

    value_index = LinearSearch(array, n, num);

    if(value_index == -1){
        cout << "\nData not Found!" << endl; 
    } else {
        cout << "\nFound at index no.: " << value_index << endl << endl; 
    }

    return 0;
}