#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c, d, N, res;
    cin >> a >> b >> c >> d >> N;
    res = 4 * N - (a + b + c + d);

    if (res <= 0)
        res = 0;

    cout << res << '\n';

    return 0;
}