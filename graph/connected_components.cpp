#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices
void addEdge(int src, int dest, bool bidir = true){
    graph[src].push_back(dest);
    if(bidir){
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(visited.find(neighbor) == visited.end()){
            dfs(neighbor, visited);
        }
    }
}

int connected_components(){
    int count = 0;
    unordered_set<int> visited;
    // go to each vertex if we can start a DFS/BFS from it, then it is a new component
    for(int i = 0; i < v; i++){
        if(visited.find(i) == visited.end()){
            dfs(i, visited);
            count++;
        }
    }
    return count;
}

int main(){
    cout << "Enter number of vertices: ";
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        addEdge(s, d, false);
    }

    cout << "Number of connected components: " << connected_components() << endl;
}