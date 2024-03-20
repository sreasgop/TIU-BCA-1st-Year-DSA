#include<iostream>

using namespace std;

class linkedlist{
    
    // Structure Declaration for the node
    struct node{
        int info; 
        struct node* link;
    };

    // Private Structure variable decalration
    struct node *start;
    
    public:

    // Constructor Defined
    linkedlist(){
        start = NULL;
    }

    // Public Function Declaraed
    void createlist(int);
    void AddAtBeg(int); 
    void AddAfter(int, int);
    void Delete();
    void Count(); 
    void Search(int);
    void Display();
    void Reverse();
};

    //This Function will create a new linked list of elements
    void linkedlist::createlist(int data){
        struct node *q, *tmp;
        //raw node is created with operator
        tmp = (struct node*) new(struct node);
        tmp->info = data; 
        tmp->link = NULL;

        if(start==NULL)        // if list is empty
            start = tmp; 
        else{
            // element inserted at the end
            q = start; 
            while(q->link!=NULL)
                q = q -> link; 
            q-> link = tmp; 

        }
    }
    // End of createlist()


    // Following function will add new element at the beginning
    void linkedlist::AddAtBeg(int data){
        struct node* tmp; 
        tmp = (struct node*) new(struct node);
        tmp -> info = data; 
        tmp -> link = start; 
        start = tmp;
        this->Display(); 
    }
    // End of AddAtBeg()



    void linkedlist::AddAfter(int data, int pos){
        int i;
        struct node* tmp;  
        struct node* q = start; 
        // Finding the position in linked list to insert
        for(i=0; i<pos-1; i++){
            q = q->link; 
            if(q==NULL){
                cout << "\nThere are less than " << pos << "element";
                return; 
            }
        }
        //End of for

        tmp = (struct node*) new (struct node);
        tmp->link = q->link;
        tmp->info=data;
        q->link=tmp;
        this->Display();
    }
    // End of AddAfter()


    void linkedlist::Delete(){
        struct node *tmp, *q; 
        int data; 
        if (start == NULL){
            cout << "List is empty";
            return ;
        }

        cout << "Enter the element for deletion: ";
        cin >> data;

        if(start->info == data){
            tmp = start; 
            start = start->link;   //First element deleted
            delete(tmp);
            this->Display();
            return;
        }

        
        q = start; 
        while(q->link->link!=NULL){
            if(q->link->info == data){ //Element deleted in between
                tmp = q->link;
                q->link = tmp->link; 
                delete(tmp);
                this->Display();
                return;
            }

            q = q->link;
        }   
        //End of while


        if (q->link->info == data){     //last element deleted
            tmp = q->link;
            delete(tmp);
            q->link = NULL; 
            this->Display();
            return;
        }

        cout << "Element " << data << " not found";
    }
    // End of Delete   

    void linkedlist::Display(){
        struct node *q; 
        if(start==NULL){
            cout << "Linked List is empty.\n";
            return ;
        }
        q = start;
        cout << "List is: ";
        while(q!=NULL){
            cout << q->info << " ";
            q = q->link;
        }
        cout << "\n";
    }

    void linkedlist::Count(){
        int counter = 0;
        
        struct node *current; 
        current = start;

        while(current!=NULL) {
            counter++;
            current = current->link;
        }
        cout << "Number of nodes in the linked list: " << counter << endl;
    }

    void linkedlist::Search(int data){
        int counter = 0;
        struct node *q; 
        
        if(start==NULL){
            cout << "Linked List is empty: Nothing to search for.\n";
            return;
        }
        q = start; 

        while (q!=NULL) {
            counter++;
            if(q->info==data) {
                cout << "Value present at node no: " << counter << endl;
                break;
            }
            q = q->link;    
        }
        if(q==NULL){
            cout << data << " not found in list!" << endl;
        }
    }

    void linkedlist::Reverse() {

        if(start==NULL){
            cout << "Linked List is empty: Nothing to search for.\n";
            return;
        }
        
        struct node *prev = NULL;
        struct node *current = start;
        struct node *next = NULL; 

        while (current != NULL) {
            next = current->link;

            current->link = prev;

            prev = current;
            current = next;
        }

        start = prev;
        cout << "List Reversed." << endl;
        this->Display();
     ;
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
    cout << "7. Reverse\n";
    cout << "8. Search\n";
    cout << "9. Quit\n";
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
            po.Reverse();
            break;
        case 8:
            cout << "Enter element that you want to search: ";
            cin >> m;
            po.Search(m);
            break;
        case 9:
            cout << "Exitting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }
    return 0;
}