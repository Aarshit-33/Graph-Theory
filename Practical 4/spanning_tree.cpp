#include <bits/stdc++.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest;

    Edge(int s, int d) : src(s), dest(d) {}
};

vector<vector<Edge>> spanningTrees;

// Function to generate all combinations of V-1 edges from the given set of edges
void generateCombinations(vector<Edge>& edges, int V, int E, int index, int count, vector<Edge>& currentCombination, vector<vector<Edge>>& allCombinations) {
    if (count == V - 1) {
        allCombinations.push_back(currentCombination);
        return;
    }

    if (index == E) {
        return;
    }

    // Include the current edge in the combination
    currentCombination.push_back(edges[index]);
    generateCombinations(edges, V, E, index + 1, count + 1, currentCombination, allCombinations);

    // Exclude the current edge from the combination
    currentCombination.pop_back();
    generateCombinations(edges, V, E, index + 1, count, currentCombination, allCombinations);
}

// Function to check if a set of edges forms a valid spanning tree
bool isSpanningTree(const vector<Edge>& edges, int V) {
    vector<int> parent(V, -1);

    for (const Edge& edge : edges) {
        int x = edge.src;
        int y = edge.dest;

        int rootX = x;
        int rootY = y;

        while (parent[rootX] != -1) {
            rootX = parent[rootX];
        }

        while (parent[rootY] != -1) {
            rootY = parent[rootY];
        }

        if (rootX == rootY) {
            return false; // Cycle detected, not a spanning tree
        }

        parent[rootX] = rootY;
    }

    return true;
}


void printAdjacencyMatrix(const vector<Edge>& edges, int V) {
    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0));

    for (const Edge& edge : edges) {
        adjacencyMatrix[edge.src][edge.dest] = 1;
        adjacencyMatrix[edge.dest][edge.src] = 1;
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void findValidSpanningTree(vector<vector<Edge>>& allCombinations, int V) {
    cout << "All possible spanning trees:\n";
    
    for (const vector<Edge>& combination : allCombinations) {

        if(isSpanningTree(combination, V)){

            spanningTrees.push_back(combination);
        }
    }
}

void printSpanningTrees(int V) {
    cout << "All spanning trees: " << endl;
    int x = 1;
    for (const vector<Edge>& tree : spanningTrees) {
        cout << "Spanning tree " << x++ << ": " << endl;
        printAdjacencyMatrix(tree, V);
    }
}

int main() {
    int V, E;

    cout << "Enter the number of vertices (V) and edges (E) in the graph: ";
    cin >> V;
    E = V*(V-1)/2;
    vector<Edge> edges;
    vector<vector<Edge>> allCombinations;
    vector<Edge> currentCombination;

    for(int i=0; i<V; i++){
        for(int j=i+1; j<V; j++){
            if(i==j) continue;
            edges.emplace_back(i, j);
        }
    }

    generateCombinations(edges, V, E, 0, 0, currentCombination, allCombinations);

    findValidSpanningTree(allCombinations, V);

    // Calculate the total number of spanning trees using the pow() function
    cout << "Total number of spanning trees: " << pow(V, V-2) << endl;

    printSpanningTrees(V);

    return 0;
}
