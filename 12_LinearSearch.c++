#include<iostream>
using namespace std;

int main(){
    int arr[10], i, num, index; 
    cout << "Enter 10 numbers: ";
    for(i=0; i<10; i++){
        cin >> arr[i];
    }

    cout << "Enter number to search: ";
    cin >> num; 

    for(i=0; i<10; i++){
        if(arr[i]==num){
            index = i;
            break;
        }
    }

    cout << "\nFound at index no.: " << index << endl; 

    return 0;
}