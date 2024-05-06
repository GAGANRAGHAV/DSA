#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
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

vector<int> levelorder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    vector<int>ans;

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp->left!=nullptr)
        {
            q.push(temp->left);
        }
        if(temp->right!=nullptr)
        {
            q.push(temp->right);
        }
        ans.push_back(temp->data);
    }

    return ans;
}

void inorderrecurcive(Node* root, vector<int>& ans)
{
    if(root==nullptr)
    {
        return;
    }
    inorderrecurcive(root->left, ans);
    ans.push_back(root->data);
    inorderrecurcive(root->right, ans);
}

void preorderrecurcive(Node* root, vector<int>& ans)
{
    if(root==nullptr)
    {
        return;
    }
    ans.push_back(root->data);
    preorderrecurcive(root->left, ans);
    preorderrecurcive(root->right, ans);
}

void postorderrecurcive(Node* root, vector<int>& ans)
{
    if(root==nullptr)
    {
        return ;
    }
    postorderrecurcive(root->left, ans);
    postorderrecurcive(root->right, ans);
    ans.push_back(root->data);
}

vector<int> preorderiterative(Node* root)
{
    if(root==nullptr)
    {
        return {};
    }
    vector<int>ans;

    stack<Node*>st;

    st.push(root);
    while (!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->right!=nullptr)
        {
            st.push(temp->right);
        }
        if(temp->left!=nullptr)
        {
            st.push(temp->left);
        }
    }

    return ans;   
}

vector<int> inorderiterative(Node* root)
{
    vector<int>result;
    if(root==nullptr)
    {
        return result;
    }

    stack<Node*>s;

    Node* curr = root;

    while (!s.empty() || curr!=nullptr)
    {
        while (curr!=nullptr)
        {
            s.push(curr);
            curr= curr->left;
        }

        curr = s.top();
        s.pop();
        result.push_back(curr->data);

        curr= curr->right;   
    }

    return result;  
}

vector<int> postorderiterative(Node* root)
{
    vector<int>ans;

    if(root==nullptr)
    {
        return ans;
    }

    stack<Node*>st1;
    stack<Node*>st2;

    st1.push(root);

    while (!st1.empty())
    {
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left)
        {
            st1.push(temp->left);
        }
        if(temp->right)
        {
            st1.push(temp->right);
        }
    }
    
    while (!st2.empty())
    {
        Node* temp = st2.top();
        ans.push_back(temp->data);
        st2.pop();
    }

    return ans;  
}

int main() {
    Node* root = nullptr;

    // Insertion in BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform traversals
    cout << "Level order traversal: ";
    vector<int> levelOrder = levelorder(root);
    for (int val : levelOrder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder recursive: ";
    vector<int> inorderRecursive;
    inorderrecurcive(root, inorderRecursive);
    for (int val : inorderRecursive) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder recursive: ";
    vector<int> preorderRecursive;
    preorderrecurcive(root, preorderRecursive);
    for (int val : preorderRecursive) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder recursive: ";
    vector<int> postorderRecursive;
    postorderrecurcive(root, postorderRecursive);
    for (int val : postorderRecursive) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder iterative: ";
    vector<int> preorderIterative = preorderiterative(root);
    for (int val : preorderIterative) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder iterative: ";
    vector<int> inorderIterative = inorderiterative(root);
    for (int val : inorderIterative) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder iterative: ";
    vector<int> postorderIterative = postorderiterative(root);
    for (int val : postorderIterative) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
