#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v; // number of vertices
void addEdge(int src, int dest, bool bidir = true){
    graph[src].push_back(dest);
    if(bidir){
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int end, vector<int>& path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(auto neighbor : graph[curr]){
        if(visited.find(neighbor) == visited.end()){
            dfs(neighbor, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr); // unmark visited for other paths
    return;
}

void allPath(int src, int dest){
    visited.clear(); // clear visited set before starting DFS
    vector<int> v;
    dfs(src, dest, v);
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
        addEdge(s, d);
    }

    int x, y;
    cin >> x >> y;
    allPath(x, y);
    
    for(auto path : result){
        for(auto node : path){
            cout << node << " ";
        }
        cout << endl;
    }

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