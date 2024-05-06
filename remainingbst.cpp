#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

int height(Node* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is 0
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

void mirror(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

Node* clone(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    // Create a new node with the same data
    Node* newNode = new Node(root->data);
    // Recursively clone left and right subtrees
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root; // Key not found
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the key to be deleted found

        // Case 1: Node has no children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: Node has one child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 30
    root = deleteNode(root, 30);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Height of the BST
    cout << "Height of the tree: " << height(root) << endl;

    // Mirror the BST
    mirror(root);
    cout << "Inorder traversal after mirroring: ";
    inorderTraversal(root);
    cout << endl;

    // Clone the BST
    Node* clonedRoot = clone(root);
    cout << "Inorder traversal of cloned tree: ";
    inorderTraversal(clonedRoot);
    cout << endl;

    return 0;
}
