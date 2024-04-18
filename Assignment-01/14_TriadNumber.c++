// Question:
// Write a program to check whether a given number is triad or not. 



// Code:

#include <iostream>
#include <cmath>
using namespace std;

bool isTriad(int number) {
    for (int a = 0; a * a * a <= number; a++) {
        for (int b = a; b * b * b <= number; b++) {
            for (int c = b; c * c * c <= number; c++) {
                if (a * a * a + b * b * b + c * c * c == number) {
                    cout << number << " is a triad number!";
                    return true;
                }
            }
        }
    }
    cout << number << " is not a triad number." << endl;
    return false;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    isTriad(number);

    return 0;
}



// Output:
/*
Enter a number: 1729
1729 is a triad number!
*/