// Question: 
// Write down the following functions/algorithm for a linear linked list and double linked list. 
// a) Insert a node at the beginning of the list 
// b) Delete a node at the end of the list 
// c) Append a node at the end of the list 
// d) Insert a node at any middle position of the list 
// e) Delete a node from any middle position of the list 
// f) Count number of nodes present in the list and find the sum of all nodes 



// Code: 

#include<iostream>

using namespace std;

class linkedlist{

    struct node{
        int info; 
        struct node* prev;
        struct node* next;
    };

    struct node *start;
    
    public:

    linkedlist(){
        start = NULL;
    }

    void createlist(int);
    void AddAtBeg(int); 
    void AddAfter(int, int);
    void Delete();
    void Count(); 
    void Display();
};


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
    this->Display();
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

    this->Display();
}


void linkedlist::Delete(){
    if (start == NULL){
        cout << "List is empty";
        return ;
    }

    int data; 
    cout << "Enter the element for deletion: ";
    cin >> data;

    struct node *tmp = start;

    if(tmp->info == data){
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        delete tmp;
        return;
    }

    while(tmp != NULL && tmp->info != data)
        tmp = tmp->next;

    if(tmp == NULL){
        cout << "\n\nElement " << data << " not found";
        return;
    }

    if(tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;

    delete tmp;
    this->Display();
}

void linkedlist::Display(){
    if(start == NULL){
        cout << "Linked List is empty.";
        return ;
    }
    struct node *q = start;
    cout << "List is: ";
    while(q != NULL){
        cout << q->info << " ";
        q = q->next;
    }
    cout << endl;
}

void linkedlist::Count(){
    int counter = 0;
    int sum = 0;

    struct node *current = start;

    while(current != NULL) {
        sum += current->info;
        counter++;
        current = current->next;
    }
    cout << "Number of nodes in the linked list: " << counter << endl;
    cout << "Sum of all nodes in the linked list: " << sum << endl;
}


int main() {
    int choice, n, m, position, i; 
    linkedlist po;
    cout << "\nMain Menu:\n";
    cout << "==========\n";
    cout << "1. Create list\n";
    cout << "2. Add at Beginning\n";
    cout << "3. Add After\n";
    cout << "4. Delete\n";
    cout << "5. Display\n";
    cout << "6. Count\n";
    cout << "7. Quit\n";
    while(1){
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
            cout << "Enter the element: ";
            cin >> m;
            po.AddAtBeg(m);
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> m;
            cout << "Enter the position after which element is inserted: ";
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
            cout << "Exiting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }
    return 0;
}



// Output:

/*
Main Menu:
==========
1. Create list
2. Add at Beginning
3. Add After
4. Delete
5. Display
6. Count
7. Quit

Enter Choice: 1
How many nodes do you want: 5
Enter the elements: 10 20 30 40 50

Enter Choice: 2
Enter the element: 100
List is: 100 10 20 30 40 50

Enter Choice: 3
Enter the element: 99
Enter the position after which element is inserted: 4
List is: 100 10 20 30 99 40 50

Enter Choice: 4
Enter the element for deletion: 99
List is: 100 10 20 30 40 50

Enter Choice: 5
List is: 100 10 20 30 40 50

Enter Choice: 6
Number of nodes in the linked list: 6
Sum of all nodes in the linked list: 250

Enter Choice: 7
Exiting Program!
*/