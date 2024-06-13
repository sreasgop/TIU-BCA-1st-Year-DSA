#include<iostream>
using namespace std;

struct Node{
    int key; 
    Node* left; 
    Node* right; 

    Node(int data){
        key = data; 
        left = nullptr; 
        right = nullptr; 
    }
};

class BST{
private: 
    Node* root; 

    Node* insertRecursive(Node* root, int key){
        if(root==nullptr){
            return new Node(key);
        }

        if(key < root->key){
            root->left = insertRecursive(root->left, key); 
        } else if(key > root->key){
            root->right = insertRecursive(root->right, key);
        }

        return root; 
    }

    void inorderRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        inorderRecursive(root->left);
        cout << root->key << " -> "; 
        cout << "NULL";
        inorderRecursive(root->right);
    }

    void preorderRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        cout << root->key << " -> "; 
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    void postorderRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->key << " -> "; 
    }

public: 
    BST(){
        root = nullptr; 
    }

    void insert(int key){
        root = insertRecursive(root, key);
    }

    void inorderTraversal(){
        inorderRecursive(root);
    }

    void preorderTraversal(){
        preorderRecursive(root);
    }

    void postorderTraversal(){
        postorderRecursive(root);
    }
};

int main() {
    BST tree; 
    int choice, value; 

    cout << "\nMain Menu:\n===========\n";
    cout << "1. Insert Node\n"; 
    cout << "2. Ineorder Traversal\n"; 
    cout << "3. Preeorder Traversal\n"; 
    cout << "4. Posteorder Traversal\n"; 
    cout << "5. Exit!\n";

    while(true){
        cout << "\nEnter Choice: "; 
        cin >> choice; 
        switch(choice){
            case 1:
                cout << "Enter data: "; 
                cin >> value;
                tree.insert(value); 
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorderTraversal();
                cout << "\n\n"; 
                break;
            case 3: 
                cout << "Preorder Traversal: "; 
                tree.preorderTraversal();
                cout << "\n\n"; 
                break;
            case 4: 
                cout << "Postorder Traversal: "; 
                tree.postorderTraversal();
                cout << "\n\n"; 
                break; 
            case 5:
                cout << "Exiting...\n";
                exit(1);
                break; 
        }
    }

    return 0;
}