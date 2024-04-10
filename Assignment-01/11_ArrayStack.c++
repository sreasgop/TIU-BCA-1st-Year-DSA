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
        cout << "\nEnter element to be inserted: ";
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
        cout << "\nThe Deleted item is: " << item;
    }
}

void Stack_Array::traverse(){
    int i; 
    if(top==-1){
        cout << "\nStack Empty";
    } else {
        cout << "\n\nThe elements in the stack are: ";
        for(i=top; i>=0; i--){
            cout << "\n" << stack[i];
        }
    }
}

int main() {
    int choice; 
    char ch; 
    
    // Declaring an object to the class
    Stack_Array ps;

    do{
        // A menu for stack operation
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Traverse";
        cout << "\nEnter your choice: ";
        cin >> choice; 
        switch (choice)
        {
        case 1:         // Calling push function by class object
            ps.push();
            break;
        case 2: 
            ps.pop();
            break;
        case 3:
            ps.traverse();
            break;
        default:
            cout << "\nInvalid Input! Enter correct choice.";
            break;
        }
        cout << "\n\nPress(y/Y) to continue: ";
        cin >> ch;
    }while( ch=='y' || ch=='Y');

    return 0;
}