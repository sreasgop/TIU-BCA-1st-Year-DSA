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
    cout << "Main Menu:\n===========" << endl;
    cout << "1. Insert elements in Queue.\n";
    cout << "2. Delete elements from Queue.\n";
    cout << "3. Display Queue.\n";
    cout << "4. Exit\n";
    do{
        cout << "Enter your choice: ";
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