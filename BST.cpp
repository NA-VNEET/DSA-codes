#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* add_Node(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (root->data > val) {
        root->left = add_Node(root->left, val);
    } else if (root->data < val) {
        root->right = add_Node(root->right, val); 
    }
    return root;
}

// Recursive Traversals
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); // fixed typo
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right); // fixed typo
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right); 
    cout << root->data << " ";
}

//iterative traversal
void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (!st.empty() || curr != NULL) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderIterative(Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

void postorderIterative(Node* root) {
    if (root == NULL) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right); 
    }
    while (!st2.empty()) {
        Node* curr = st2.top();
        st2.pop();
        cout << curr->data << " ";
    }
}

Node* findmin(Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data > val) {
        root->left = deleteNode(root->left, val);
    } else if (root->data < val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        Node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool checkEqual(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;
    if(root1->data != root2->data){
        return false;
    }
    return checkEqual(root1->left,root2->left) && checkEqual(root1->right,root2->right);
}

bool checkMirror(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;
    if(root1->data != root2->data){
        return false;
    }
    return checkMirror(root1->left,root2->right) && checkMirror(root1->right,root2->left);

}

int height(Node* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left,right);
}

int main() {
    
    Node* root = NULL;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = add_Node(root, val);
    }

    cout << "\nRecursive Inorder Traversal: ";
    inorder(root);
    cout << "\nRecursive Preorder Traversal: ";
    preorder(root);
    cout << "\nRecursive Postorder Traversal: ";
    postorder(root);

    cout << "\nIterative Inorder Traversal: ";
    inorderIterative(root);
    cout << "\nIterative Preorder Traversal: ";
    preorderIterative(root);
    cout << "\nIterative Postorder Traversal: ";
    postorderIterative(root);
    cout << "\n";

    return 0;
}
