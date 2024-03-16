#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int sum = i;
        int num = i;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        
        if (sum == N) {
            result = i;
            break;
        }
    }

    cout << result << "\n";

    return 0;
}