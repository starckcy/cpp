#include <iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3); // Duplicate, will not be added
    s.erase(2); // Remove element 2

    int target = 3;
    if (s.find(target) != s.end()) {
        cout << target << " is present in the set." << endl;
    } else {
        cout << target << " is not present in the set." << endl;
    }

    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}