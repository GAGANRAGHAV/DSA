#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int ht;
};

Node* root = nullptr;

Node *create(int x) {
    Node *newnode = new Node;
    newnode->data = x;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

int height(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int balancefactor(Node *root) {
    int lh = height(root->left);
    int rh = height(root->right);

    return lh - rh;
}

Node *leftrotate(Node *root) {
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;

    root->ht = height(root);
    newroot->ht = height(newroot);

    return newroot;
}

Node *rightrotate(Node *root) {
    Node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;

    root->ht = height(root);
    newroot->ht = height(newroot);

    return newroot;
}

Node* insert(int data, Node* root) {
    if (root == nullptr) {
        return create(data);
    } else if (root->data < data) {
        root->right = insert(data, root->right);

        if (balancefactor(root) == -2) {
            if (data > root->right->data) {
                root = leftrotate(root);
            } else {
                root->right = rightrotate(root->right);
                root = leftrotate(root);
            }
        }
    } else {
        root->left = insert(data, root->left);

        if (balancefactor(root) == 2) {
            if (data < root->left->data) {
                root = rightrotate(root);
            } else {
                root->left = leftrotate(root->left);
                root = rightrotate(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans; 
    if (root == nullptr) {
        return ans; 
    }
    
    queue<Node*> q; 
    q.push(root); 

    while (!q.empty()) {
        int size = q.size(); 
        vector<int> level; 

        for (int i = 0; i < size; i++) {
            Node* node = q.front(); 
            q.pop(); 
            level.push_back(node->data); 

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        ans.push_back(level); 
    }
    return ans; 
}

void printAns(vector<vector<int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    root = insert(50, root);
    root = insert(30, root);
    root = insert(70, root);
    root = insert(20, root);
    root = insert(40, root);
    root = insert(60, root);
    root = insert(80, root);

    cout << "Level Order Traversal: " << endl;
    vector<vector<int>> ans = levelOrder(root);
    printAns(ans);

    return 0;
}
