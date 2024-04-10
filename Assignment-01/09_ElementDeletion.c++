#include <iostream>
using namespace std;

// Function to delete an element from an array
void deleteElement(int arr[], int& size, int position) {
    // Check if position is valid
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the left starting from position
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    size--;
}

int main() {
    int arr[100]; // Maximum array size
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input the elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int position;
    // Input the position to delete element
    cout << "Enter the position of the element to delete (0-indexed): ";
    cin >> position;

    // Delete element at the given position
    deleteElement(arr, size, position);

    // Display the updated array
    cout << "Array after deleting element:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
