#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; // number of vertices
void addEdge(int src, int dest, bool bidir = true){
    graph[src].push_back(dest);
    if(bidir){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int end){
    if(curr == end){
        return true;
    }
    visited.insert(curr); // mark visited
    for(auto neighbor : graph[curr]){
        if(visited.find(neighbor) == visited.end()){
            if(dfs(neighbor, end)){
                return true;
            }
        }
    }
    return false;
}

bool anyPath(int src, int dest){
    visited.clear(); // clear visited set before starting DFS
    return dfs(src, dest);
}

int main(){

    cout << "Enter number of vertices: ";
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    visited.clear();
    while(e--){
        int s, d;
        cin >> s >> d;
        addEdge(s, d, false);
    }

    int x, y;
    cin >> x >> y;
    cout << anyPath(x, y) << endl;

    // bidirectional = true
//     5
// 5
// 0 1
// 1 2
// 2 3
// 3 4
// 0 4
// 0 4

    return 0;
}