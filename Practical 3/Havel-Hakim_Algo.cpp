#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
void printGraph(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        cout << i << " ::  ";
        for(int j=0;j<graph[i].size();j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSimple(vector<pair<int, int>> deg){
    int n = deg.size();

    graph.clear();
    graph.resize(n);
    
    // Check if sum of all degrees is even
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += deg[i].first;
    }
    if(sum%2 != 0) return false;
    
    for(int i=0;i<n;i++){
        // Check if degree is greater than or equal to n-i
        if(deg[i].first >= n-i) return false;
        // if degree is negative
        if(deg[i].first < 0) return false;
        // if degree is 0, then all the remaining degrees should be 0
        if(deg[i].first == 0) break;

        for(int j=i+1;j<=i+deg[i].first;j++){
            deg[j].first--;
            // if degree becomes negative after decrementing 
            if(deg[j].first < 0) return false;

            // add edge between i and j
            graph[deg[i].second].push_back(deg[j].second);
            graph[deg[j].second].push_back(deg[i].second);

        }
        
        // rearrange the sequence
        sort(deg.begin()+i+1,deg.end(), greater<pair<int,int>>());
    }
    
    return true;
}

int main() {

    int n;
    cin >> n;

    while(n--){
        int size; // size of degree sequence
        cin >> size;
        
        vector<pair<int,int>> nodesWithDegree(size);
        for(int i=0;i<size;i++){
            int tmp;
            cin >> tmp;
            nodesWithDegree[i] = {tmp, i};
        }
        
        sort(nodesWithDegree.begin(), nodesWithDegree.end(), greater<pair<int,int>>());
        
        if(isSimple(nodesWithDegree)) {
            cout << "Graph is simple" << endl;
            printGraph(graph);
        } else cout << "Graph is not simple" << endl;

        cout << endl;
    }
    return 0;
}