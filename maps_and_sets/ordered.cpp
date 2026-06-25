#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
    
    // ordered set
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);

    cout << "Ordered Set: ";
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // ordered map
    map<int, string> m;
    m[3] = "Three";
    m[1] = "One";
    m[4] = "Four";
    m[2] = "Two";

    cout << "Ordered Map: ";
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << it->first << ":" << it->second << " ";
    cout << endl;

    return 0;
}