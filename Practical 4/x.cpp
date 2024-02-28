#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 10; // Maximum number of vertices

vector<int> graph[MAX_V]; // Adjacency list representation

// Function to generate all subsets of edges
void generateSubsets(int v, int mask, int edges) {
    if (edges == v - 1) {
        // Check if the subset forms a spanning tree
        // (Implement your own validation logic here)
        // If valid, print or store the spanning tree
        // Example: print the edges in the subset
        for (int i = 0; i < v; ++i) {
            if (mask & (1 << i)) {
                cout << "Edge " << i << " included" << endl;
            }
        }
        cout << "-----------------------" << endl;
        return;
    }

    for (int u = 0; u < v; ++u) {
        if (!(mask & (1 << u))) {
            // Include edge (u, v) in the subset
            generateSubsets(v, mask | (1 << u), edges + 1);
        }
    }
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Assume the graph is complete (all pairs of vertices connected)
    // Initialize the adjacency list (you can modify this based on your input)
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (u != v) {
                graph[u].push_back(v);
            }
        }
    }

    // Generate all subsets of edges
    generateSubsets(V, 0, 0);

    return 0;
}
