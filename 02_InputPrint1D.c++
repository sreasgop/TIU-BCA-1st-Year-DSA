#include<iostream>
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i: arr){
        std::cout << i << " ";
    }
    return 0;
}