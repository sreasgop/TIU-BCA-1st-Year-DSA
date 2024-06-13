#include<iostream>

using namespace std;

class Queue {

    struct node {
        int data; 
        struct node* link;
    };

    struct node *front, *rear;

public:
    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Public Function Declarations
    void enqueue(int);
    void dequeue();
    void display();
    bool isEmpty();
    int getFront();
};

void Queue::enqueue(int data) {
    struct node* tmp;
    tmp = new struct node;
    tmp->data = data;
    tmp->link = NULL;

    if (rear == NULL) {
        front = rear = tmp;
    } else {
        rear->link = tmp;
        rear = tmp;
    }
    cout << "Enqueued " << data << " to the queue.\n";
    this->display();
}

void Queue::dequeue() {
    if (front == NULL) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    struct node* tmp;
    tmp = front;
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }
    cout << "Dequeued " << tmp->data << " from the queue.\n";
    delete(tmp);
    this->display();
}

void Queue::display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    struct node* tmp = front;
    cout << "Queue elements are: ";
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << "\n";
}

bool Queue::isEmpty() {
    return front == NULL;
}

int Queue::getFront() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return -1;
    }
    return front->data;
}

int main() {
    int choice, data;
    Queue q;
    cout << "\nMain Menu:\n";
    cout << "==========\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Check if Empty\n";
    cout << "5. Get Front Element\n";
    cout << "6. Quit\n";
    
    while (1) {
        cout << "\nEnter Choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "Enter the element: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            if (q.isEmpty()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Queue is not empty.\n";
            }
            break;
        case 5:
            data = q.getFront();
            if (data != -1) {
                cout << "Front element is: " << data << "\n";
            }
            break;
        case 6:
            cout << "Exiting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }

    return 0;
}
