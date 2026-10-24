#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int, int>>> graph;
int v; // number of vertices
void addEdge(int src, int dest, int weight, bool bidir = true){
    graph[src].push_back({dest, weight});
    if(bidir){
        graph[dest].push_back({src, weight});
    }
}

void display(){
    for(int i = 0; i < v; i++){
        cout << i << " --> ";
        for(auto x : graph[i]){
            cout << "(" << x.first << ", " << x.second << ") ";
        }
        cout << endl;
    }
}

int main(){
    cout << "Enter number of vertices: ";
    cin >> v;
    graph.resize(v, list<pair<int, int>>());
    int e;
    cin >> e;
    while(e--){
        int s, d, w;
        cin >> s >> d >> w;
        addEdge(s, d, w, false);
    }

    display();

// Enter number of vertices: 5
// 5
// 0 1 10
// 0 2 5
// 1 2 2
// 1 3 1
// 3 4 3

// bidirectional = true
// 0 --> (1, 10) (2, 5)
// 1 --> (0, 10) (2, 2) (3, 1)
// 2 --> (0, 5) (1, 2)
// 3 --> (1, 1) (4, 3)
// 4 --> (3, 3)

// bidirectional = false
// 0 --> (1, 10) (2, 5)
// 1 --> (2, 2) (3, 1)
// 2 --> ()
// 3 --> (4, 3)
// 4 --> ()

}