#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> previousGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Remove smaller elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If empty → no greater element
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 1, 2, 7, 4, 6, 2, 3};

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> res = previousGreater(arr);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}