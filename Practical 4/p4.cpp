// find all spanning trees of a complete directed graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i != j) {
                graph[i][j] = 1;
            }
        }
    }

    // find all spanning trees
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> edges;
        for (int i = 0; i < n; i++) {   
            if (mask & (1 << i)) {
                edges.push_back(i);
            }
        }
        if (edges.size() == n - 1) {
            // check if the subset forms a spanning tree
            // (implement your own validation logic here)
            // if valid, print or store the spanning tree
            // example: print the edges in the subset
            for (int i = 0; i < edges.size(); i++) {
                cout << "Edge " << edges[i] << " included" << endl;
            }
            cout << "-----------------------" << endl;
        }
    }

    return 0;
}
