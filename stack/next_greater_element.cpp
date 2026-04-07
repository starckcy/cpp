#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);  // Initialize all as -1
    stack<int> st;              // Stack to store indices

    for (int i = 0; i < n; i++) {
        // If current element is greater than stack top element
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 1, 2, 7, 4, 6, 2, 3};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> nge = nextGreaterElement(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}