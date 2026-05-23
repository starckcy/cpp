#include <iostream>
using namespace std;

int binary2decimal(string &binary){
    int n = binary.size();
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        int num = binary[i] - '0';
        ans += num * (1 << (n - 1 - i));
    }
    return ans;
}

int main() {
    string str = "001011";
    cout << binary2decimal(str);
    return 0;
}