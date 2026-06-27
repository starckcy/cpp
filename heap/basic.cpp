#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq; // max heap
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);

    cout << "Max heap elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    minHeap.push(10);

    cout << "Min heap elements: ";
    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    
    return 0;
}