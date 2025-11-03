#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    long long result = ceil(H / (double)(N + 1)) * ceil(W / (double)(M + 1));

    cout << result << "\n";

    return EXIT_SUCCESS;
}