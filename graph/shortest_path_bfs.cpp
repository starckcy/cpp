#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
#include<climits>
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

void bfs(int src, vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbor : graph[curr]){
            if(visited.find(neighbor) == visited.end()){
                visited.insert(neighbor);
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
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

    int x;
    cin >> x;

    vector<int> dist;
    bfs(x, dist);
    
    for(int i=0; i<dist.size(); i++){
        cout << dist[i] << " ";
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