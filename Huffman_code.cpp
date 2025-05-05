#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    Node *left,*right;

    Node(char c){
        ch = c;
        left = right = NULL;
    }
};

void print(Node* root,string s){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->ch<<" : "<<s<<endl;
        return;
    }
    print(root->left,s+'0');
    print(root->right,s+'1');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE   // If online judge is not defined
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int n;//number of element to add
    cin>>n;
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i = 0;i<n;i++){
        char ch; //character
        int x; //frequency
        cout<<"Enter character: ";
        cin>>ch;
        cout<<"Enter Frequency: ";
        cin>>x;
        Node* temp = new Node(ch);
        pq.push({x,temp});
    }

    while(pq.size() != 1){
        Node* left = pq.top().second;
        int l = pq.top().first;
        pq.pop();
        Node* right = pq.top().second;
        int r = pq.top().first;
        pq.pop();
        Node* temp = new Node('0');
        temp->left = left;
        temp->right = right;
        pq.push({l+r,temp});
    }

    print(pq.top().second,"");
    
    return 0;
}
