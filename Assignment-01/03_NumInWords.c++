// Write a program that accepts an amount in figures and prints that in words. For example, for an amount of Rs. 426, it should output the string Four hundred twenty six, whereas for Rs.316 it would be Three hundred sixteen. 

// Code: 
#include<iostream>
#include<map>
using namespace std;

string convertToWords(int num){
    
    map<int, string> numDict = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},
        {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
        {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
        {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };

    if (num <= 20) {
        return numDict[num];
    } else if (num < 100) {
        int tens = num / 10 * 10;
        int ones = num % 10;
        return numDict[tens] + " " + numDict[ones];
    } else if (num < 1000) {
        int hundreds = num / 100;
        int remainder = num % 100;
        return numDict[hundreds] + " Hundred " + convertToWords(remainder);
    } else {
        return "Number out of range!";
    }
}

int main() {
    int num; 

    cout << "Enter amount in figures: ";
    cin >> num;

    cout << "Amount in Words: " << convertToWords(num)<< endl;

    return 0;
}

// Output
/*
Enter amount in figures: 234
Amount in Words: Two Hundred Thirty Four
*/