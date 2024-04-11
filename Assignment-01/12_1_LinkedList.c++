#include<iostream>

using namespace std;

class linkedlist{
    
    struct node{
        int info; 
        struct node* link;
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
        struct node *q, *tmp;
        tmp = (struct node*) new(struct node);
        tmp->info = data; 
        tmp->link = NULL;

        if(start==NULL)
            start = tmp; 
        else{
            q = start; 
            while(q->link!=NULL)
                q = q -> link; 
            q-> link = tmp; 

        }
    }


    void linkedlist::AddAtBeg(int data){
        struct node* tmp; 
        tmp = (struct node*) new(struct node);
        tmp -> info = data; 
        tmp -> link = start; 
        start = tmp;
        this->Display(); 
    }


    void linkedlist::AddAfter(int data, int pos){
        int i;
        struct node* tmp;  
        struct node* q = start; 
        for(i=0; i<pos-1; i++){
            q = q->link; 
            if(q==NULL){
                cout << "\nThere are less than " << pos << "element";
                return; 
            }
        }

        tmp = (struct node*) new (struct node);
        tmp->link = q->link;
        tmp->info=data;
        q->link=tmp;
        this->Display();
    }


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
            start = start->link;
            delete(tmp);
            this->Display();
            return;
        }
        
        q = start; 
        while(q->link->link!=NULL){
            if(q->link->info == data){
                tmp = q->link;
                q->link = tmp->link; 
                delete(tmp);
                this->Display();
                return;
            }

            q = q->link;
        }   

        if (q->link->info == data){ 
            tmp = q->link;
            delete(tmp);
            q->link = NULL; 
            this->Display();
            return;
        }

        cout << "Element " << data << " not found";
    }


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
        int sum = 0;

        struct node *current; 
        current = start;

        while(current!=NULL) {
            sum += current->info;
            counter++;
            current = current->link;
        }
        cout << "Number of nodes in the linked list: " << counter << endl;
        cout << "Sum of all nodes:  " << sum << endl;
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
            cout << "Exitting Program!\n";
            exit(1);
        default:
            cout << "Invalid Input!\n";
            break;
        }
    }
    return 0;
}