#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        // Remove smaller or equal elements
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // Calculate span
        if (st.empty())
            span[i] = i + 1;
        else
            span[i] = i - st.top();

        // Push current index
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 81, 70, 60, 75, 85};

    for (int i = 0; i < price.size(); i++) {
        cout << price[i] << " ";
    }
    cout << endl;

    vector<int> result = stockSpan(price);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}