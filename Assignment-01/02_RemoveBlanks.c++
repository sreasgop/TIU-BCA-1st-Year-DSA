// In an inputted sentence words are separated by a random number of blanks. Write a program to convert the sentence in perfect form where each word will be separated by a single blank. 

// Code:
#include <iostream>

using namespace std;

void convertToPerfectForm(char* str) {
    int index = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (index > 0 && str[index - 1] != ' ') {
                str[index++] = ' ';
            }
        } else {
            str[index++] = str[i];
        }
    }

    if (index > 0 && str[index - 1] == ' ') {
        index--;
    }

    str[index] = '\0'; 
}

int main() {
    char str[100];
    cout << "Enter the sentence: ";
    cin.getline(str, 100); 
    
    convertToPerfectForm(str);

    cout << "Sentence in perfect form: " << str << endl;

    return 0;
}
// Output
/*
Enter the sentence: A quick  brown   fox jmps over   the lazy dog
Sentence in perfect form: A quick brown fox jmps over the lazy dog
*/