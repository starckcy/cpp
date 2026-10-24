#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // number of vertices
void addEdge(int src, int dest, bool bidir = true){
    graph[src].push_back(dest);
    if(bidir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0; i < v; i++){
        cout << i << " --> ";
        for(auto x : graph[i]){
            cout << x << " ";
        }
        cout << endl;
    }
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

    display();

// bidirectional = true
//     Enter number of vertices: 5
// 5
// 0 1
// 0 2
// 1 2
// 1 3
// 3 4
// 0 --> 1 2 
// 1 --> 0 2 3 
// 2 --> 0 1 
// 3 --> 1 4 
// 4 --> 3 

// bidirectional = false
//    Enter number of vertices: 5
// 5
// 0 1
// 0 2
// 1 2
// 1 3
// 3 4
// 0 --> 1 2
// 1 --> 2 3
// 2 --> 
// 3 --> 4
// 4 --> 

}