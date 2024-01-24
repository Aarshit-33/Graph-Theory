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
        for(int j=0;j<adj2[i].size();j++) {
            if(find(uni[i].begin(),uni[i].end(),adj2[i][j]) == uni[i].end())
                uni[i].push_back(adj2[i][j]);
        }
    }

    return uni;
}

// intersection of two graphs
vector<vector<int>> interSection(vector<vector<int>> adj1,vector<vector<int>> adj2) {

    int s1 = adj1.size();
    int s2 = adj2.size();
    int r = max(s1,s2);
    


    vector<vector<int>> inter(r);

    for(int i=1;i<r;i++) {
        for(int j=0;j<adj2[i].size();j++) {
            if(find(adj1[i].begin(),adj1[i].end(),adj2[i][j]) != adj1[i].end())
                inter[i].push_back(adj2[i][j]);
        }
    }

    return inter;
}

// difference of two graphs
vector<vector<int>> diffGraph(vector<vector<int>> adj1,vector<vector<int>> adj2) {
            
        int s1 = adj1.size();
        int s2 = adj2.size();
        int r = max(s1,s2);
        
        vector<vector<int>> diff(r);
    
        for(int i=1;i<r;i++) {
            for(int j=0;j<adj2[i].size();j++) {
                if(find(adj1[i].begin(),adj1[i].end(),adj2[i][j]) == adj1[i].end())
                    diff[i].push_back(adj2[i][j]);
            }
        }
    
        return diff;
}

// symmetric difference of two graphs
vector<vector<int>> symDiff(vector<vector<int>> adj1,vector<vector<int>> adj2) {

    int s1 = adj1.size();
    int s2 = adj2.size();
    int r = max(s1,s2);
    
    vector<vector<int>> sym(r);

    for(int i=1;i<r;i++) {
        for(int j=0;j<adj2[i].size();j++) {
            if(find(adj1[i].begin(),adj1[i].end(),adj2[i][j]) == adj1[i].end())
                sym[i].push_back(adj2[i][j]);
        }
    }

    for(int i=1;i<r;i++) {
        for(int j=0;j<adj1[i].size();j++) {
            if(find(adj2[i].begin(),adj2[i].end(),adj1[i][j]) == adj2[i].end())
                sym[i].push_back(adj1[i][j]);
        }
    }

    return sym;
}

int main() {

    int n,e;
    cin>>n>>e;
    vector<vector<int>> g1 = createGraph(n,e);
    print(g1);

    int n1,e1;
    cin>>n1>>e1;
    vector<vector<int>> g2 = createGraph(n1,e1);
    print(g2);

    vector<vector<int>> uni = unionGraph(g1,g2);
    cout << "Union graph: " << endl;
    print(uni);

    vector<vector<int>> inter = interSection(g1,g2);
    cout << "Intersection graph: " << endl;
    print(inter);

    vector<vector<int>> diff = diffGraph(g1,g2);
    cout << "Difference graph(g2-g1): " << endl;
    print(diff);
    
    vector<vector<int>> diff2 = diffGraph(g2,g1);
    cout << "Difference graph(g1-g2): " << endl;
    print(diff2);

    vector<vector<int>> sym = symDiff(g1,g2);
    cout << "Symmetric difference (Ring Sum) graph: " << endl;
    print(sym);


    return 0;
}