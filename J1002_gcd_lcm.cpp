#include <bits/stdc++.h>

using namespace std;

vector<int> v(10, 0);
int N;

int GCD(int a, int b) {
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int gcd = v[0];
    int lcm = v[0];

    for (int i = 1; i < N; i++) {
        gcd = GCD(gcd, v[i]);
        lcm = lcm * v[i] / GCD(lcm, v[i]);
    }

    cout << gcd << " " << lcm << "\n";

    return 0;
}