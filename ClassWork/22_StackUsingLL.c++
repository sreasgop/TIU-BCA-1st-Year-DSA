#include<iostream>

using namespace std;

class Stack {
    
    struct node {
        int data; 
        struct node* link;
    };

    struct node *top;
    
public:
   
    Stack() {
        top = NULL;
    }

    void push(int);
    void pop();
    void display();
    bool isEmpty();
};

void Stack::push(int data) {
    struct node* tmp;
    tmp = new struct node;
    tmp->data = data;
    tmp->link = top;
    top = tmp;
    cout << "Pushed " << data << " onto the stack.\n";
    this->display();
}

void Stack::pop() {
    if (top == NULL) {
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }

    struct node* tmp;
    tmp = top;
    top = top->link;
    cout << "Popped " << tmp->data << " from the stack.\n";
    delete(tmp);
    this->display();
}

void Stack::display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }

    struct node* tmp = top;
    cout << "Stack elements are: ";
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << "\n";
}

bool Stack::isEmpty() {
    return top == NULL;
}

int main() {
    int choice, data;
    Stack s;
    cout << "\nMain Menu:\n";
    cout << "==========\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Display\n";
    cout << "4. Check if Empty\n";
    cout << "5. Quit\n";
    
    while (1) {
        cout << "\nEnter Choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "Enter the element: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            if (s.isEmpty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack is not empty.\n";
            }
            break;
        case 5:
            cout << "Exitting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }

    return 0;
}
