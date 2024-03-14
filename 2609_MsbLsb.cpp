#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << GCD(a, b) << '\n';
    cout << LCM(a, b) << '\n';

    return 0;
}