#include<iostream>
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
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4; 
    int n = sizeof(array)/sizeof(array[0]);
    int result = BinarySearch(array, x, 0, n-1);

    if(result==-1){
        cout << "Number not found!" << endl;
    } else {
        cout << "Element found at index: " << result << endl; 
    }

    return 0;
}