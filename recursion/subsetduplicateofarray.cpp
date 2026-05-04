#include <iostream>
#include <vector>
using namespace std;

void storesubset(vector<int> &ans, vector<int> &arr, int idx, vector<vector<int>> &result, bool flag) {
    
    if (idx == arr.size()) {
        result.push_back(ans);
        return;
    }

    // Last element case
    if (idx == arr.size() - 1) {
        if (flag) {
            ans.push_back(arr[idx]);
            storesubset(ans, arr, idx + 1, result, true);
            ans.pop_back();
        }
        storesubset(ans, arr, idx + 1, result, true);
        return;
    }

    // Duplicate check
    if (arr[idx] == arr[idx + 1]) {
        if (flag) {
            ans.push_back(arr[idx]);
            storesubset(ans, arr, idx + 1, result, true);
            ans.pop_back();
        }
        storesubset(ans, arr, idx + 1, result, false);
    }

    else {
        if (flag) {
            ans.push_back(arr[idx]);
            storesubset(ans, arr, idx + 1, result, true);
            ans.pop_back();
        }
        storesubset(ans, arr, idx + 1, result, true);
    }
}

int main() {
    vector<int> arr = {1, 1, 1, 2};  // must be sorted
    vector<vector<int>> result;
    vector<int> ans;

    storesubset(ans, arr, 0, result, true);

    for (auto subset : result) {  // auto is used to avoid type declaration
        for (int x : subset) cout << x << " ";
        cout << endl;
    }

    // for (int i = 0; i < result.size(); i++) {
    // vector<int> subset = result[i];
    
    // for (int j = 0; j < subset.size(); j++) {
    //     cout << subset[j] << " ";
    // }
    // cout << endl;
    // }

    return 0;
}