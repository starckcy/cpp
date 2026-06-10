#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;

    pair<string, int> p1("Alice", 30);

    pair<string, int> p2;
    p2.first = "David";
    p2.second = 40;

    m["Bob"] = 25; // Using operator[] to insert
    m["Charlie"] = 35;

    m.insert(p1);
    m.insert(p2);
    m.insert({"Eve", 28}); // Using initializer list
    m.insert(make_pair("Frank", 32)); // Using make_pair
    m.insert(pair<string, int>("Grace", 27)); // Using pair constructor

    for(auto p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    cout<<endl;

    m.size(); // Returns the number of key-value pairs in the map
    m.erase("Bob"); // Removes the key "Bob" from the map

    for(auto p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    cout<<endl;
    m.size(); // Returns the number of key-value pairs in the map after erasing "Bob"
    m.find("Charlie"); // Returns an iterator to the key "Charlie" if it exists, or m.end() if it doesn't
    m.count("Alice"); // Checks if "Alice" exists in the map (returns 1 if exists, 0 otherwise)

    cout<<endl;
    cout << m["Frank"] << endl; // Accessing a non-existent key will insert it with a default value (0 for int)
    cout << m["Bob"] << endl; // Accessing "Bob" will insert it back with a default value (0 for int)
    m.clear(); // Removes all key-value pairs from the map
    
    return 0;
}