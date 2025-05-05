#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    cout << src << " ";
    visited[src] = true;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[src][i] == 1 && !visited[i]) {
            dfs(i, adj, visited);
        }
    }
}

void bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (int i = 0; i < adj.size(); i++) {
            if (adj[temp][i] == 1 && !visited[i]) {
                visited[i] = true;  
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V, vector<int>(V, 0));  // 0-based adjacency matrix

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    vector<bool> visitedDFS(V, false);
    cout << "\nDFS traversal: ";
    dfs(0, adj, visitedDFS);
    cout << "\n";

    vector<bool> visitedBFS(V, false);
    cout << "BFS traversal: ";
    bfs(0, adj, visitedBFS);
    cout << "\n";

    // Count connected components
    vector<bool> visitedComp(V, false);
    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!visitedComp[i]) {
            components++;
            cout << "Component " << components << ": ";
            dfs(i, adj, visitedComp);
            cout << "\n";
        }
    }

    if (components == 1) {
        cout << "The graph is connected.";
    } else {
        cout << "The graph is NOT connected."<<endl;
        cout << "Number of connected components: " << components << endl;
    }

    return 0;
}
