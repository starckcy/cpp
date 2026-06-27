#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap; // max heap

    for (int i = 0; i < arr.size(); i++) {
        maxHeap.push(arr[i]);

        // If the size of the heap exceeds k, remove the largest element
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // The root of the max heap is the kth smallest element
    return maxHeap.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int result = kthSmallest(arr, k);
    cout << "The " << k << "rd smallest element is: " << result << endl;

    return 0;
}