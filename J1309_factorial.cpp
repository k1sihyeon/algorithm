#include <bits/stdc++.h>

using namespace std;

long long factorial(long long n) {

    if (n == 1) {
        cout << "1! = 1\n";
        return 1;
    }

    cout << n << "! = " << n << " * " << n - 1 << "!\n";

    return n * factorial(n-1);
}

int main(void) {

    int n;
    cin >> n;
    cout << factorial(n) << "\n";

    return 0;
}