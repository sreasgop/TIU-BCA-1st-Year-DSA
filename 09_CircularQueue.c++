#include<iostream>
using namespace std;

int cqueue[100], front = -1, rear = -1, n = 5;

void insertcq(int val){
    if((front==0 && rear==n-1) || front == rear+1){
        cout << "Queue Overflow\n";
        return;
    } else if(front==-1){
        front = 0; 
        rear = 0; 
    } else if(rear == n-1){
        rear = 0;
    } else {
        rear = rear + 1;
    }
    cqueue[rear] = val;
}

void deletecq(){
    if(front == -1){
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Element deleted from queue is: " << cqueue[front] << endl;
    if(front==rear){
        front = -1; 
        rear = -1;
    } else {
        if(front == n-1){
            front = 0; 
        } else{
            front = front + 1;
        }
    }
}

void displaycq(){
    int f=front, r=rear; 
    if(front == -1){
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements are: ";
    if(f<=r){
        while(f<=r){
            cout << cqueue[f] << " ";
            f++;
        }
    } else {
        while(f<=n-1){
            cout << cqueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}

int main() {
    int ch, val; 
    cout << "Main Menu\n=========\n";
    cout << "1. Insert cq\n";
    cout << "2. Delete cq\n";
    cout << "3. Display cq\n";
    cout << "4. Exit\n";
    do{
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1: 
                cout << "Input for insertion: ";
                cin >> val;
                insertcq(val);
                break;
            case 2: 
                deletecq();
                break;
            case 3:
                displaycq();
                break;
            case 4:
                cout << "Exiting Program.\n";
                break;
            default: 
                cout << "Invalid Choice!\n";
                break;
        }
        
    }while(ch!=4);

    return 0;
}