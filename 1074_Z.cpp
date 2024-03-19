#include <iostream>
#include <vector>

using namespace std;

int N, r, c, cnt = 0;

void Z(int x, int y, int size) {
    if ((x == r) && (y == c)) {
        cout << cnt << '\n';
        return;
    }

    if ((r < x + size) && (r >= x) && (c < y + size) && (c >= y)) {
        Z(x, y, size / 2);
        Z(x, y + size / 2, size / 2);
        Z(x + size / 2, y, size / 2);
        Z(x + size / 2, y + size / 2, size / 2);
    }
    else
        cnt += size * size;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    Z(0, 0, 1 << N); // 1 << N == 2^N (2의 N승)

    return 0;
}