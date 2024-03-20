#include<iostream>

using namespace std;

class linkedlist{
    
    // Structure Declaration for the node
    struct node{
        int info; 
        struct node* prev;  // Pointer to the previous node
        struct node* next;  // Pointer to the next node
    };

    // Private Structure variable declaration
    struct node *start;
    
    public:

    // Constructor Defined
    linkedlist(){
        start = NULL;
    }

    // Public Function Declared
    void createlist(int);
    void AddAtBeg(int); 
    void AddAfter(int, int);
    void Delete();
    void Count(); 
    void Search(int);
    void Display();
    void Reverse();
};

// Function Definitions

void linkedlist::createlist(int data){
    struct node *tmp = new node;
    tmp->info = data; 
    tmp->prev = NULL;
    tmp->next = NULL;

    if(start == NULL)
        start = tmp; 
    else{
        struct node *q = start;
        while(q->next != NULL)
            q = q->next;
        q->next = tmp;
        tmp->prev = q;
    }
}

void linkedlist::AddAtBeg(int data){
    struct node* tmp = new node;
    tmp->info = data; 
    tmp->prev = NULL;
    tmp->next = start;

    if(start != NULL)
        start->prev = tmp;
    
    start = tmp;
}

void linkedlist::AddAfter(int data, int pos){
    struct node* tmp = new node;
    tmp->info = data;
    struct node* q = start;
    
    for(int i = 0; i < pos - 1 && q != NULL; i++)
        q = q->next;

    if(q == NULL){
        cout << "\nThere are less than " << pos << " elements." << endl;
        return; 
    }

    tmp->next = q->next;
    tmp->prev = q;
    if(q->next != NULL)
        q->next->prev = tmp;
    q->next = tmp;
}

void linkedlist::Delete(){
    if (start == NULL){
        cout << "\n\nList is empty";
        return ;
    }

    int data; 
    cout << "\n\nEnter the element for deletion: ";
    cin >> data;

    struct node *tmp = start;

    // Check if the element to be deleted is the first node
    if(tmp->info == data){
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        delete tmp;
        return;
    }

    // Traverse the list to find the element to be deleted
    while(tmp != NULL && tmp->info != data)
        tmp = tmp->next;

    if(tmp == NULL){
        cout << "\n\nElement " << data << " not found";
        return;
    }

    // Adjust the links to delete the node
    if(tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;

    delete tmp;
}

void linkedlist::Display(){
    if(start == NULL){
        cout << "\n\nLinked List is empty.";
        return ;
    }
    struct node *q = start;
    cout << "\n\nList is: ";
    while(q != NULL){
        cout << q->info << " ";
        q = q->next;
    }
    cout << endl;
}

void linkedlist::Count(){
    int counter = 0;
    struct node *current = start;

    while(current != NULL) {
        counter++;
        current = current->next;
    }
    cout << "Number of nodes in the linked list: " << counter << endl;
}

void linkedlist::Search(int data){
    int counter = 0;
    struct node *q = start;

    while (q != NULL) {
        counter++;
        if(q->info == data) {
            cout << "Value present at node no: " << counter << endl;
            return;
        }
        q = q->next;    
    }
    cout << data << " not found in list!" << endl;
}

void linkedlist::Reverse() {
    if(start == NULL){
        cout << "\n\nLinked List is empty: Nothing to reverse.";
        return;
    }

    struct node *tmp = NULL;
    struct node *current = start;

    while (current != NULL) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    if(tmp != NULL)
        start = tmp->prev;
}

int main() {
    int choice, n, m, position, i; 
    linkedlist po;
    while(1){
        cout << "\nMain Menu:\n";
        cout << "==========\n";
        cout << "1. Create list\n";
        cout << "2. Add at Beginning\n";
        cout << "3. Add After\n";
        cout << "4. Delete\n";
        cout << "5. Display\n";
        cout << "6. Count\n";
        cout << "7. Reverse\n";
        cout << "8. Search\n";
        cout << "9. Quit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many nodes do you want: ";
            cin >> n; 
            cout << "Enter the elements: ";
            for ( i = 0; i < n; i++)
            {
                cin >> m;
                po.createlist(m);
            }
            break;
        case 2:
            cout << "\n\nEnter the element: ";
            cin >> m;
            po.AddAtBeg(m);
            break;
        case 3:
            cout << "\n\nEnter the element: ";
            cin >> m;
            cout << "\n\nEnter the position after which element is inserted: ";
            cin >> position;
            po.AddAfter(m, position);
            break;
        case 4:
            po.Delete();
            break;
        case 5:
            po.Display();
            break;
        case 6: 
            po.Count();
            break;
        case 7:
            po.Reverse();
            break;
        case 8:
            cout << "Enter element that you want to search: ";
            cin >> m;
            po.Search(m);
            break;
        case 9:
            cout << "Exiting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }
    return 0;
}
