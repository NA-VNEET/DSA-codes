// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> adj,vector<bool> &visited,stack<int> &st){
    visited[node] = true;
    for(auto it:adj[node]){
        if(visited[it] == false){
            dfs(it,adj,visited,st);
        }
    }
    st.push(node);
}

int main(){

    int V;
    cout<<"Enter number of Veritces: ";
    cin>>V;
    int E;
    cout<<"Enter number of Edges: ";
    cin>>E;
    vector<vector<int>> adj(V);
    for(int i = 0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i = 0;i<V;i++){
        if(visited[i] == false){
            dfs(i,adj,visited,st);
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
