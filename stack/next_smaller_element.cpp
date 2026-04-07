#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;

    // Traverse from right
    for (int i = n - 1; i >= 0; i--) {

        // Remove elements greater or equal
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Assign result
        if (st.empty())
            result[i] = -1;
        else
            result[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> res = nextSmallerElement(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}