// Question: 
// Write a program/algorithm to sort an array of integers using insertion sort technique. 



// Code: 

#include <iostream>
#define MAXSIZE 100
using namespace std;

void insertionSort(int arr[], int size) {
    int key;
    int j = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

int main() {
    int n;
    int myarray[MAXSIZE];

    cout << "\nInsertion Sort:\n===============\n\n";

    cout << "Number of elements: ";
    cin >> n; 

    cout << "Enter " << n << " integers in any order: ";
    for (int i = 0; i < n; i++) {
        cin >> myarray[i];
    }

    insertionSort(myarray, n);

    cout << endl << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl << endl;
    return 0;
}



// Output:
/*

Insertion Sort:
===============

Number of elements: 5
Enter 5 integers in any order: 100 9 -1 0 2

Sorted Array: 
-1 0 2 9 100 

*/