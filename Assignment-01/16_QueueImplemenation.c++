// Question:
// Write a program to implement the Queue data structure. 



// Code:

#include<iostream>
using namespace std;

int queue[10], n = 10, front = -1, rear = -1; 

void Insert(){
    int val; 
    if(rear == n-1){
        cout << "Queue Overflow\n";
        return;
    } else if (front == -1){
        front = 0;
    }
    cout << "Insert element in Queue: ";
    cin >> val; 
    queue[++rear] = val;
}

void Delete(){
    if(front == -1 ){
        cout << "Queue is empty\n";
        return;
    }else if(front > rear){
        cout << "Queue Underflow\n";
        return;
    }else {
        cout << "Element deleted from queue is: " << queue[front] << endl; 
        front++;
    }
}

void Display(){
    if(front == -1){
        cout << "Queue is empty";
    } else {
        cout << "Queue elements are: ";
        for(int i = front; i<=rear; i++){
            cout << queue[i] << " ";
        }
        cout << "\n";
    }   
}

int main() {
    int ch; 
    cout << "\nMain Menu:\n===========" << endl;
    cout << "1. Insert elements in Queue.\n";
    cout << "2. Delete elements from Queue.\n";
    cout << "3. Display Queue.\n";
    cout << "4. Exit\n";
    do{
        cout << "\nEnter your choice: ";
        cin >> ch; 
        switch(ch){
            case 1: 
                Insert();
                break; 
            case 2: 
                Delete();
                break; 
            case 3: 
                Display();
                break; 
            case 4: 
                cout << "Exiting Program\n";
                break;
            default:
                cout << "Invalid Input!";
                break;
        }
    }while(ch!=4);

    return 0;
}



// Output:
/*
Main Menu:
===========
1. Insert elements in Queue.
2. Delete elements from Queue.
3. Display Queue.
4. Exit

Enter your choice: 1
Insert element in Queue: 10

Enter your choice: 1
Insert element in Queue: 20

Enter your choice: 1
Insert element in Queue: 30

Enter your choice: 1
Insert element in Queue: 40

Enter your choice: 3
Queue elements are: 10 20 30 40

Enter your choice: 2
Element deleted from queue is: 10

Enter your choice: 3
Queue elements are: 20 30 40

Enter your choice: 4
Exiting Program
*/