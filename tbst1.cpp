#include <iostream>

struct Node {
    struct Node *left, *right;
    int info;
    bool lthread;
    bool rthread;
};

// Insert a Node in Binary Threaded Tree 
Node *insert(struct Node *root, int ikey) {
    Node *ptr = root;
    Node *par = nullptr;
    while (ptr != nullptr) {
        if (ikey == ptr->info) {
            std::cout << "Duplicate Key !" << std::endl;
            return root;
        }
        par = ptr;
        if (ikey < ptr->info) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node *tmp = new Node;
    tmp->info = ikey;
    tmp->lthread = true;
    tmp->rthread = true;

    if (par == nullptr) {
        root = tmp;
        tmp->left = nullptr;
        tmp->right = nullptr;
    } else if (ikey < par->info) {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
    } else {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = false;
        par->right = tmp;
    }

    return root;
} 

// Returns inorder successor using rthread 
Node *inorderSuccessor(struct Node *ptr) {
    if (ptr->rthread == true)
        return ptr->right;

    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
} 

// Printing the threaded tree 
void inorder(struct Node *root) {
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    Node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != nullptr) {
        std::cout << ptr->info << " ";
        ptr = inorderSuccessor(ptr);
    }

} 

// Driver Program 
int main() {
    struct Node *root = nullptr; 

    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 

    inorder(root); 

    return 0; 
}
