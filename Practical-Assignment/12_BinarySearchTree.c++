#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int data) : key(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = insertRecursive(root->right, key);
        }

        return root;
    }

    void inorderRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderRecursive(root->left);
        std::cout << root->key << " ";
        inorderRecursive(root->right);
    }

    void preorderRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->key << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    void postorderRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        std::cout << root->key << " ";
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    void inorderTraversal() {
        inorderRecursive(root);
    }

    void preorderTraversal() {
        preorderRecursive(root);
    }

    void postorderTraversal() {
        postorderRecursive(root);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "\nBinary Search Tree Traversal:\n=============================\n\n";

    std::cout << "Inorder traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    tree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    tree.postorderTraversal();
    std::cout << std::endl;

    return 0;
}
