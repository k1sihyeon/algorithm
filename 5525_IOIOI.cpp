#include <iostream>

using namespace std;

int N, M, result = 0;
string S;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;

    for (int i = 0; i < M - 2; i++) {
        if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I') {
            int cnt = 0;

            while (S[i + 1] == 'O' && S[i + 2] == 'I') {
                i += 2;
                cnt += 1;

                if (cnt == N) {
                    cnt -= 1;
                    result += 1;
                }
            }
        }
    }

    cout << result << '\n';


    return 0;
}