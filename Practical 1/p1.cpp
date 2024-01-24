#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> adj) {
    cout << "Adjacency Matrix: " << endl;
    for(int i=1;i<adj.size();i++) {
        for(int j=1;j<adj[i].size();j++) {
            cout<<adj[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> graphCreation(int n,int e) {
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=1;i<=e;i++) {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return adj;
}

// union of two graphs
vector<vector<int>> unionGraph(vector<vector<int>> adj1,vector<vector<int>> adj2) {

    int s1 = adj1.size();
    int s2 = adj2.size();
    int r;
    
    vector<vector<int>> uni;
    if(s1 > s2) {
        uni = adj1;
        r = s2;
    }
    else {
        uni = adj2;
        r = s1;
    }

    for(int i=1;i<r;i++) {
        for(int j=1;j<r;j++) {
            if(adj1[i][j]==1 || adj2[i][j]==1) {
                uni[i][j]=1;
            }
        }
    }
    
    return uni;
}

// intersection of two graphs
vector<vector<int>> interGraph(vector<vector<int>> adj1,vector<vector<int>> adj2) {

    int s1 = adj1.size();
    int s2 = adj2.size();
    int r;
    
    vector<vector<int>> inter;
    if(s1 > s2) {
        inter = vector<vector<int>>(s1,vector<int>(s1,0));
        r = s2;
    }
    else {
        inter = vector<vector<int>>(s2,vector<int>(s2,0));
        r = s1;
    }

    for(int i=1;i<r;i++) {
        for(int j=1;j<r;j++) {
            if(adj1[i][j]==1 && adj2[i][j]==1) {
                inter[i][j]=1;
            }
        }
    }
    
    return inter;
}

// difference of two graphs
vector<vector<int>> diffGraph(vector<vector<int>> adj1,vector<vector<int>> adj2) {

    int s1 = adj1.size();
    int s2 = adj2.size();
    int r = min(s1,s2);
    
    vector<vector<int>> diff;
    diff = adj1;
    
    for(int i=1;i<r;i++) {
        for(int j=1;j<r;j++) {
            if(adj1[i][j]==1 && adj2[i][j]==1) {
                diff[i][j]=0;
            }
        }
    }
    
    return diff;
}

// symmetric difference of two graphs
vector<vector<int>> symDiffGraph(vector<vector<int>> adj1,vector<vector<int>> adj2) {
    vector<vector<int>> un = unionGraph(adj1,adj2);
    vector<vector<int>> in = interGraph(adj1,adj2);
    return diffGraph(un,in);
}

int main() {
    int n1,e1;
    cout << "Enter number of vertices and edges (Graph 1): ";
    cin>>n1>>e1;
    vector<vector<int>> g1 = graphCreation(n1,e1);
    print(g1);

    int n2,e2;
    cout << "Enter number of vertices and edges (Graph 2): ";
    cin>>n2>>e2;
    vector<vector<int>> g2 = graphCreation(n2,e2);
    print(g2);

    // union
    vector<vector<int>> ug = unionGraph(g1,g2);
    cout << "Union Graph :: " << endl;
    print(ug);

    // intersection
    vector<vector<int>> ig = interGraph(g1,g2);
    cout << "Intersection Graph :: " << endl;
    print(ig);

    // difference
    vector<vector<int>> dg = diffGraph(g1,g2);
    cout << "Difference Graph (g1-g2):: " << endl;
    print(dg);

    dg = diffGraph(g2,g1);
    cout << "Difference Graph (g2-g1):: " << endl;
    print(dg);

    // symmetric difference
    vector<vector<int>> sdg = symDiffGraph(g1,g2);
    cout << "Symmetric Difference Graph (Ring Sum) :: " << endl;
    print(sdg);

    return 0;
}

// input

// 5 6
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 4 5
// 5 5
// 1 2
// 4 3
// 5 3
// 2 5
// 3 1

