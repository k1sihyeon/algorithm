#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    for (int i = 5; i <= N; i *= 5)
        count += N / i;
    
    cout << count << '\n';

    return 0;
}