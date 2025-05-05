#include <bits/stdc++.h>
using namespace std;

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

    vector<vector<int>> adj(V + 1);  // 1-based indexing
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Enter first Node: ";
        cin >> u;
        cout << "Enter second Node: ";
        cin >> v;
        adj[u].push_back(v);
    }

    vector<int> indeg(V + 1, 0);

    for (int i = 1; i <= V; i++) {
        for (auto it : adj[i]) {
            indeg[it]++;
        }
    }

  
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= V; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> ans;
    int cnt = 0;

   
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        ans.push_back(temp);
        cnt++;

        for (auto it : adj[temp]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                pq.push(it);
            }
        }
    }

    if (cnt != V) {
        cout << "Deadlock condition is there (Cycle detected)." << endl;
    } else {
        cout << "Topological order: ";
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
