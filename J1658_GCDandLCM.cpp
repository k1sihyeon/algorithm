#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

int main(void) {
    int a, b;
    cin >> a >> b;

    int gcd = GCD(a, b);
    int lcm = a * b / gcd;

    cout << gcd << "\n";
    cout << lcm << "\n";

    return 0;
}