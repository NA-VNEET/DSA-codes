#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (distance, vertex)


void dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > d + weight) {
                dist[v] = d + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Display shortest distances and paths
    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "To " << i << " : " << dist[i] << endl;

    cout << "\nPaths from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        if (i == source) continue;
        cout << "Path to " << i << ": ";
        stack<int> path;
        int v = i;
        while (v != -1) {
            path.push(v);
            v = parent[v];
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);
    cout << "Enter edges in format: from to weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove this line if the graph is directed
    }

    dijkstra(V, adj, 0); // source = 0
    return 0;
}
