#include<iostream>

#define MAXSIZE 100

using namespace std;

class Stack_Array{
    int stack[MAXSIZE];
    int top; 

    public:
    
    Stack_Array(){
        top = -1;
    }

    void push();
    void pop();
    void traverse();
};

void Stack_Array::push(){
    int item; 
    if(top==MAXSIZE-1){
        cout << "\nThe Stack is full";
        
    } else {
        cout << "Enter element to be inserted: ";
        cin >> item;
        stack[++top] = item;    
    }
}

void Stack_Array::pop(){
    int item; 
    if(top==-1){
        cout << "\nThe stack is empty";
    
    } else {
        item = stack[top--];
        cout << "The Deleted item is: " << item;
    }
}

void Stack_Array::traverse(){
    int i; 
    if(top==-1){
        cout << "\nStack Empty";
    } else {
        cout << "The elements in the stack are: ";
        for(i=top; i>=0; i--){
            cout << "\n" << stack[i];
        }
    }
}

int main() {
    int choice; 
    char ch; 

    Stack_Array ps;

    cout << "\nMain Menu:\n==========\n";
    cout << "1. Push";
    cout << "\n2. Pop";
    cout << "\n3. Traverse";
    cout << "\n4. Quit";

    while(1){
        cout << "\n\nEnter your choice: ";
        cin >> choice; 
        switch (choice)
        {
        case 1:        
            ps.push();
            break;
        case 2: 
            ps.pop();
            break;
        case 3:
            ps.traverse();
            break;
        case 4:
            cout << "Exiting Program!\n";
            exit(1);
        default:
            cout << "\nInvalid Input! Enter correct choice.";
            break;
        }
    }

    return 0;
}



// Output:
/*

Main Menu:
==========
1. Push
2. Pop
3. Traverse
4. Quit

Enter your choice: 1
Enter element to be inserted: 10


Enter your choice: 1
Enter element to be inserted: 20


Enter your choice: 1
Enter element to be inserted: 30


Enter your choice: 1
Enter element to be inserted: 40


Enter your choice: 3
The elements in the stack are:
40
30
20
10

Enter your choice: 2
The Deleted item is: 40

Enter your choice: 2
The Deleted item is: 30

Enter your choice: 3
The elements in the stack are: 
20
10

Enter your choice: 4
Exiting Program!
*/