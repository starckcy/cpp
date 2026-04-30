#include <iostream>
using namespace std;

int pow(int x, int n){
    if(n == 0) return 1;
    if(n % 2 == 0){
        int half = pow(x, n/2);
        return half * half;
    }
    else{
        int half = pow(x, n/2);
        return half * half * x;
    }
}

// int normal_pow(int x, int n){
//     if(n == 0) return 1;
//     return x * normal_pow(x, n-1);
// }

int main() {
    cout << pow(2, 10) << endl;
    // cout << normal_pow(2, 10) << endl;
    return 0;
}