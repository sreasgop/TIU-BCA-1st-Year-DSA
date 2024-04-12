#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            new_node->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    void remove(int key) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;


        while (current->data != key) {
            if (current->next == head) {
                cout << "Key not found in the list" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }


        if (current->next == head && prev == nullptr) {
            head = nullptr;
            delete current;
            cout << "Node with data " << key << " removed successfully" << endl;
            return;
        }


        if (current == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
            delete current;
        } else if (current->next == head) {
            prev->next = head;
            delete current;
        } else {
            prev->next = current->next;
            delete current;
        }

        cout << "Node with data " << key << " removed successfully" << endl;
    }

    void display() {
        if (!head) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, data;

    while (true) {
        cout << "\nCircular Linked List Operations:" << endl;
        cout << "1. Append" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to append: ";
                cin >> data;
                cll.append(data);
                break;
            case 2:
                cout << "Enter data to remove: ";
                cin >> data;
                cll.remove(data);
                break;
            case 3:
                cout << "Circular Linked List:" << endl;
                cll.display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
