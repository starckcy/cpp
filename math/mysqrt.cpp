#include <iostream>
#include <cmath>
using namespace std;

long long mySqrt(long long n) {
    long long left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid <= n / mid) {  // avoids overflow
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

// Using the Newton-Raphson method:
double mySqrt2(double n) {
    if (n < 0) return -1; // invalid

    double x = n;
    double prev = 0;

    while (fabs(x - prev) > 1e-9) {
        prev = x;
        x = (x + n / x) / 2;
    }

    return x;
}

int main() {
    long long n = 25;
    cout << mySqrt(n) << endl;  // 5
    double m = 2.0;
    cout << mySqrt2(m) << endl;  // 1.41421
    return 0;
}