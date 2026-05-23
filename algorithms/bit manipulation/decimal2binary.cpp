#include <iostream>
using namespace std;

string decimal2binary(int n){
    string ans = "";
    while(n > 0){
        int rem = n & 1;
        ans = to_string(rem) + ans;
        n = n >> 1;
    }
    return ans;
}

int main() {
    int n = 11;
    cout << decimal2binary(n);
    return 0;
}