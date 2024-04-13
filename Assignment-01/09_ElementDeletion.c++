// Output: 
// Write a program to delete an element from an array of integers where position of the element is the input of the program. 



// Code: 

#include <iostream>
using namespace std;


void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

int main() {
    int arr[100];
    int size, pos;

    cout << "\nEnter the size of the array: ";
    cin >> size;

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter the position of the element to delete (0 to n-1): ";
    cin >> pos;

    deleteElement(arr, size, pos);

    cout << "Array after deleting element: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    return 0;
}



// Output" 
/*
Enter the size of the array: 5
Enter the elements: 9 1 3 0 -1

Enter the position of the element to delete (0-indexed): 4
Array after deleting element: 9 1 3 0 
*/