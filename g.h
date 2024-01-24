#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> adj) {

    cout << "Adjacency List: " << endl;
    for(int i=1;i<adj.size();i++) {
        cout << i << ": ";
        for(int j=0;j<adj[i].size();j++) {
            cout<<adj[i][j]<<" ";
        }
        cout << endl;
    }

    cout << endl;
}

vector<vector<int>> createGraph(int n, int e) {
    vector<vector<int>> adj(n+1);

    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

// create a graph from adjacency matrix

vector<vector<bool>> createMaze(int n, int e) {
    vector<vector<bool>> graph(n, vector<bool>(n, 1));

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 0;
    }

    return graph;
}
